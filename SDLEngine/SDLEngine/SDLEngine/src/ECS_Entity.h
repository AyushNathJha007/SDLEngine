#pragma once
#ifndef ECS_ENTITY_H
#define ECS_ENTITY_H

#include<vector>
#include<string>
#include "./ECS_Component.h"
#include "./ECS_EntityManager.h"
using namespace std;

class ECS_EntityManager;
class ECS_Component;

class ECS_Entity {
private:
	vector<ECS_Component*> components;
	ECS_EntityManager &EntityManager;
	bool isActive;
public:
	string name;
	ECS_Entity(ECS_EntityManager &EntityManager);
	ECS_Entity(ECS_EntityManager &EntityManager,string name);
	void Update(float deltaTime);
	void Render();
	void Destroy();
	bool IsActive() const;

	template<typename T, typename... TArgs>
	T& AddComponent(TArgs&&... args)
	{
		T* newComponent(new T(std::forward<TArgs>(args)...));
		newComponent->owner = this;
		components.emplace_back(newComponent);
		newComponent->Initialize();
		return *newComponent;
	}
};

#endif
