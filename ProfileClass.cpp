#include <iostream>
#include <fstream>

#include "ProfileClass.hpp"
#include "CharacterClass.hpp"


//*--Leave open for event handling capabilities later

////        operators       ////
////        functions       ////
//Profile Constructor
Profile::Profile(std::string inputUserName, std::string inputOrgName) {
    menuActive = 1;
    profileName = inputUserName;
    orgName = inputOrgName;
    registeredChars;
    charsQuantities;
}

//Profile Destructor
Profile::~Profile() {
}

/*Hosts/Runs the profile interface and logic
    function: runProfile_Menu
    param: none
    return: void
*/
void Profile::runProfile_Menu() {
    std::cout << "Initializing assets...\n";
    //*--Initialize here
    std::cout << "Initialization complete.\n";
    system("cls");

    while(_isMenuActive() == 1) {
        //*--Main Menu
        std::cout << "Welcome " << profileName << "! What would you like to do?\n\n"
        << "[1]_Run check\n"
        << "[2]_Create new character\n"
        << "[3]_Modify existing character\n"
        << "[4]_Exit\n";

        set_user_response();
        //*--Checks user's decision
        if (retrieve_user_response() == "1" || retrieve_user_response() == "run" || retrieve_user_response() == "run check" || retrieve_user_response() == "check") {
            //*--Displays existing characters if any are present
            if (registeredChars.size() == 0) {
                std::cout << "There are currently no existing characters.\n";
                system("pause");
                continue;
            } else {
                std::cout << "Existing characters:\n";
                for (int i = 0; i < registeredChars.size(); i++) {
                    std::cout << registeredChars[i] << "\n";
                }
            }
        //*--Process new character creation request, 1. runProfile_createCharacter()
        } else if (retrieve_user_response() == "2" || retrieve_user_response() == "create new character" || retrieve_user_response() == "create new" || retrieve_user_response() == "create" || retrieve_user_response() == "new character" || retrieve_user_response() == "new") {
            while (_isMenuActive()) {
                std::cout << "Would you like to create a new character?\ny/n\n\n";
                set_user_response();
                if (retrieve_user_response() == "n") {
                } else if (retrieve_user_response() == "y") {
                    runProfile_createCharacter();
                    break;
                } else {
                    systemException();
                    std::cout << "Improper user response.\n";
                }
            }
        } else if (retrieve_user_response() == "3" || retrieve_user_response() == "modify existing character" || retrieve_user_response() == "modify existing" || retrieve_user_response() == "modify" || retrieve_user_response() == "existing character" || retrieve_user_response() == "existing") {
        //*--Modify existing character properties
        std::cout << "Placeholder\n";
        //*--Returns back to main menu, 1. _closeMenuStatus()
        } else if (retrieve_user_response() == "4" || retrieve_user_response() == "exit") {
            _closeMenuStatus();
        }
        continue;
    }
    _openMenuStatus();
}
    //Save
    //Load
    /*Loads profile data from a local .dat file

        function: loadProfile
        param: none
        return: void
    */
void Profile::loadProfile() {
    //*Pulls from .dat file
}
    //Character functions
        /*Create new character object

        function: runProfile_createCharacter
        param: none
        return: void
        */
void Profile::runProfile_createCharacter() {
    while (_isMenuActive()) {
        repeat:
        //*--requests desired character
        std::cout << "Please input the character you wish to enter:\n";
        set_user_response();
        std::string userInput = retrieve_user_response();
        char charInput = userInput[0];
        /*Run check to ensure user does not duplicate already existing character
        param: isExistingCharacter, bool- does the user-submitted character already exist? y/n?
        */
       while(_isMenuActive()) {
        if (isExistingCharacter(charInput)) {
            std::cout << "Sorry, \"" <<  charInput << " \" already exists in the current library.\nWould you still like to input a new entry?\ny/n\n\n";
            set_user_response();
            if (retrieve_user_response() == "n") {
                _closeMenuStatus();
                break;
            } else if (retrieve_user_response() == "y") {
                _closeMenuStatus();
                continue;
            } else {
                systemException();
                std::cout << "Please enter a proper response\n";
            }
        } else {
            _openMenuStatus();
            //*
            Character character(charInput);
            character._addQuantity();
            _registerCharacter(charInput, registeredChars);
            while(_isMenuActive()) {
                std::cout << "The character " << character._getCharacter() << " has been added. Would you like to enter another character?\ny/n\n\n";
                set_user_response();
                if (retrieve_user_response() == "n") {
                    _closeMenuStatus();
                } else if (retrieve_user_response() == "y") {
                    goto repeat;
                } else {
                    std::cout << "Please enter a proper response.\n";
                }
            }
        }
        _closeMenuStatus();
       }
    }
    _openMenuStatus();
}
        //Add Character
void Profile::_updateCharacter() {

}
        //Character checks
bool Profile::isExistingCharacter(char uInput) {
    for (int i = 0; i < registeredChars.size(); i++) {
        if (uInput == registeredChars[i]) {
            return true;
        }
    }
    return false;
}

void Profile::systemException() {
    std::cout << "System Exception: \n";
}

////        accessors       ////
    //getters
    std::string Profile::retrieve_user_response() {
    for (auto& i : userInput) {
        i = tolower(i);
    }
    return userInput;
}
    //setters
void Profile::set_user_response() {
    std::string uInput = " ";
    std::cout << "User: ";
    getline(std::cin, uInput);
    std::cout << "\n";
    userInput = uInput;
}

void Profile::_registerCharacter(char userInput, std::vector<char> &outputCharVector) {
    outputCharVector.push_back(userInput);
}
////        modifiers       ////