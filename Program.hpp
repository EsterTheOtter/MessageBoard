#ifndef Program_hpp
#define Program_hpp

#include <string>


class Program {
    private:
    bool menuActive;
    std::string userInput;
    public:
    //operators
    //functions
    Program();
    virtual ~Program();
    void runMainMenu();
    void createNewProfile();
    void loadProfile();
    void continueProfile();
    void options();
    void exit();
    //accessors
        //getters
    inline bool _isMenuActive() const {return menuActive;}
    std::string _getUserInput();
    //True user input- gets unmodified user input
    //*Messy, implament manually later down line if no better alternative
    inline std::string _getTrueUserInput() {return userInput;}
        //setters
    void _setUserInput();
    inline void _closeMenuStatus() {menuActive = 0;}
    inline void _openMenuStatus() {menuActive = 1;}
    //modifiers
};

#endif