Simaal Belgaumi
Jesus Novoa Vasquez 
Hugo Cisneros

This project is a simple castle adventure game written in C++.

The original code used the classes Room, Node, and LinkedList. The program reads room data from a CSV file, creates Room objects, stores them in a linked list, and allows the player to move through each room using console input.

Our group worked together equally on all parts of the project including design, planning, and coding.

We added three new objects to the program: Player, Weapon, and Enemy.

The Player class stores the player’s name, health, inventory, and currently equipped weapon. It allows the player to collect items, equip a weapon, and view their inventory and status.

The Weapon class stores a weapon name and damage value. When the player picks up an item from a room, that item is turned into a simple weapon and equipped by the player.

The Enemy class represents a basic enemy in each room. It stores the enemy name and health and allows the player to fight the enemy by reducing its health.

To integrate these objects into the code, we added new header and source files for Player, Weapon, and Enemy. We updated main.cpp to create a Player object and create an Enemy in each room. We added new functions to handle taking a weapon, fighting an enemy, and displaying player information. We also updated the menu system to include these new actions.

Additional functions added to main include takeWeapon, fightEnemy, and showPlayer.

Additional game features include the ability to pick up items as weapons, fight enemies in each room, display player inventory, display player status, and improved readability of the game through separators and pauses.

The final program allows the player to move through rooms, collect weapons, fight enemies, and track their inventory in a simple text-based interface while keeping the original structure of the program mostly unchanged.
