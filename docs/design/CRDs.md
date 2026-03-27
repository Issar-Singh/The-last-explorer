Class Descriptions for ### The Last Explorer ###

#### GameManger ####
Description : The GameManager class controls the overall flow of the game. It coordinates player actions, manages transitions between environments, and directs interactions with puzzles and combat. It acts as the central controller connecting the main systems.

Attributes :->currentEnvironment: Environment — the environment the player is currently in.
            ->player: Player — the main player object being controlled.
            ->puzzleManager: PuzzleManager — handles puzzle loading and validation.
            ->combatSystem: CombatSystem — handles combat logic between player and NPCs.
            ->rewardSystem: RewardSystem — manages rewards, upgrades, and points for the player.

Methods:->startGame() — initializes the game and sets the first environment.
        ->nextStage() — moves the player to the next environment.
        ->endGame() — ends the game when objectives are complete or player dies.


#### Player ####
Description - Represents the user-controlled character in the game. The player explores environments, solves puzzles, collects items, and engages in combat.

Attributes :->health: int — the player’s remaining health points.
            ->points: int — score accumulated by solving puzzles or defeating NPCs.
            ->inventory: Inventory — stores all collected items and weapons.

Methods :->pickItem(Item) — adds an item to the inventory.
        ->solvePuzzle(Puzzle) — interacts with puzzles to gain rewards.
        ->attack(NPC) — performs attacks through the CombatSystem.
        ->upgradeSword() — enhances weapon strength using the RewardSystem.


#### Inventory ####
Description - Maintains a list of all items and weapons owned by the player. Provides methods to add, remove, and access items during gameplay.

Attributes :->items: List<Item> — stores all collectible items.

Methods :->addItem(Item) — adds a new item to the inventory.
        -> removeItem(Item) — removes an existing item.
        ->getWeapon(): Weapon — retrieves the player’s current weapon.


#### Item ####
Description : Defines the base properties for all collectible items in the game, such as weapons, tools, and keys.

Attributes :->name: string — the name or identifier of the item.

Methods :->use() — defines a general use behavior for all items.

#### Environment ####
Description : Represents a general environment within the game world. Each specific environment provides unique puzzles and NPCs.

Attributes :->description: string — textual description of the environment.

Methods :->enter() — loads the environment and sets its conditions.
        ->triggerEvent() — activates events or interactions specific to that environment.
        ->loadPuzzle() — loads puzzles specific to the environment.


#### Puzzle ####
Description : Defines the general structure for all puzzles, including their question, answer, and validation process.

Attributes :->question: string — puzzle question or challenge text.
            ->answer: string — correct answer for the puzzle.

Methods :->ask() — displays the puzzle question.
        ->check(answer): bool — verifies if the player’s answer is correct.


#### PuzzleManager ####
Description : Manages all puzzles within the game. It loads puzzles, checks player answers, and coordinates rewards for successful solutions.

Attributes :->puzzles: List<Puzzle> — a collection of puzzles used in the game.

Methods :->loadPuzzle() — retrieves a new puzzle for the player.
        ->validateAnswer(answer): bool — checks if a given answer is correct.
        ->rewardPlayer(Player) — rewards the player for correct answers.


#### RewardsSystem ####
Description : Handles the player’s rewards for achievements like solving puzzles or winning battles. It can increase player points or upgrade weapons.

Methods :->addPoints(Player, int) — increases player’s score.
        ->upgradeSword(Player) — upgrades the player’s sword level.


#### NPC ####
Description : Represents non-player characters that can interact or fight with the player. Each NPC has a strength value and may guard puzzles or items.

Attributes :->strength: int — defines combat difficulty.

Methods :->interact() — allows NPCs to communicate or trigger events.
        ->attack(Player) — defines the NPC’s attack behavior.


#### Character ####
Description : Base class for all characters, including both player and NPC. It defines shared attributes like name and health, and basic interaction behavior.

Attributes :->name: string — character’s name.
            ->health: int — current health level.

Methods :->interact() — handles communication or battle initiation. 
