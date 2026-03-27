
## The Last Explorer

## Course Information

Course: CPSC 2720 – Object-Oriented Programming
Institution: University of Lethbridge
Project: Text-Based Adventure Game (Major Project)

## Team Members:
-Gurnoor Kaur
-Issar Singh
-Muskan

## Overview

The Last Explorer is a text-based adventure game that follows a lone adventurer on a quest through mysterious and dangerous environments — a raging river, a perilous forest, and a dark cave. The player faces different challenges, including puzzles, combat, and decision-making moments that shape the outcome of the story. Each environment presents unique choices: crossing a deadly river, battling a bear in the forest, and fighting a soldier in the final cave. Success in these trials depends on logical thinking, strategic item use, and solving riddles along the way.

The game emphasizes exploration, survival, and reasoning. Players must manage their health, collect tools like an axe and lamp, and solve puzzles to progress. Every decision affects the storyline — victory brings rewards like health restoration or upgraded weapons, while failure results in game over. By blending storytelling with interactive gameplay, The Last Explorer delivers an engaging experience built on choice, logic, and courage.

## Game Design Elements

Core Concepts: Exploration, puzzle-solving, and combat.

Game Mechanics: Player decision-making affects progression and outcome.

Reward System: Players earn health and items by solving puzzles and winning battles.

Failure Consequence: Losing a battle results in Game Over.

## Team Contributions (Design Phase)

Issar Singh: Designed the UML diagram and Sequence 1 diagram, outlining system flow and class interactions. Also wrote DRY and SOLID principle descriptions to ensure clean and reusable code structure.

Muskan: Created Sequence 2 and Sequence 3 diagrams, detailing player actions and interactions in later game stages. Authored class descriptions, explaining roles, attributes, and relationships.

Gurnoor Kaur: Assisted in designing the UML and sequence diagrams, contributed ideas for puzzles and gameplay flow, and helped maintain consistency across the documentation.

## Team Contributions (Basic Design Implemention)

Teammate 1: Issar Singh
Responsible for game flow, player logic, and inventory integration. Completed the GameManager, Player, and Inventory classes, including handling game lifecycle functions, transitions between environments, and input/output flow. Integrated all other systems into the playable game loop.

Teammate 2: Gurnoor Kaur
Responsible for environments, NPCs, and interaction logic. Completed the River, Forest, and Cave classes, environment descriptions, and movement logic. Implemented NPC interaction behavior and ensured environments connect smoothly with the main game flow.

Teammate 3: Muskan Chauhan
Responsible for puzzles, items, and reward mechanics. Implemented Puzzle and PuzzleManager functionality, puzzle validation, the RewardSystem, and collectible items such as the Axe. Ensured puzzles are tied correctly to NPC interactions and update the Player’s inventory.

## Team Contribution (Final Implementation)

Teammate 1: Issar Singh – Game Flow & System Integration
Finalized the main game loop logic and ensured smooth transitions between all stages (River → Garden → Forest → Maze → Cave → Final Puzzle).
Connected the Player class with puzzle outcomes, combat results, and environment events.
Handled health updates, point tracking, and dialogue flow to match the final game output.
Integrated all systems into a complete and playable build.


Teammate 2: Gurnoor Kaur – Environments & NPC Implementation
Finalized and tested all environments:
River, Gardener’s Field, Forest, Maze, Cave
Completed NPC dialogues and interactions (Maid, Boatman, Gardener, Cavekeeper).
Ensured each environment followed the final storyline logic and connected correctly with the GameManager.
Verified that player choices lead to the correct outcomes (progression or Game Over).


eammate 3: Muskan Chauhan – Final Puzzles, Items & Rewards System
Implemented and connected all final puzzles:
Cleaning Solution (w + v)
Flower Identification (Rose)
Cave Riddle (Egg)
Final Symbol Puzzle (w l s m)
Finalized the RewardSystem, ensuring correct distribution of:
Money, Axe, Lamp, Sword, 
Points (+10 per completed stage)
Ensured that specific items were required for progression, such as:
Axe needed to defeat the bear,
Sword required to defeat the monster in the cave
Integrated all collectibles through the ICollectible interface and connected them to the Player’s inventory.