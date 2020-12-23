#include "./ECS_Animation.h"

ECS_Animation::ECS_Animation()
{

}

ECS_Animation::ECS_Animation(unsigned int index, unsigned int numberOfFrames, unsigned int animationSpeed)
{
	this->index = index;
	this->numberOfFrames = numberOfFrames;
	this->animationSpeed = animationSpeed;
}