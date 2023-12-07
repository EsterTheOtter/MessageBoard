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
    int charsQuantities;
    public:
    ////        operators       ////
    ////        functions       ////
    Profile(std::string inputUserName = "Member", std::string inputOrgName = "SMCSC");
    virtual ~Profile();
    void runProfile_Menu();
        //Save
        //Load
    void loadProfile();
        //Characters
            //Character creation
    void runProfile_createCharacter();
            //Character checks
    bool isExistingCharacter(char uInput);
    void systemException();
    ////        accessors       ////
    //      getters     //
    inline bool _isMenuActive() const {return menuActive;}
    std::string retrieve_user_response();
    inline std::string _getProfileName() const {return profileName;}
    //      setters     //
    void set_user_response();
    inline void _closeMenuStatus() {menuActive = 0;}
    inline void _openMenuStatus() {menuActive = 1;}
    void _registerCharacter(char userInput, std::vector<char> &outputCharVector);
    void _updateCharacter();
    ////        modifiers       ////
};

#endif