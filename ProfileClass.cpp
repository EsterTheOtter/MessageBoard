#include <iostream>
#include <fstream>

#include "ProfileClass.hpp"
#include "CharacterClass.hpp"


//*Leave open for event handling capabilities later

//operators
//functions
Profile::Profile(std::string uName, std::string oName) {
    menuStatus = 1;
    pName = uName;
    orgName = oName;
    registeredChars;
}

Profile::~Profile() {
}

void Profile::runProfile() {
    std::cout << "Initializing assets...\n";
    //*Initialize here
    std::cout << "Initialization complete.\n";

    while(_getMenuStatus() == 1) {
        std::cout << "Welcome " << pName << "! What would you like to do?\n\n"
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
        //Character creation
void Profile::createCharacter() {
    while (_getMenuStatus()) {
        std::cout << "Please input the character you wish to enter:\n";
        _setUserInput();
        //*Run check to ensure user does not duplicate already existing character
        std::string userInput = _getUserInput();
        char charInput = userInput[0];
        if (characterCheck(charInput)) {
            std::cout << charInput << " already exists in the current library.\nWould you like to input a new entry?\ny/n\n\n";
            _setUserInput();
            if(_getUserInput() == "n") {
                _setMenuStatus(0);
            } else if (_getUserInput() == "y") {
            }
        }
    }
    _resetMenu();
}
        //Character check
bool Profile::characterCheck(char uInput) {
    for (int i = 0; i < registeredChars.size(); i++) {
        if (uInput == registeredChars[i]) {
            return true;
        }
    }
    return false;
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
}
//modifiers