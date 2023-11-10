#ifndef ProfileClass_hpp
#define ProfileClass_hpp

#include <string>
#include <vector>


class Profile {
    private:
    bool menuStatus;
    std::string userInput;
    std::string pName;
    std::string orgName;
    std::vector<char> registeredChars;
    public:
    //operators
    //functions
    Profile(std::string uName = "Member", std::string oName = "SMCSC");
    virtual ~Profile();
    void runProfile();
        //Save
        //Load
        //Characters
            //Character creation
    void createCharacter();
            //Character check
    bool characterCheck(char uInput);
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