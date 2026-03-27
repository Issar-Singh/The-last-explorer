#include "cave.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <string>

static std::string trimLower(std::string s) {
  while (!s.empty() && std::isspace(static_cast<unsigned char>(s.front())))
    s.erase(s.begin());
  while (!s.empty() && std::isspace(static_cast<unsigned char>(s.back())))
    s.pop_back();
  for (char& c : s)
    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
  return s;
}

static std::string extractWLSM(std::string s) {
  s = trimLower(s);
  std::string out;
  out.reserve(s.size());

  std::copy_if(s.begin(), s.end(), std::back_inserter(out), [](char ch) {
    return ch == 'w' || ch == 'l' || ch == 's' || ch == 'm';
  });

  return out;
}

Cave::Cave()
    : Environment(
          "You stand before the entrance of a dark, echoing cave. "
          "The air is cold and still.") {}

void Cave::enter(IPlayer* player) {
  std::cout << "\n[Cave Entrance]\n";
  std::cout << "Cavekeeper: \"Answer this to pass. What has to be broken "
               "before you can use it?\"\n";
  std::cout << "> Answer (type 'h' for help): ";

  std::string ans;
  while (true) {
    std::getline(std::cin >> std::ws, ans);
    std::string n = trimLower(ans);
    if (n == "h" || n == "help") {
      std::cout << "[Help] The winning answer is 'egg'.\n";
      std::cout << "> Answer: ";
      continue;
    }
    ans = n;
    break;
  }

  if (ans == "egg") {
    std::cout << "Cavekeeper: \"Impressive. You may enter.\"\n";
    player->addPoints(10);
    if (!player->hasItem("sword")) player->addItem("sword");
    std::cout << "Points +10 | Total: " << player->getPoints()
              << " | Item: sword\n\n";
  } else {
    std::cout << "Cavekeeper: \"You may enter... but you walk without my "
                 "blessing.\"\n\n";
  }

  std::cout << "[Inner Cave — Final Battle]\n";
  std::cout << "You light the lamp. A monster looms over a locked chest.\n";
  std::cout << "Battle begins...\n";

  if (!player->hasItem("sword")) {
    std::cout << "You have no sword. The monster defeats you. Game Over.\n";
    player->changeHealth(-player->getHealth());
    return;
  }

  std::cout << "You defeat the monster with the sword.\n\n";

  std::cout << "[Final Mechanism — Symbol Matching]\n";
  std::cout << "Prompt: \"Life begins with water, grows with leaf, shines with "
               "sun, and rests with moon.\"\n";
  std::cout << "Enter sequence using letters (w for water, l for leaf, s for "
               "sun, m for moon):\n";
  std::cout << "> Input (type 'h' for help): ";

  std::string seq;
  while (true) {
    std::getline(std::cin >> std::ws, seq);
    std::string n = trimLower(seq);
    if (n == "h" || n == "help") {
      std::cout << "[Help] The winning sequence is 'w l s m'.\n";
      std::cout << "> Input: ";
      continue;
    }
    break;
  }
  std::string letters = extractWLSM(seq);
  if (letters != "wlsm") {
    std::cout << "The symbols do not align. Game Over.\n";
    player->changeHealth(-player->getHealth());
    return;
  }

  std::cout << "The symbols align and the lock falls away.\n\n";
  std::cout << "The chest opens revealing treasure beyond measure.\n";
  std::cout << "End: YOU WIN!!!" << std::endl;
}

void Cave::triggerEvent(IPlayer* player) { (void)player; }
