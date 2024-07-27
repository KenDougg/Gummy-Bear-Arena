#ifndef menu_h
#define menu_h

#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <iostream>

// Function to handle main menu
string mainMenu() {
    cout << "Welcome to Gummy Bear Arena!" << endl;
    this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "Enter your name: ";
    string playerName;
    getline(cin, playerName);
    system("cls");

    cout << "Hello, " << playerName << "!" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Quit" << endl;
    cout << "Choose an option: ";

    return playerName;
}

#endif