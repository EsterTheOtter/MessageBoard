#ifndef Program_hpp
#define Program_hpp

#include <string>

#include "CharacterClass.hpp"


class Program {
    private:
    bool menuStatus;
    std::string userInput;
    public:
    //operators
    //functions
    Program();
    virtual ~Program();
    void mainMenu();
    void newProfile();
    void loadProfile();
    void continueProfile();
    void options();
    void exit();
    //accessors
        //getters
    inline bool _getMenuStatus() const {return menuStatus;}
    std::string _getUserInput();
        //setters
    void _setUserInput();
    inline void _setMenuStatus(bool uInput) {menuStatus == uInput;}
    //modifiers
};

#endif