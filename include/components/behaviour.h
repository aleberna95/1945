#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

typedef struct 
{
    //std
    void* owner;
    void*self;
    //mov
    float speed;
    //dead after
    float death_counter;
    float timeOfDeath;
    //animator
    float animation_duration;
    float counter;
    int num_of_sprites;
    int index;
    int pixel_offset;
}behaviour;

#endif