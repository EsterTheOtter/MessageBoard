#include <iostream>
#include <Windows.h>

#include "Program.hpp"
#include "ProfileClass.hpp"


//operators
//functions
Program::Program() {
    menuStatus = 1;
}

Program::~Program() {

}

void Program::mainMenu() {
    //*conditional startup- first startup directs to profile creation
    //initialization
    system("cls");
    //runtime
    while (_getMenuStatus() == 1) {
        //Main Menu
        std::cout << "Welcome... Please select an option:\n\n"
        << "[1]_Continue last session\n"
        << "[2]_New Profile\n"
        << "[3]_Load Profile\n"
        << "[4]_Options\n"
        << "[5]_Exit\n";

        _setUserInput();
        //Continue last session
        if (_getUserInput() == "1" || _getUserInput() == "continue" || _getUserInput() == "continue last profile" || _getUserInput() == "last" || _getUserInput() == "last profile" ) {
            std::cout << "Continue last used profile?\ny/n\n\n";
            //*proceeds to display information regarding profile: profile name, dates, access time, creation time, etc. to aid in decision to continue- perhapse provide timestamp of profile
            _setUserInput();
            if (_getUserInput() == "n") {
            } else if (_getUserInput() == "y") {
                continueProfile();
            }
        //New Profile
        } else if (_getUserInput() == "2" || _getUserInput() == "new" || _getUserInput() == "new profile") {
            std::cout << "Create a new profile?\ny/n\n\n";
            _setUserInput();
            if (_getUserInput() == "n") {
            } else if (_getUserInput() == "y") {
                newProfile();
            }
        //Load Profile
        } else if (_getUserInput() == "3" || _getUserInput() == "load profile" || _getUserInput() == "load") {
            loadProfile();
        //Options
        } else if (_getUserInput() == "4" || _getUserInput() == "options" || _getUserInput() == "option") {
            options();
        //Exit
        } else if (_getUserInput() == "5" || _getUserInput() == "exit") {
            _setMenuStatus(0);
        }
    }
}

void Program::newProfile() {
    std::string uProfileName;
    while (_getMenuStatus() == 1) {
        std::cout << "Please input profile name:\n";
        _setUserInput();
        uProfileName = _getTrueUserInput();
        std::cout << "You selected \"" << uProfileName << "\", is this correct?\ny/n\n\n";
        _setUserInput();
        if (_getUserInput() == "n") {
        } else if (_getUserInput() == "y") {
            _setMenuStatus(0);
        }
    }
    _resetMenu();
    Profile uProfile(uProfileName);
    uProfile.runProfile();
    //*Exports user settings to plain text file
    
    //*Creates profile: Name, time and date created, and access time should be created and stored in separate file utilizing iomanip
}

void Program::loadProfile() {
    //*menu interface that displays all saved profiles located at specific folder
}

void Program::continueProfile() {
    //*menu interface that accessess last used file
}

void Program::options() {
    //*menu interface that displays options
}

void Program::exit() {

}

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

void Program::_setMenuStatus(bool uInput) {
    menuStatus = uInput;
};
//modifiers