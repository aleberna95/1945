#include "shootManager.h"
#include "gameObject.h"

shootManager* new_bulletsBehaviour(gameObject* owner, float bulletSpeed)
{
    shootManager* shootMgr = (shootManager*)malloc(sizeof(shootManager));
    shootMgr->active_bullets = createQueue();
    shootMgr->deactive_bullets = createQueue();
    shootMgr->bulletSpeed = bulletSpeed;

    return shootMgr;
}

void shoot(shootManager* shootMgr){
    gameObject* go = dequeue(shootMgr->deactive_bullets);
    enqueue(shootMgr->active_bullets, go);
}

void setUnactiveBullet(shootManager* shootMgr){
    gameObject* go = dequeue(shootMgr->active_bullets);
    enqueue(shootMgr->deactive_bullets, go);
}
