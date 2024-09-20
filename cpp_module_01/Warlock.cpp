#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : name(name), title(title) {
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
    std::cout << name << ": My job here is done!" << std::endl;
    for (std::vector<ASpell*>::iterator it = spells.begin(); it != spells.end(); ++it) {
        delete *it;
    }
    spells.clear();
}

const std::string& Warlock::getName() const {
    return name;
}

const std::string& Warlock::getTitle() const {
    return title;
}

void Warlock::setTitle(const std::string& title) {
    this->title = title;
}

void Warlock::introduce() const {
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell) {
    if (spell) {
        for (std::vector<ASpell*>::iterator it = spells.begin(); it != spells.end(); ++it) {
            if ((*it)->getName() == spell->getName())
                return;
        }
        spells.push_back(spell->clone());
    }
}

void Warlock::forgetSpell(const std::string& spellName) {
    for (std::vector<ASpell*>::iterator it = spells.begin(); it != spells.end(); ++it) {
        if ((*it)->getName() == spellName) {
            delete *it;
            spells.erase(it);
            return;
        }
    }
}

void Warlock::launchSpell(const std::string& spellName, const ATarget& target) {
    for (std::vector<ASpell*>::iterator it = spells.begin(); it != spells.end(); ++it) {
        if ((*it)->getName() == spellName) {
            (*it)->launch(target);
            return;
        }
    }
}
