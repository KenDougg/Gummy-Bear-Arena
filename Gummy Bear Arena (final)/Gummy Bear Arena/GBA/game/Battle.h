#ifndef Battle_h
#define Battle_h

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include "../assets/GummyBear.h"

using namespace std;

void battlePhase(GummyBear& player, GummyBear& opponent, bool goFirst) {
    cout << "Entering Battle Phase..." << endl;
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));

    // Initialize player and opponent stats
    int playerHealth = player.getHealth();
    int opponentHealth = opponent.getHealth();
    int playerEnergy = 10;
    int opponentEnergy = 10;

    // Main battle loop
    while (playerHealth > 0 && opponentHealth > 0) {
        // Player's turn
        if (goFirst == true) {
            bool player_defending = false;
            bool opponent_defending = false;
            cout << player.getName() << "'s turn: Choose an action" << endl;
            if (playerEnergy > 0) {
                cout << "1. Light Attack (Cost: 2 Energy)" << endl;
                cout << "2. Heavy Attack (Cost: 4 Energy)" << endl;
                cout << "3. Special Skill (Cost: 6 Energy)" << endl;
                cout << "4. Ultimate (Cost: 8 Energy)" << endl;
            }
            cout << "5. Defend" << endl;

            int playerChoice;
            cout << "Enter your choice: ";
            cin >> playerChoice;
            cout << endl;

            int playerDamage = 0;
            int playerEnergyCost = 0;

            switch (playerChoice) {
                case 1:
                    if (playerEnergy >= 2) {
                        cout << player.getName() <<" uses Light Attack!" << endl;
                        playerDamage = 10 + player.getAttack();
                        playerEnergyCost = 2;
                    } else {
                        cout << "Not enough energy! " << player.getName() << " defends." << endl;
                        playerEnergyCost = 0; // Defending costs no energy
                        playerEnergy += 2; // Gain 2 energy when defending
                        player_defending = true;
                    }
                    break;
                case 2:
                    if (playerEnergy >= 4) {
                        cout << player.getName() << " uses Heavy Attack!" << endl;
                        playerDamage = 20 + player.getAttack();
                        playerEnergyCost = 4;
                    } else {
                        cout << "Not enough energy! " << player.getName() << " defends." << endl;
                        playerEnergyCost = 0; // Defending costs no energy
                        playerEnergy += 2; // Gain 2 energy when defending
                        player_defending = true;
                    }
                    break;
                case 3:
                    if (playerEnergy >= 6) {
                        cout << player.getName() << " uses Special Skill!" << endl;
                        playerDamage = 30 + player.getAttack();
                        playerEnergyCost = 6;
                    } else {
                        cout << "Not enough energy! " << player.getName() << " defends." << endl;
                        playerEnergyCost = 0; // Defending costs no energy
                        playerEnergy += 2; // Gain 2 energy when defending
                        player_defending = true;
                    }
                    break;
                case 4:
                    if (playerEnergy >= 8) {
                        cout << "Player uses Ultimate!" << endl;
                        playerDamage = 50 + player.getAttack();
                        playerEnergyCost = 8;
                    } else {
                        cout << "Not enough energy! " << player.getName() << " defends." << endl;
                        playerEnergyCost = 0; // Defending costs no energy
                        playerEnergy += 2; // Gain 2 energy when defending
                        player_defending = true;
                    }
                    break;
                case 5:
                    cout << player.getName() << " chooses to Defend!" << endl;
                    playerEnergyCost = 0; // Defending costs no energy
                    playerEnergy += 2; // Gain 2 energy when defending
                    player_defending = true;
                    break;
                default:
                    cout << "Invalid choice! Player skips turn." << endl;
                    break;
            }

            // Update player's energy
            playerEnergy -= playerEnergyCost;
            if (playerEnergy < 0) {
                playerEnergy = 0;
            }

            cout << endl;
            cout << "--------------------------------------" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));

            // Opponent's turn
            cout << opponent.getName() << "'s turn: Choose an action" << endl;
            if (opponentEnergy > 0) {
                cout << "1. Light Attack (Cost: 2 Energy)" << endl;
                cout << "2. Heavy Attack (Cost: 4 Energy)" << endl;
                cout << "3. Special Skill (Cost: 6 Energy)" << endl;
                cout << "4. Ultimate (Cost: 8 Energy)" << endl;
            }
            cout << "5. Defend" << endl;
            cout << endl;

            int opponentChoice = rand() % 5 + 1; // Random choice between 1 and 5
            int opponentDamage = 0;
            int opponentEnergyCost = 0;

            switch (opponentChoice) {
                case 1:
                    if (opponentEnergy >= 2) {
                        cout << opponent.getName() << " uses Light Attack!" << endl;
                        opponentDamage = 10 + opponent.getAttack();
                        opponentEnergyCost = 2;
                    } else {
                        cout << opponent.getName() << " doesn't have enough energy! " << opponent.getName() << " defends." << endl;
                        opponentEnergyCost = 0; // Defending costs no energy
                        opponentEnergy += 2; // Gain 2 energy when defending
                        opponent_defending = true;
                    }
                    break;
                case 2:
                    if (opponentEnergy >= 4) {
                        cout << opponent.getName() << " uses Heavy Attack!" << endl;
                        opponentDamage = 20 + opponent.getAttack();
                        opponentEnergyCost = 4;
                    } else {
                        cout << opponent.getName() << " doesn't have enough energy! " << opponent.getName() << " defends." << endl;
                        opponentEnergyCost = 0; // Defending costs no energy
                        opponentEnergy += 2; // Gain 2 energy when defending
                        opponent_defending = true;
                    }
                    break;
                case 3:
                    if (opponentEnergy >= 6) {
                        cout << opponent.getName() << " uses Special Skill!" << endl;
                        opponentDamage = 30 + opponent.getAttack();
                        opponentEnergyCost = 6;
                    } else {
                        cout << opponent.getName() << " doesn't have enough energy! " << opponent.getName() << " defends." << endl;
                        opponentEnergyCost = 0; // Defending costs no energy
                        opponentEnergy += 2; // Gain 2 energy when defending
                        opponent_defending = true;
                    }
                    break;
                case 4:
                    if (opponentEnergy >= 8) {
                        cout << opponent.getName() << " uses Ultimate!" << endl;
                        opponentDamage = 50 + opponent.getAttack();
                        opponentEnergyCost = 8;
                    } else {
                        cout << opponent.getName() << " doesn't have enough energy! " << opponent.getName() << " defends." << endl;
                        opponentEnergyCost = 0; // Defending costs no energy
                        opponentEnergy += 2; // Gain 2 energy when defending
                        opponent_defending = true;
                    }
                    break;
                case 5:
                    cout << opponent.getName() << " chooses to Defend!" << endl;
                    opponentEnergyCost = 0; // Defending costs no energy
                    opponentEnergy += 2; // Gain 2 energy when defending
                    opponent_defending = true;
                    break;
                default:
                    cout << "Invalid choice! " << opponent.getName() <<" skips turn." << endl;
                    break;
            }

            // Update opponent's energy
            opponentEnergy -= opponentEnergyCost;
            if (opponentEnergy < 0) {
                opponentEnergy = 0;
            }

            cout << endl;
            cout << "--------------------------------------" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));

            // Calculate damage to each other
            if (opponent_defending) {
                playerDamage = playerDamage * (1 - (opponent.getDefense() * 10) / 100); // Damage reduction based on defense stat
            }
            if (player_defending) {
                opponentDamage = opponentDamage * (1 - (player.getDefense() * 10) / 100); // Damage reduction based on defense stat
            }
            playerHealth -= opponentDamage;
            opponentHealth -= playerDamage;
            this_thread::sleep_for(chrono::milliseconds(1000));

            // Display the outcome of the turn
            cout << "->" << player.getName() << " takes " << opponentDamage << " damage!" << " HP: " << playerHealth << " Energy: " << playerEnergy << endl;
            cout << "->" << opponent.getName() << " takes " << playerDamage << " damage!" << " HP: " << opponentHealth << " Energy: " << opponentEnergy << endl;

            // Check for game over
            if (playerHealth <= 0) {
                this_thread::sleep_for(chrono::milliseconds(1000));
                cout << endl;
                cout << "!!! "<< player.getName() << " has been defeated! Game over. !!!" << endl;
                break;
            } else if (opponentHealth <= 0) {
                this_thread::sleep_for(chrono::milliseconds(1000));
                cout << endl;
                cout << "!!! "<< opponent.getName() << " has been defeated! " << player.getName() << " wins. !!!" << endl;
                break;
            }

            // Wait for a moment before next turn
            this_thread::sleep_for(chrono::seconds(2));
            cout << "--------------------------------------" << endl;
        }

        else {
            bool opponent_defending = false;
            bool player_defending = false;
            // Opponent's turn
            cout << opponent.getName() << "'s turn: Choose an action" << endl;
            if (opponentEnergy > 0) {
                cout << "1. Light Attack (Cost: 2 Energy)" << endl;
                cout << "2. Heavy Attack (Cost: 4 Energy)" << endl;
                cout << "3. Special Skill (Cost: 6 Energy)" << endl;
                cout << "4. Ultimate (Cost: 8 Energy)" << endl;
            }
            cout << "5. Defend" << endl;
            cout << endl;

            int opponentChoice = rand() % 5 + 1; // Random choice between 1 and 5
            int opponentDamage = 0;
            int opponentEnergyCost = 0;

            switch (opponentChoice) {
                case 1:
                    if (opponentEnergy >= 2) {
                        cout << opponent.getName() << " chose! Your turn!" << endl;
                        opponentDamage = 10 + opponent.getAttack();
                        opponentEnergyCost = 2;
                    } else {
                        cout << opponent.getName() << " doesn't have enough energy! " << opponent.getName() << " defends." << endl;
                        opponentEnergyCost = 0; // Defending costs no energy
                        opponentEnergy += 2; // Gain 2 energy when defending
                        opponent_defending = true;
                    }
                    break;
                case 2:
                    if (opponentEnergy >= 4) {
                        cout << opponent.getName() << " chose! Your turn!" << endl;
                        opponentDamage = 20 + opponent.getAttack();
                        opponentEnergyCost = 4;
                    }else {
                        cout << opponent.getName() << " doesn't have enough energy! " << opponent.getName() << " defends." << endl;
                        opponentEnergyCost = 0; // Defending costs no energy
                        opponentEnergy += 2; // Gain 2 energy when defending
                        opponent_defending = true;
                    }
                    break;
                case 3:
                    if (opponentEnergy >= 6) {
                        cout << opponent.getName() << " chose! Your turn!" << endl;
                        opponentDamage = 30 + opponent.getAttack();
                        opponentEnergyCost = 6;
                    } else {
                        cout << opponent.getName() << " doesn't have enough energy! " << opponent.getName() << " defends." << endl;
                        opponentEnergyCost = 0; // Defending costs no energy
                        opponentEnergy += 2; // Gain 2 energy when defending
                        opponent_defending = true;
                    }
                    break;
                case 4:
                    if (opponentEnergy >= 8) {
                        cout << opponent.getName() << " chose! Your turn!" << endl;
                        opponentDamage = 50 + opponent.getAttack();
                        opponentEnergyCost = 8;
                    } else {
                        cout << opponent.getName() << " doesn't have enough energy! " << opponent.getName() << " defends." << endl;
                        opponentEnergyCost = 0; // Defending costs no energy
                        opponentEnergy += 2; // Gain 2 energy when defending
                        opponent_defending = true;
                    }
                    break;
                case 5:
                    cout << opponent.getName() << " chose! Your turn!" << endl;
                    opponentEnergyCost = 0; // Defending costs no energy
                    opponentEnergy += 2; // Gain 2 energy when defending
                    opponent_defending = true;
                    break;
                default:
                    cout << "Invalid choice! " << opponent.getName() <<" skips turn." << endl;
                    break;
            }

            // Update opponent's energy
            opponentEnergy -= opponentEnergyCost;
            if (opponentEnergy < 0) {
                opponentEnergy = 0;
            }
            
            cout << endl;
            cout << "--------------------------------------" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            
            // Player's turn
            cout << player.getName() << "'s turn: Choose an action" << endl;
            if (playerEnergy > 0) {
                cout << "1. Light Attack (Cost: 2 Energy)" << endl;
                cout << "2. Heavy Attack (Cost: 4 Energy)" << endl;
                cout << "3. Special Skill (Cost: 6 Energy)" << endl;
                cout << "4. Ultimate (Cost: 8 Energy)" << endl;
            }
            cout << "5. Defend" << endl;

            int playerChoice;
            cout << "Enter your choice: ";
            cin >> playerChoice;
            cout << endl;

            int playerDamage = 0;
            int playerEnergyCost = 0;

            switch (playerChoice) {
                case 1:
                    if (playerEnergy >= 2) {
                        cout << player.getName() <<" uses Light Attack!" << endl;
                        playerDamage = 10 + player.getAttack();
                        playerEnergyCost = 2;
                    } else {
                        cout << "Not enough energy! " << player.getName() << " defends." << endl;
                        playerEnergyCost = 0; // Defending costs no energy
                        playerEnergy += 2; // Gain 2 energy when defending
                        player_defending = true;
                    }
                    break;
                case 2:
                    if (playerEnergy >= 4) {
                        cout << player.getName() << " uses Heavy Attack!" << endl;
                        playerDamage = 20 + player.getAttack();
                        playerEnergyCost = 4;
                    } else {
                        cout << "Not enough energy! " << player.getName() << " defends." << endl;
                        playerEnergyCost = 0; // Defending costs no energy
                        playerEnergy += 2; // Gain 2 energy when defending
                        player_defending = true;
                    }
                    break;
                case 3:
                    if (playerEnergy >= 6) {
                        cout << player.getName() << " uses Special Skill!" << endl;
                        playerDamage = 30 + player.getAttack();
                        playerEnergyCost = 6;
                    } else {
                        cout << "Not enough energy! " << player.getName() << " defends." << endl;
                        playerEnergyCost = 0; // Defending costs no energy
                        playerEnergy += 2; // Gain 2 energy when defending
                        player_defending = true;
                    }
                    break;
                case 4:
                    if (playerEnergy >= 8) {
                        cout << "Player uses Ultimate!" << endl;
                        playerDamage = 50 + player.getAttack();
                        playerEnergyCost = 8;
                    } else {
                        cout << "Not enough energy! " << player.getName() << " defends." << endl;
                        playerEnergyCost = 0; // Defending costs no energy
                        playerEnergy += 2; // Gain 2 energy when defending
                        player_defending = true;
                    }
                    break;
                case 5:
                    cout << player.getName() << " chooses to Defend!" << endl;
                    playerEnergyCost = 0; // Defending costs no energy
                    playerEnergy += 2; // Gain 2 energy when defending
                    player_defending = true;
                    break;
                default:
                    cout << "Invalid choice! Player skips turn." << endl;
                    break;
            }

            // Update player's energy
            playerEnergy -= playerEnergyCost;
            if (playerEnergy < 0) {
                playerEnergy = 0;
            }

            cout << endl;
            cout << "--------------------------------------" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));

            // Calculate damage to each other
            if (opponent_defending) {
                playerDamage = playerDamage * (1 - (opponent.getDefense() * 10) / 100); // Damage reduction based on defense stat
            }
            if (player_defending) {
                opponentDamage = opponentDamage * (1 - (player.getDefense() * 10) / 100); // Damage reduction based on defense stat
            }
            playerHealth -= opponentDamage;
            opponentHealth -= playerDamage;
            this_thread::sleep_for(chrono::milliseconds(1000));

            // Display the outcome of the turn
            cout << "->" << player.getName() << " takes " << opponentDamage << " damage!" << " HP: " << playerHealth << " Energy: " << playerEnergy << endl;
            cout << "->" << opponent.getName() << " takes " << playerDamage << " damage!" << " HP: " << opponentHealth << " Energy: " << opponentEnergy << endl;

            // Check for game over
            if (playerHealth <= 0) {
                this_thread::sleep_for(chrono::milliseconds(1000));
                cout << endl;
                cout << "!!! "<< player.getName() << " has been defeated! Game over. !!!" << endl;
                break;
            } else if (opponentHealth <= 0) {
                this_thread::sleep_for(chrono::milliseconds(1000));
                cout << endl;
                cout << "!!! "<< opponent.getName() << " has been defeated! " << player.getName() << " wins. !!!" << endl;
                break;
            }

            // Wait for a moment before next turn
            this_thread::sleep_for(chrono::seconds(2));
            cout << "--------------------------------------" << endl;
        }
    }
}

#endif