#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

#include "GBA\assets\GummyBear.h"
#include "GBA\assets\Character.h"
#include "GBA\game\DiceRoll.h"
#include "GBA\menu\Menu.h"
#include "GBA\game\Battle.h"

using namespace std;


// Function to handle game loop
void startGame() {
    // Main menu
    string playerName = mainMenu();

    // Game setup
    GummyBear player(playerName, 100, 10, 5, 8);
    GummyBear opponent("Gumy The God of Gummy Bear", 100, 10, 5, 8);

    // Main game loop
    bool gameOver = false;
    while (!gameOver) {
        // Display main menu
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                // Enter battle phase
                cout << "Entering Battle Phase..." << endl;
                cout << "Setting up your Gummy Bear..." << endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
                cout << "Setting up opponent's Gummy Bear..." << endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
                
                // Dice roll showdown to determine who goes first
                bool goFirst;
                
                goFirst = diceRollShowdown(playerName, opponent.getName());

                cout << "--------------------------------------" << endl;
                // Display stats
                player.displayStats();
                cout << endl;
                cout << "                  vs                  " << endl;
                cout << endl;
                opponent.displayStats();
                cout << "--------------------------------------" << endl;
                

                // Battle phase
                battlePhase(player, opponent, goFirst);
                break;

            case 2:
                // Quit the game
                cout << "Exiting game..." << endl;
                gameOver = true;
                break;

            default:
                cout << "Invalid choice! Please choose again." << endl;
                break;
        }
        gameOver = true;
    }
}


int main() {
    startGame();

    return 0;
}