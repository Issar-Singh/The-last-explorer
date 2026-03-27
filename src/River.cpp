#include "River.hpp"

#include <iostream>
#include <string>

#include "Player.hpp"         // concrete player type
#include "PuzzleManager.hpp"  // to run maid_cleaning puzzle
#include "RewardSystem.hpp"   // to grant money + points via puzzle

River::River()
    : Environment(
          "You arrive at a raging river with no bridge. "
          "The current is fierce, and a maid is washing clothes on the bank.") {
}

/**
 * River::enter
 * ------------
 * Full river story:
 *  - Introduces maid and her request
 *  - Runs the maid_cleaning puzzle via PuzzleManager
 *  - If solved, lets the player choose: swim (die) or pay boatman (cross)
 *  - Forest and Cave travel happen outside, in GameManager
 */
void River::enter(IPlayer* player) {
  // --- Intro script (printed once, before River Bank) ---
  std::cout << "Game Start\n";
  std::cout << "You discovered an ancient map to a hidden treasure.\n";
  std::cout << "Your journey begins at a raging river with no bridge.\n";
  std::cout << "------------------------------------------------------\n";

  std::cout << "\n--- River Bank ---\n" << description << "\n\n";

  std::cout << "Maid: \"I could lend you some money to pay the boatman, "
               "but my clothes are too dirty.\"\n";
  std::cout
      << "Maid: \"Help me make a cleaning solution, and I’ll reward you.\"\n";

  // We need the concrete Player type for PuzzleManager (it uses Player*).
  Player* concretePlayer = dynamic_cast<Player*>(player);
  if (concretePlayer == nullptr) {
    std::cout
        << "[River] Internal error: expected a concrete Player instance.\n";
    return;
  }

  // Create a local RewardSystem + PuzzleManager for this environment.
  // All puzzle text/answer/reward live inside PuzzleManager/Puzzle.
  RewardSystem rewardSystem;
  PuzzleManager puzzleManager(&rewardSystem);
  puzzleManager.initPuzzles();

  std::cout << "\n(The maid asks you to solve a puzzle to make the cleaning "
               "solution.)\n";
  std::cout << "(Type 'h' for guidance at any prompt.)\n";

  bool solved = puzzleManager.runPuzzle("maid_cleaning", concretePlayer);

  if (!solved) {
    std::cout << "Maid: \"That's not right. I cannot help you.\"\n";
    std::cout << "Without the maid’s help, you have no safe way to cross.\n";
    player->changeHealth(-player->getHealth());
    return;
  }

  // On success, the RewardSystem (via PuzzleManager) already gave:
  //  - points (+10)
  //  - item  "money"
  std::cout << "Maid: \"Perfect. Here is the money. Pay the boatman "
               "and be careful.\"\n";

  // Now handle the crossing choice.
  std::cout << "\nYou approach the riverbank.\n";
  std::cout << "Choices:\n";
  std::cout << "  1) Swim across the river\n";
  std::cout << "  2) Pay the boatman and cross safely\n";
  std::cout << "Enter choice (type 'h' for help):\n";
  std::string choice;
  auto normalize = [](const std::string& s) {
    std::string t = s;
    auto l = t.find_first_not_of(" \t\r\n");
    auto r = t.find_last_not_of(" \t\r\n");
    if (l == std::string::npos) return std::string("");
    t = t.substr(l, r - l + 1);
    for (auto& c : t) c = std::tolower(c);
    return t;
  };

  while (true) {
    std::cout << "> Choice: ";
    std::getline(std::cin, choice);
    std::string n = normalize(choice);
    if (n == "h" || n == "help") {
      std::cout << "[Help] Press '1' to swim (you will die)." << std::endl;
      std::cout << "[Help] Press '2' to pay the boatman and cross safely."
                << std::endl;
      std::cout << "[Help] Puzzle answer is: '2'." << std::endl;
      std::cout << "Enter choice: \n";
      continue;
    }
    break;
  }

  if (choice == "1") {
    std::cout << "\nYou dive into the river...\n";
    std::cout << "The current is far stronger than you expected.\n";
    std::cout
        << "You struggle to stay afloat, but the water drags you under.\n";
    std::cout << "You drown in the raging river.\n";

    // Signal death: set health to 0.
    int currentHealth = concretePlayer->getHealth();
    concretePlayer->changeHealth(-currentHealth);
    return;
  } else if (choice == "2") {
    std::cout << "\n[Boatman]\n";
    std::cout
        << "Boatman: \"Payment received. Hold tight; the current is wild.\"\n";
    std::cout << "The boat rocks violently as it cuts through the waves.\n";
    std::cout << "After a tense crossing, you safely reach the other side.\n";

    // Crossing costs health and all previous items.
    concretePlayer->changeHealth(-10);
    concretePlayer->clearInventory();
    concretePlayer->addItem("axe");

    std::cout << "Boatman: \"You trusted me and the river. "
                 "Take this Axe; it may save your life.\"\n";
    std::cout << "Status: Health " << concretePlayer->getHealth()
              << " (lost 10 from exhaustion).\n";
    std::cout << "Inventory updated: Axe received.\n";
  } else {
    std::cout << "\nYou hesitate on the shore as storm clouds gather.\n";
    std::cout << "The river swells, and the boatman leaves.\n";
    std::cout << "You lose your chance to cross the river.\n";
    // Player is alive but stuck; GameManager can treat as game over.
    return;
  }
}

/**
 * triggerEvent
 * ------------
 * For this design, all river logic is handled in enter().
 * We keep this function to satisfy the Environment interface.
 */
void River::triggerEvent(IPlayer* player) {
  (void)player;  // unused for now
}
