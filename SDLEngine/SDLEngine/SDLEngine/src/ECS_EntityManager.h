#pragma once
#ifndef ECS_ENTITY_MANAGER_H
#define ECS_ENTITY_MANAGER_H

#include "./ECS_Entity.h"
//#include "./ECS_Component.h"
#include <vector>
#include <string>
class ECS_Entity;

class ECS_EntityManager
{
private:
	std::vector<ECS_Entity*> EntityList;
public:
	void Update(float deltaTime);
	void Render();
	bool HasNoEntities();
	ECS_Entity& AddEntity(std::string name, Layer layer);
	std::vector<ECS_Entity*> GetEntities() const;
	std::vector<ECS_Entity*> GetEntitiesByLayer(Layer layer) const;
	unsigned int GetEntityCount();
	void ClearData();

};


#endif
