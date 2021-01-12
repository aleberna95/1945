#include "bullet.h"

bullet* newBullet(gameObject* self, gameObject* owner){
    bullet* _bullet = (bullet*)malloc(sizeof(bullet));
    _bullet->self = self;
    _bullet->owner = owner;
    return _bullet;
}
