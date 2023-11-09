#ifndef ProfileClass_hpp
#define ProfileClass_hpp

#include <string>
#include <vector>


class Profile {
    private:
    bool menuStatus;
    std::string userInput;
    std::string pName;
    std::vector<char> registeredChars;
    public:
    //operators
    //functions
    Profile(std::string uName);
    virtual ~Profile();
    void runProfile();
        //Save
        //Load
        //Characters
    void createCharacter();
    //accessors
        //getters
    inline bool _getMenuStatus() const {return menuStatus;}
    std::string _getUserInput();
        //setters
    void _setUserInput();
    void _setMenuStatus(bool uInput);
    inline void _resetMenu() {menuStatus = 1;}
    //modifiers
};

#endif