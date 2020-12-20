#include "ECS_EntityManager.h"


void ECS_EntityManager::Update(float deltaTime)
{
	for (auto& entity : EntityList)
	{
		entity->Update(deltaTime);
	}
}

void ECS_EntityManager::Render()
{
	for (auto& entity : EntityList)
	{
		entity->Render();
	}
}

bool ECS_EntityManager::HasNoEntities()
{
	return EntityList.size()==0;
}

ECS_Entity & ECS_EntityManager::AddEntity(std::string name)
{
	ECS_Entity *entity = new ECS_Entity(*this, name);
	EntityList.emplace_back(entity);
	return *entity;
}

std::vector<ECS_Entity*> ECS_EntityManager::GetEntities() const
{
	return EntityList;
}

unsigned int ECS_EntityManager::GetEntityCount()
{
	return EntityList.size();
}

void ECS_EntityManager::ClearData()
{
	for (auto& entity : EntityList)
	{
		entity->Destroy();
	}
}










