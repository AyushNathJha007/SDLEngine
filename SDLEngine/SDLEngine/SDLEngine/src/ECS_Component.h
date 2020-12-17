#pragma once
#ifndef ECS_COMPONENT_H
#define ECS_COMPONENT_H

class ECS_Component {
public:
	ECS_Entity *owner;
	virtual ~ECS_Component() {}
	virtual void Initialize() {}
	virtual void Update(float deltaTime) {}
	virtual void Render() {}
};

#endif