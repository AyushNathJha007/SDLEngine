
#include "ECS_Collider_Component.h"

ECS_Collider_Component::ECS_Collider_Component(std::string colliderTag, int x, int y, int width, int height)
{
	this->colliderTag = colliderTag;
	this->collider = { x,y,width,height };
}

void ECS_Collider_Component::Initialize()
{
	if (owner->HasComponent<ECS_Transform_Component>())
	{
		transform = owner->GetComponent<ECS_Transform_Component>();
		sourceRect = { 0, 0, transform->width, transform->height };
		destRect = { collider.x,collider.y,collider.w,collider.h };
	}
}

void ECS_Collider_Component::Update(float deltaTime)
{
	//The collider follows the object to which it is attached
	collider.x = static_cast<int>(transform->position2D.x);
	collider.y = static_cast<int>(transform->position2D.y);
	collider.h = transform->height*transform->scale;
	collider.w= transform->width*transform->scale;
	destRect.x = collider.x - Game::camera.x;
	destRect.y = collider.y - Game::camera.y;
}
