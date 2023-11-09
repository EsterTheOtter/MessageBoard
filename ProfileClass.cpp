#include <iostream>
#include <iomanip>

#include "ProfileClass.hpp"
#include "CharacterClass.hpp"


//operators
//functions
Profile::Profile(std::string uName) {
    menuStatus = 1;
    pName = uName;
    registeredChars;
}

Profile::~Profile() {
}

void Profile::runProfile() {
    std::cout << "Initializing assets...\n";
    //*Initialize here
    std::cout << "Initialization complete.\n";

    while(_getMenuStatus() == 1) {
        std::cout << "Welcome SMCSC Member! What would you like to do?\n\n"
        << "[1]_Run check\n"
        << "[2]_Create new character\n"
        << "[3]_Modify existing character\n"
        << "[4]_Exit\n";

        _setUserInput();

        if (_getUserInput() == "1" || _getUserInput() == "run" || _getUserInput() == "run check" || _getUserInput() == "check") {
            //Run check program
        } else if (_getUserInput() == "2" || _getUserInput() == "create new character" || _getUserInput() == "create new" || _getUserInput() == "create" || _getUserInput() == "new character" || _getUserInput() == "new") {
            std::cout << "Would you like to create a new character?\ny/n\n\n";
            _setUserInput();
            if (_getUserInput() == "n") {
            } else if (_getUserInput() == "y") {
                createCharacter();
            }
        } else if (_getUserInput() == "3" || _getUserInput() == "modify existing character" || _getUserInput() == "modify existing" || _getUserInput() == "modify" || _getUserInput() == "existing character" || _getUserInput() == "existing") {
            //Modify existing character
        } else if (_getUserInput() == "4" || _getUserInput() == "exit") {
            _setMenuStatus(0);
        }
    }
    _resetMenu();
}
    //Save
    //Load
    //Characters
void Profile::createCharacter() {
    std::cout << "Please input the character you wish to enter:\n";
    _setUserInput();
    //*Run check to ensure user does not duplicate already existing character
}
//accessors
    //getters
    std::string Profile::_getUserInput() {
    for (auto& i : userInput) {
        i = tolower(i);
    }
    return userInput;
}
    //setters
void Profile::_setUserInput() {
    std::string uInput = " ";
    std::cout << "User: ";
    getline(std::cin, uInput);
    std::cout << "\n";
    userInput = uInput;
}

void Profile::_setMenuStatus(bool uInput) {
    menuStatus = uInput;
};
//modifiers