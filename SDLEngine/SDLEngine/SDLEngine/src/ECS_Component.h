#pragma once
#ifndef ECS_COMPONENT_H
#define ECS_COMPONENT_H

#include "./ECS_Entity.h"
 
class ECS_Entity;

class ECS_Component {
public:
	ECS_Entity *owner;
	virtual ~ECS_Component() {}
	virtual void Initialize() {}
	virtual void Update(float deltaTime) {}
	virtual void Render() {}
};

#endif