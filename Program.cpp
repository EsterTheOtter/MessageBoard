#include <iostream>
#include <iomanip>
#include <Windows.h>

#include "Program.hpp"
#include "CharacterClass.hpp"


//operators
//functions
Program::Program() {
    menuStatus = 1;
};

Program::~Program() {

};

void Program::mainMenu() {
    //conditional startup- first startup directs to profile creation
    //initialization
    system("cls");
    //runtime
    while (_getMenuStatus() == 1) {
        std::cout << "Welcome... Please select an option:\n\n"
        << "[1]_Continue last profile\n"
        << "[2]_New Profile\n"
        << "[3]_Load Profile\n"
        << "[4]_Options\n"
        << "[5]_Exit\n";

        _setUserInput();
        if (_getUserInput() == "5" || _getUserInput() == "exit") {
            _setMenuStatus(0);
            break;
        };
    }
};

void Program::newProfile() {

};

void Program::loadProfile() {

};

void Program::continueProfile() {

};

void Program::options() {

};

void Program::exit() {

};

//accessors
    //getters
std::string Program::_getUserInput() {
    for (auto& i : userInput) {
        i = tolower(i);
    }
    return userInput;
}
    //setters
void Program::_setUserInput() {
    std::string uInput = " ";
    std::cout << "User: ";
    getline(std::cin, uInput);
    std::cout << "\n";
    userInput = uInput;
}
//modifiers