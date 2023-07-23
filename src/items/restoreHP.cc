#include "restoreHP.h"

void RestoreHealthPotion::update() {
    target->setHP(target->getHP() + 10);
}
