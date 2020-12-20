#pragma once
#ifndef RIGIDBODY_COMPONENT_H
#define RIGIDBODY_COMPONENT_H

#include "../ECS_Component.h"
#include "../../libs/glm/glm.hpp"

class ECS_Rigidbody_Component :public ECS_Component
{
public:
	glm::vec2 velocity2D;
	

	ECS_Rigidbody_Component(int velX, int velY);

	void Initialize() override;
	void Update(float deltaTime) override;
	void Render() override;

};

#endif