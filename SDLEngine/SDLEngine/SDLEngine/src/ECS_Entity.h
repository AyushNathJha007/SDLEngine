#pragma once
#ifndef ECS_ENTITY_H
#define ECS_ENTITY_H

#include<vector>
#include<string>
using namespace std;

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
	bool isActive() const;
};

#endif
