#pragma once
#ifndef ECS_ANIMATION_H
#define ECS_ANIMATION_H

class ECS_Animation
{
public:
	unsigned int index;
	unsigned int numberOfFrames;
	unsigned int animationSpeed;

	ECS_Animation();
	ECS_Animation(unsigned int index, unsigned int numberOfFrames, unsigned int animationSpeed);
};

#endif ECS_ANIMATION_H
