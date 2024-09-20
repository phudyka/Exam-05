#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <vector>
#include "ASpell.hpp"

class SpellBook {
private:
    std::vector<ASpell*> spells;

    SpellBook(const SpellBook& other);
    SpellBook& operator=(const SpellBook& other);

public:
    SpellBook();
    ~SpellBook();

    void learnSpell(ASpell* spell);
    void forgetSpell(const std::string& spellName);
    ASpell* createSpell(const std::string& spellName);
};

#endif
