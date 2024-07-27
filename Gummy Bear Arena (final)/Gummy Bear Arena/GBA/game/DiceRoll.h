#ifndef DiceRoll_H
#define DiceRoll_H

#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <iostream>

void rollDiceAnimation() {
    // Seed the random number generator
    srand(time(nullptr));

    // Number of frames for animation
    const int numFrames = 10;

    // Animation loop
    for (int i = 0; i < numFrames; ++i) {
        // Clear the screen
        system("cls");
        cout << "Rolling dice: ";
        for (int j = 0; j < i; ++j) {
            cout << "-";
        }

        // Sleep for a short duration to create animation effect
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << endl;
}

// Function to handle dice roll showdown to determine who goes first
bool diceRollShowdown(string playerName, string opponentName) {
    // Roll the dice animation
    rollDiceAnimation();

    // Roll dice for player and opponent
    int playerRoll = rand() % 6 + 1; // Roll a number from 1 to 6
    int opponentRoll = rand() % 6 + 1; // Roll a number from 1 to 6

    cout << playerName << " rolled: " << playerRoll << endl;
    cout << opponentName << " rolled: " << opponentRoll << endl;

    // Determine who goes first based on the higher roll
    if (playerRoll > opponentRoll) {
        cout << playerName << " goes first!" << endl;
        cout << endl;
        return true;

    } else if (opponentRoll > playerRoll) {
        cout << opponentName << " goes first!" << endl;
        cout << endl;
        return false;

    } else {
        cout << "It's a tie! Rolling again..." << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        return diceRollShowdown(playerName, opponentName); // If it's a tie, roll again
    }
    
}

#endif