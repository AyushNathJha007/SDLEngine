
#include "ECS_Rigidbody_Component.h"

ECS_Rigidbody_Component::ECS_Rigidbody_Component(int velX, int velY)
{
	velocity2D = glm::vec2(velX, velY);
}

void ECS_Rigidbody_Component::Initialize()
{
}

void ECS_Rigidbody_Component::Update(float deltaTime)
{
}

void ECS_Rigidbody_Component::Render()
{
}
