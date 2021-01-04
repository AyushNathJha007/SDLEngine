
#include "ECS_Entity.h"
#include "ECS_EntityManager.h"

ECS_Entity::ECS_Entity(ECS_EntityManager & EntityManager) : EntityManager(EntityManager)
{
	this->isActive = true;
}

ECS_Entity::ECS_Entity(ECS_EntityManager & EntityManager, std::string name,Layer layer):EntityManager(EntityManager),name(name),layer(layer)
{
	this->isActive = true;
}

void ECS_Entity::Update(float deltaTime)
{
	for (auto& component:components)
	{
		component->Update(deltaTime);
	}
}

void ECS_Entity::Render()
{
	for (auto& component : components)
	{
		component->Render();
	}
}

void ECS_Entity::Destroy()
{
	this->isActive = false;
}

bool ECS_Entity::IsActive() const
{
	return this->isActive;
}