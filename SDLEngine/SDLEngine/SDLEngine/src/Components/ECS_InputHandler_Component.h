/*Todo:- 
Create a flexible input handler such that users can define their own input bindings, apart from the ones given here*/

#pragma once
#ifndef ECS_INPUTHANDLER_COMPONENT_H
#define ECS_INPUTHANDLER_COMPONENT_H

#include "../ECS_Component.h"
#include "../Game.h"
#include "./ECS_Sprite_Component.h"
#include "./ECS_Transform_Component.h"
#include "./ECS_Rigidbody_Component.h"
#include <map>
#include <string>

class ECS_InputHandler_Component :public ECS_Component
{
public:
	/*Basic keyboard bindings*/
	map<std::string, std::string> keyboardMapping;

	/*Add mouse bindings*/
	map<std::string, std::string> mouseMapping;

	/*Add gamepad bindings*/
	map<std::string, std::string> gamepadMapping;

	/*For storing the components which may get influenced by input provided*/
	ECS_Transform_Component *transform;
	ECS_Rigidbody_Component *rb2d;
	ECS_Sprite_Component *sprite;

	ECS_InputHandler_Component();
	ECS_InputHandler_Component(map<std::string, std::string> keyboardMapping, map<std::string, std::string> mouseMapping, map<std::string, std::string> gamepadMapping);
	void Initialize() override;
	void Update(float deltaTime) override;
	void Render() override;
};

#endif
