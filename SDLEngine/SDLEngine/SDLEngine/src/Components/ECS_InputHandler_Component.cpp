#include "./ECS_InputHandler_Component.h"
#include "../Constants.h"

ECS_InputHandler_Component::ECS_InputHandler_Component()
{
	/*Keyboard Mapping, which includes <KeyName,KeyFuncDes>.*/
	/*Proposal->Enumerate all KeyNames so that user can directly assign keys without mapping the SDL bindings.*/
	this->keyboardMapping.emplace("Up", "MoveUp"); 
	this->keyboardMapping.emplace("Down", "MoveDown");
	this->keyboardMapping.emplace("Left", "MoveLeft");
	this->keyboardMapping.emplace("Right", "MoveRight");
	this->keyboardMapping.emplace("Space", "Shoot");
}

ECS_InputHandler_Component::ECS_InputHandler_Component(map<std::string, std::string> keyboardMapping, map<std::string, std::string> mouseMapping, map<std::string, std::string> gamepadMapping)
{
	this->keyboardMapping = keyboardMapping;
	this->mouseMapping = mouseMapping;
	this->gamepadMapping = gamepadMapping;
}

void ECS_InputHandler_Component::Initialize()
{
	transform = owner->GetComponent<ECS_Transform_Component>();
	sprite = owner->GetComponent<ECS_Sprite_Component>();
	rb2d = owner->GetComponent<ECS_Rigidbody_Component>();
}

/*Check for input and perform corresponding action*/
void ECS_InputHandler_Component::Update(float deltaTime)
{
	if (Game::event.type == SDL_KEYDOWN)
	{
		std::string keyCode = std::to_string(Game::event.key.keysym.sym);
		if (keyCode.compare(SDLKeyStringCode.find("Up")->second)==0)
		{
			/* Right now, velocity component associated with transform is being changed*/
			/* Todo:- Update Rigidbody such that only velocity associated with rigidbody is needed to be changed i.e abstract it out completely*/
			transform->velocity2D = glm::vec2(0, -20);
			sprite->PlayAnimation("UpAnimation");
		}
		if (keyCode.compare(SDLKeyStringCode.find("Down")->second)==0)
		{
			transform->velocity2D = glm::vec2(0, 20);
			sprite->PlayAnimation("DownAnimation");
		}
		if (keyCode.compare(SDLKeyStringCode.find("Left")->second)==0)
		{
			transform->velocity2D = glm::vec2(-20, 0);
			sprite->PlayAnimation("LeftAnimation");
		}
		if (keyCode.compare(SDLKeyStringCode.find("Right")->second)==0)
		{
			transform->velocity2D = glm::vec2(20, 0);
			sprite->PlayAnimation("RightAnimation");
		}
		if (keyCode.compare(SDLKeyStringCode.find("Space")->second)==0)
		{

		}
	}
	if (Game::event.type == SDL_KEYUP)
	{
		std::string keyCode = std::to_string(Game::event.key.keysym.sym);
		if (keyCode.compare(SDLKeyStringCode.find("Up")->second)==0)
		{
			transform->velocity2D.y=0;

		}
		if (keyCode.compare(SDLKeyStringCode.find("Down")->second)==0)
		{
			transform->velocity2D.y = 0;
		}
		if (keyCode.compare(SDLKeyStringCode.find("Left")->second)==0)
		{
			transform->velocity2D.x = 0;
		}
		if (keyCode.compare(SDLKeyStringCode.find("Right")->second)==0)
		{
			transform->velocity2D.x = 0;
		}
		if (keyCode.compare(SDLKeyStringCode.find("Space")->second)==0)
		{

		}
	}
}

void ECS_InputHandler_Component::Render()
{

}