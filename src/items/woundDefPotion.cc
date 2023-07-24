#include "woundDefPotion.h"

 WoundDefPotion::WoundDefPotion(Player* p) : ItemDecorator(p) {
    target = p;
 }


WoundDefPotion::~WoundDefPotion(){
    
} 

void WoundDefPotion::update() {
    target->setDef(target->getDef() - 5);
}
