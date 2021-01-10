#ifndef SHOOT_MANAGER_H
#define SHOOT_MANAGER_H
#include "queue.h"
#include "gameObject.h"

typedef struct 
{
    gameObject* owner;
    queue* active_bullets;
    queue* deactive_bullets;
    float bulletSpeed;
}shootManager ;

shootManager* new_bulletsBehaviour(gameObject* owner, float bulletSpeed);
void shoot(shootManager* shootMgr);
void enqueueBullet(shootManager* shootMgr);
void dequeueBullet(shootManager* shootMgr);
#endif