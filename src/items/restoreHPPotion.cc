#include "restoreHPPotion.h"


 RestoreHealthPotion::RestoreHealthPotion(Player* p) : ItemDecorator(p) {

 }

 RestoreHealthPotion::~RestoreHealthPotion(){
    
 }

void RestoreHealthPotion::update() {
    target->setHP(target->getHP() + 10);
}
