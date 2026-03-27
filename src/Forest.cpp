#include "Forest.hpp"

#include <cctype>
#include <iostream>
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

Forest::Forest()
    : Environment("You leave the river behind and step into a quiet forest.") {}

void Forest::enter(IPlayer* player) {
  std::cout << "\n[Gardener\u2019s Field]\n";
  std::cout << "A gardener stands beside cactus, rose, and pitcher plant.\n";
  std::cout << "Gardener: \"Help me water the flower. Which is it?\"\n";
  std::cout << "Options: (a) Cactus  (b) Rose  (c) Pitcher plant\n";
  std::cout << "> Answer (type 'h' for help): ";

  std::string ans;
  while (true) {
    std::getline(std::cin >> std::ws, ans);
    std::string n = trimLower(ans);
    if (n == "h" || n == "help") {
      std::cout << "[Help] The winning answer is 'b' (rose).\n";
      std::cout << "> Answer: ";
      continue;
    }
    ans = n;
    break;
  }

  bool gardenerSolved = (ans == "b" || ans == "rose");

  if (gardenerSolved) {
    std::cout << "Gardener: \"Correct. May fortune favor you.\"\n";
    player->addPoints(10);
    std::cout << "Points +10 | Total: " << player->getPoints() << "\n\n";
  } else {
    std::cout << "Gardener: \"That\u2019s not quite right.\"\n\n";
  }

  std::cout << "[Forest]\n";
  std::cout << "Rustling in the bushes. A bear blocks the path.\n";
  std::cout << "Choose an action:\n";
  std::cout << "1) Hide in bushes\n";
  std::cout << "2) Fight with Axe\n";
  std::cout << "> Choice (type 'h' for help): ";

  int choice = -1;
  while (true) {
    std::string line;
    std::getline(std::cin >> std::ws, line);
    std::string n = trimLower(line);
    if (n == "h" || n == "help") {
      if (player->hasItem("axe")) {
        std::cout << "[Help] Winning choice is '2' (fight with Axe).\n";
      } else {
        std::cout << "[Help] You need an Axe to win here. Winning choice is "
                     "'2' once you have it.\n";
      }
      std::cout << "> Choice: ";
      continue;
    }
    if (!n.empty() && std::isdigit(static_cast<unsigned char>(n[0]))) {
      choice = n[0] - '0';
      break;
    }
    // If invalid, echo prompt again
    std::cout << "> Choice: ";
  }

  if (choice == 1) {
    std::cout << "\nThe bear finds you and attacks. Game Over.\n";
    player->changeHealth(-player->getHealth());
    return;
  }

  if (!player->hasItem("axe")) {
    std::cout << "\nYou have no axe. The bear overpowers you. Game Over.\n";
    player->changeHealth(-player->getHealth());
    return;
  }

  std::cout << "You fight bravely and slay the bear.\n";

  const int targetHealth = 40;
  player->changeHealth(targetHealth - player->getHealth());

  std::cout << "Status: Health 40 (you lose 50 in battle)\n";
  std::cout << "You find a Lamp in the bear\u2019s den.\n";
  if (!player->hasItem("lamp")) player->addItem("lamp");
  std::cout << "Item: lamp\n\n";

  std::cout << "[Mystic Maze]\n";
  std::cout << "You navigate twisting passages. A pedestal glows with guiding "
               "light.\n";
  std::cout << "Inscription: \"Light will guide those who keep faith.\"\n";
  std::cout << "You secure your Lamp and follow the beam.\n";
  player->addPoints(10);
  std::cout << "Points +10 | Total: " << player->getPoints() << "\n";
}

void Forest::triggerEvent(IPlayer* player) { (void)player; }
