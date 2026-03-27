# 🗺️ The Last Explorer

**The Last Explorer** is a **group C++ text-based adventure game** built using object-oriented programming principles. The player progresses through dangerous environments, solves puzzles, collects items, survives combat encounters, and makes choices that determine whether the story ends in victory or failure.

This project also reflects our practical use of **AI-assisted development tools** to improve coding speed, organization, and iteration while keeping human control over design, review, and testing.

---

## 📌 Course Information

- **Course:** CPSC 2720 – Object-Oriented Programming  
- **Institution:** University of Lethbridge  
- **Project Type:** Major Group Project  

---

## 👥 Team Members

- **Gurnoor Kaur**
- **Issar Singh**
- **Muskan Chauhan**

---

## 🎯 Project Overview

The Last Explorer follows a lone adventurer on a quest for hidden treasure. The journey begins at a raging river and continues through a forest, a maze-like path, and a dark cave. Along the way, the player must solve puzzles, choose safe actions, defeat enemies, and manage collected items to survive.

The game combines:
- exploration
- puzzle-solving
- inventory-based progression
- combat
- branching outcomes based on player choices

Success depends on using the correct items at the right time and answering puzzles correctly. Wrong decisions can lead directly to **Game Over**.

---

## ✨ Key Features

- **Text-based adventure gameplay**
- **Multiple environments** with different events
- **Puzzle-driven progression**
- **Inventory system** for item collection and use
- **Health and points tracking**
- **Combat scenarios**
- **Choice-based outcomes**
- **Object-oriented C++ design**
- **Unit testing and code-quality tooling**

---

## 🧱 Gameplay Flow

The player moves through the game in the following progression:

1. **River Bank**
   - Solve the maid’s cleaning-solution puzzle
   - Earn money
   - Choose whether to swim or pay the boatman
   - Crossing safely grants an **axe**

2. **Gardener’s Field**
   - Solve the flower-identification puzzle
   - Earn points

3. **Forest**
   - Encounter a bear
   - Survive only if the player has the **axe**
   - Earn a **lamp**

4. **Mystic Maze**
   - Follow the lamp’s light
   - Earn more points

5. **Cave Entrance**
   - Solve the cavekeeper’s riddle
   - Earn a **sword**

6. **Final Battle & Symbol Puzzle**
   - Defeat the monster using the sword
   - Solve the final symbol sequence puzzle
   - Unlock the treasure and win

---

## 🧩 Puzzle and Reward Design

The game includes multiple puzzles tied directly to progression.

### Puzzle examples
- Cleaning solution puzzle
- Flower identification puzzle
- Cave riddle
- Final symbol-matching puzzle

### Reward examples
- **Money**
- **Axe**
- **Lamp**
- **Sword**
- **Points**

These rewards are not cosmetic. They are required for progression and survival.

---

## 🛠️ Tech Stack

- **Language:** C++
- **Standard:** C++14
- **Compiler:** g++
- **Build Tool:** Makefile
- **Testing:** Google Test
- **Static Analysis:** cppcheck
- **Style Checking:** cpplint
- **Memory Checking:** valgrind
- **CI Configuration:** `.gitlab-ci.yml`

---

## 📂 Project Structure

```text
text-adventure-game/
│
├── include/
│   ├── Axe.hpp
│   ├── Cave.hpp
│   ├── Environment.hpp
│   ├── Forest.hpp
│   ├── GameManager.hpp
│   ├── ICollectible.hpp
│   ├── IInteractable.hpp
│   ├── IPlayer.hpp
│   ├── Inventory.hpp
│   ├── Item.hpp
│   ├── NPC.hpp
│   ├── Player.hpp
│   ├── Puzzle.hpp
│   ├── PuzzleManager.hpp
│   ├── RewardSystem.hpp
│   ├── River.hpp
│   └── character.hpp
│
├── src/
│   ├── Forest.cpp
│   ├── GameManager.cpp
│   ├── Inventory.cpp
│   ├── Item.cpp
│   ├── NPC.cpp
│   ├── Player.cpp
│   ├── Puzzle.cpp
│   ├── PuzzleManager.cpp
│   ├── RewardSystem.cpp
│   ├── River.cpp
│   └── cave.cpp
│
├── test/
│   ├── main.cpp
│   ├── test_Cave.cpp
│   ├── test_Forest.cpp
│   ├── test_ICollectible.cpp
│   ├── test_Item_Axe.cpp
│   ├── test_NPC.cpp
│   ├── test_Puzzle.cpp
│   ├── test_PuzzleManager.cpp
│   ├── test_RewardsSystem.cpp
│   ├── test_gamemanager.cpp
│   ├── test_inventory.cpp
│   └── test_player.cpp
│
├── docs/
├── Makefile
├── CPPLINT.cfg
├── .gitlab-ci.yml
└── README.md
```
## ▶️ Build and Run

### Build

```bash
make
```
Additional checks
```
make static
make style
make memcheck
```
What these do
- make static → runs static analysis using cppcheck
- make style → checks style using cpplint
- make memcheck → checks for memory issues using valgrind
