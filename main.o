//Simaal B
//CPSC 25
//Adventure Game

#include <fstream>
#include <sstream>
#include "LinkedList.h"
#include "Player.h"
#include "Weapon.h"
#include "Enemy.h"

void introduction() {
    cout << "Welcome to the Castle Adventure!\n";
    cout << "You will navigate through various rooms in the castle.\n";
    cout << "Choose your actions wisely.\n\n";
}

void printLine() {
    cout << "\n----------------------------------------\n";
}

void pauseGame() {
    cout << "\nPress enter to continue...";
    cin.ignore();
    cin.get();
}

// lets player take the room item and make it their weapon
void takeWeapon(Player& player, Room& room) {
    printLine();

    if (room.getItem() == "None") {
        cout << "There is no weapon left in this room.\n";
        pauseGame();
        return;
    }

    Weapon weapon(room.getItem(), 10);
    player.addItem(room.getItem());
    player.setWeapon(weapon);
    room.setItem("None");

    cout << "You picked up and equipped: " << weapon.getName() << endl;
    pauseGame();
}

// lets player fight the enemy
void fightEnemy(Player& player, Enemy& enemy) {
    printLine();

    if (enemy.isDefeated()) {
        cout << enemy.getName() << " is already defeated.\n";
        pauseGame();
        return;
    }

    cout << "You attack " << enemy.getName() << " with "
         << player.getWeapon().getName() << ".\n";

    enemy.takeDamage(player.getWeapon().getDamage());

    if (enemy.isDefeated()) {
        cout << "You defeated " << enemy.getName() << "!\n";
    } else {
        cout << enemy.getName() << " has " << enemy.getHealth() << " health left.\n";
    }

    pauseGame();
}

// shows player information
void showPlayer(Player& player) {
    printLine();
    cout << "Player: " << player.getName() << endl;
    cout << "Health: " << player.getHealth() << endl;
    cout << "Current weapon: " << player.getWeapon().getName() << endl;
    player.showInventory();
    pauseGame();
}

int main() {
    LinkedList castleRooms;
    ifstream file("rooms.csv");
    string line;

    // read rooms from csv file
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string name, description, actionsStr, item;
            vector<string> actions;

            getline(ss, name, ',');
            getline(ss, description, ',');
            getline(ss, actionsStr, ',');
            getline(ss, item);

            stringstream actionStream(actionsStr);
            string action;
            while (getline(actionStream, action, ';')) {
                actions.push_back(action);
            }

            Room newRoom(name, description, actions, item);
            castleRooms.addRoom(newRoom);
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
        return 1;
    }

    introduction();

    Player player("Hero", 100);
    auto current = castleRooms.getHead();

    while (current != nullptr) {
        Enemy enemy("Guard", 20);
        bool leaveRoom = false;

        while (!leaveRoom) {
            printLine();
            cout << current->room.toString() << endl;
            cout << "Enemy: " << enemy.getName() << " | Health: " << enemy.getHealth() << endl;

            int actionNum = 1;
            for (const auto& action : current->room.getActions()) {
                cout << actionNum++ << ". " << action << endl;
            }

            cout << actionNum++ << ". Take weapon" << endl;
            cout << actionNum++ << ". Fight enemy" << endl;
            cout << actionNum++ << ". Show player info" << endl;

            int choice;
            cout << "Choose an action (1-" << actionNum - 1 << "): ";
            cin >> choice;

            int originalActionCount = current->room.getActions().size();

            if (choice < 1 || choice > actionNum - 1) {
                cout << "Invalid choice. Try again.\n";
                pauseGame();
            } else if (choice <= originalActionCount) {
                printLine();
                cout << "You chose: " << current->room.getActions()[choice - 1] << endl;

                // assumes leave room is the last original action
                if (choice == originalActionCount) {
                    cout << "You leave the room.\n";
                    pauseGame();
                    leaveRoom = true;
                    current = current->next;
                } else {
                    pauseGame();
                }
            } else if (choice == originalActionCount + 1) {
                takeWeapon(player, current->room);
            } else if (choice == originalActionCount + 2) {
                fightEnemy(player, enemy);
            } else if (choice == originalActionCount + 3) {
                showPlayer(player);
            }
        }
    }

    printLine();
    cout << "You have reached the end of your adventure!\n";
    return 0;
}