#include <iostream>
#include <Windows.h>
#include <chrono>
#include <ctime>

#include "Program.hpp"
#include "ProfileClass.hpp"


//operators
//functions
Program::Program() {
    menuActive = 1;
}

Program::~Program() {

}

void Program::runMainMenu() {
    //*conditional startup- first startup directs to profile creation
    //initialization
    system("cls");
    //runtime
    while (_isMenuActive()) {
        //Main Menu
        //* Conditional menu- only display continue if there was a previous session
        //Conditional checks and Event Logic


        //* get from userprofile database
        //* if (userProfileExists) { below } else if (!userProfileExists) { Options 1 & 2 do not display }
        std::cout << "Welcome... Please select an option:\n\n"
        << "[1]_Continue last session\n"
        << "[2]_New Profile\n"
        << "[3]_Load Profile\n"
        << "[4]_Options\n"
        << "[5]_Exit\n";

        _setUserInput();
        //Continue last session
        if (_getUserInput() == "1" || _getUserInput() == "continue" || _getUserInput() == "continue last session" || _getUserInput() == "last" || _getUserInput() == "last session" ) {
            std::cout << "Continue last used profile?\ny/n\n\n";
            //*proceeds to display information regarding profile: profile name, dates, access time, creation time, etc. to aid in decision to continue- perhapse provide timestamp of profile
            _setUserInput();
            if (_getUserInput() == "n") {
            } else if (_getUserInput() == "y") {
                continueProfile();
            }
        //New Profile
        } else if (_getUserInput() == "2" || _getUserInput() == "new" || _getUserInput() == "new profile") {
            system("cls");
            std::cout << "Create a new profile?\ny/n\n\n";
            _setUserInput();
            if (_getUserInput() == "n") {
            } else if (_getUserInput() == "y") {
                createNewProfile();
            }
        //Load Profile
        } else if (_getUserInput() == "3" || _getUserInput() == "load profile" || _getUserInput() == "load") {
            loadProfile();
        //Options
        } else if (_getUserInput() == "4" || _getUserInput() == "options" || _getUserInput() == "option") {
            options();
        //Exit
        } else if (_getUserInput() == "5" || _getUserInput() == "exit") {
            _closeMenuStatus();
        }
    }
}

void Program::createNewProfile() {
    std::string uProfileName;
    while (_isMenuActive() == 1) {
        system("cls");
        std::cout << "Please input profile name:\n";
        _setUserInput();
        uProfileName = _getTrueUserInput();

        //form confirmation
        
        std::cout << "You selected the profile name \"" << uProfileName << "\", is this correct?\ny/n\n\n";
        _setUserInput();
        userConfirmation();
    }
    _openMenuStatus();
    std::cout << "Creating user profile...\n";
    Profile uProfile(uProfileName);
    //* Exports user settings to .dat file using given profile name
    std::ofstream userProfile;
    userProfile.open(uProfileName+".dat");
    //* Creates profile: Name, time and date created, and access time should be created and stored in separate file utilizing fstream
    auto time_created = std::chrono::system_clock::now();
    std::cout << "User profile created.\n";
    std::cout << "Loading user profile... " << uProfile._getProfileName() << "\n";
    uProfile.runProfile_Menu();
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

void Program::userConfirmation() {
    if (_getUserInput() == "n") {
    } else if (_getUserInput() == "y") {
        _closeMenuStatus();
    } else {
        systemException();
    }
}

void Program::systemException() {
    std::cout << "Please input a proper response.\n";
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
//modifiers