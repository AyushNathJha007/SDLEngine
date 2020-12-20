#include "ECS_Transform_Component.h"
#include "ECS_Rigidbody_Component.h"
#include "../../SDL2Libs/include/SDL.h"
#include "../Game.h"

ECS_Transform_Component::ECS_Transform_Component(int posX, int posY, int w, int h, int s, ECS_Rigidbody_Component rigidbody2D)
{
	position2D = glm::vec2(posX, posY);
	velocity2D = rigidbody2D.velocity2D;
	width = w;
	height = h;
	scale = s;
}

void ECS_Transform_Component::Initialize()
{
	
}

void ECS_Transform_Component::Update(float deltaTime)
{
	position2D += velocity2D * deltaTime;
}

void ECS_Transform_Component::Render()
{
	SDL_Rect transformRectangle = {
		(int)position2D.x,
		(int)position2D.y,
		width,
		height
	};
	SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(Game::renderer, &transformRectangle);
}




