#include "ECS_EntityManager.h"
#include "Collision.h"
#include "./Components/ECS_Collider_Component.h"


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

std::string ECS_EntityManager::CheckEntityCollisions(ECS_Entity & entity) const
{
	ECS_Collider_Component* myCollider = entity.GetComponent<ECS_Collider_Component>();
	for (auto& entities : EntityList)
	{
		if (entities->name.compare(entity.name) != 0&&entities->name.compare("Tiles")!=0)
		{
			if (entities->HasComponent<ECS_Collider_Component>())
			{
				ECS_Collider_Component* otherCollider = entities->GetComponent<ECS_Collider_Component>();
				if (Collision::CheckCollisonAABB(myCollider->collider, otherCollider->collider))
					return otherCollider->colliderTag;
			}
		}
	}
	return std::string();
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










