#include "poisonHP.h"

void PoisonHealthPotion::update() {
    target->setHP(target->getHP() - 10);
}
