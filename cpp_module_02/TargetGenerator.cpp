#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
    for (std::vector<ATarget*>::iterator it = targets.begin(); it != targets.end(); ++it)
        delete *it;
    targets.clear();
}

void TargetGenerator::learnTargetType(ATarget* target) {
    if (target) {
        for (std::vector<ATarget*>::iterator it = targets.begin(); it != targets.end(); ++it) {
            if ((*it)->getType() == target->getType())
                return;
        }
        targets.push_back(target->clone());
    }
}

void TargetGenerator::forgetTargetType(const std::string& targetType) {
    for (std::vector<ATarget*>::iterator it = targets.begin(); it != targets.end(); ++it) {
        if ((*it)->getType() == targetType) {
            delete *it;
            targets.erase(it);
            return;
        }
    }
}

ATarget* TargetGenerator::createTarget(const std::string& targetType) {
    for (std::vector<ATarget*>::iterator it = targets.begin(); it != targets.end(); ++it) {
        if ((*it)->getType() == targetType)
            return (*it)->clone();
    }
    return NULL;
}
