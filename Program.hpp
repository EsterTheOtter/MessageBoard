#ifndef Program_hpp
#define Program_hpp

#include <string>


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
    //True user input- gets unmodified user input
    //*Messy, implament manually later down line if no better alternative
    inline std::string _getTrueUserInput() {return userInput;}
        //setters
    void _setUserInput();
    void _setMenuStatus(bool uInput);
    inline void _resetMenu() {menuStatus = 1;}
    //modifiers
};

#endif