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
	/*for (auto& entity : EntityList)
	{
		entity->Render();
	}*/
	
	//Layer wise rendering
	for (int layernum = 0; layernum < NUM_LAYERS; layernum++)
	{
		for (auto& entity : GetEntitiesByLayer(static_cast<Layer>(layernum)))
		{
			entity->Render();
		}
	}
}

bool ECS_EntityManager::HasNoEntities()
{
	return EntityList.size()==0;
}

ECS_Entity & ECS_EntityManager::AddEntity(std::string name,Layer layer)
{
	ECS_Entity *entity = new ECS_Entity(*this, name, layer);
	EntityList.emplace_back(entity);
	return *entity;
}

std::vector<ECS_Entity*> ECS_EntityManager::GetEntities() const
{
	return EntityList;
}

std::vector<ECS_Entity*> ECS_EntityManager::GetEntitiesByLayer(Layer layer) const
{
	std::vector<ECS_Entity*> layerEntities;
	for (auto& entity : EntityList)
	{
		if (entity->layer == layer)
			layerEntities.emplace_back(entity);
	}
	return layerEntities;
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










