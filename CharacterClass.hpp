#ifndef CharacterClass_hpp
#define CharacterClass_hpp


class Character {
    private:
    char character;
    int quantity;
    public:
    //operators
    //functions
    Character(char userInput);
    virtual ~Character();
    //accessors
        //getters
    inline char _getCharacter() const {return character;}
    inline int _getQuantity() const {return quantity;}
        //setters
    inline void _setCharacter(char uInput) {character = uInput;}
    inline void _setQuantity(char uInput) {quantity = uInput;}
    inline void _addQuantity() {quantity+= 1;}
    inline void _subQuantity() {quantity-= 1;}
    //modifiers
};

#endif