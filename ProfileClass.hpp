#ifndef ProfileClass_hpp
#define ProfileClass_hpp

#include <string>
#include <vector>


class Profile {
    private:
    bool menuActive;
    std::string userInput;
    std::string profileName;
    std::string orgName;
    std::vector<char> registeredChars;
    public:
    //operators
    //functions
    Profile(std::string inputUserName = "Member", std::string inputOrgName = "SMCSC");
    virtual ~Profile();
    void runProfile();
        //Save
        //Load
        //Characters
            //Character creation
    void createNewCharacter();
            //Character checks
    bool isExistingCharacter(char uInput);

    //accessors
        //getters
    inline bool _isMenuActive() const {return menuActive;}
    std::string _getUserInput();
        //setters
    void _setUserInput();
    inline void _closeMenuStatus() {menuActive = 0;}
    inline void _openMenuStatus() {menuActive = 1;}
    void _setRegisteredCharacter(char &userInput, std::vector<char> &charOutput);
    //modifiers
};

#endif