#pragma once
#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "../ECS_Component.h"
#include "ECS_Rigidbody_Component.h"
#include "../../libs/glm/glm.hpp"

class ECS_Transform_Component :public ECS_Component
{
public:
	glm::vec2 position2D;
	glm::vec2 velocity2D;
	int width;
	int height;
	int scale;

	ECS_Transform_Component(int posX, int posY, int w, int h, int s, ECS_Rigidbody_Component rigidbody2D);

	void Initialize() override;
	void Update(float deltaTime) override;
	void Render() override;

};

#endif // !TRANSFORM_COMPONENT_H


