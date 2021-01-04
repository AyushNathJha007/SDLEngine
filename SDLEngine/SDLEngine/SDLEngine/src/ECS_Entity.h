#pragma once
#ifndef ECS_ENTITY_H
#define ECS_ENTITY_H

#include<map>
#include<vector>
#include<string>
#include "./Constants.h"
#include "./ECS_Component.h"
#include "./ECS_EntityManager.h"
using namespace std;

class ECS_EntityManager;
class ECS_Component;

class ECS_Entity {
private:
	vector<ECS_Component*> components;
	ECS_EntityManager &EntityManager;
	map<const type_info*, ECS_Component*> componentID_Map;
	bool isActive;
public:
	string name;
	Layer layer;
	ECS_Entity(ECS_EntityManager &EntityManager);
	ECS_Entity(ECS_EntityManager &EntityManager,string name,Layer layer);
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
		componentID_Map[&typeid(*newComponent)] = newComponent;
		newComponent->Initialize();
		return *newComponent;
	}

	template<typename T>
	T* GetComponent()
	{
		return static_cast<T*>(componentID_Map[&typeid(T)]);
	}
};

#endif
