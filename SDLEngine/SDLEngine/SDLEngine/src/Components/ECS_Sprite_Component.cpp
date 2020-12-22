#include "ECS_Sprite_Component.h"

ECS_Sprite_Component::ECS_Sprite_Component(std::string filePath)
{
	SetTexture(filePath);
}

void ECS_Sprite_Component::SetTexture(std::string TextureID)
{
	texture = Game::assetManager->GetTexture(TextureID);
}

void ECS_Sprite_Component::Initialize()
{
	transform = owner->GetComponent<ECS_Transform_Component>();
	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = transform->width;
	sourceRect.h = transform->height;
}

void ECS_Sprite_Component::Update(float deltaTime)
{
	destRect.x = (int)transform->position2D.x;
	destRect.y = (int)transform->position2D.y;
	destRect.w = transform->width*transform->scale;
	destRect.h= transform->height*transform->scale;
}

void ECS_Sprite_Component::Render()
{
	ECS_TextureManager::Draw(texture, sourceRect, destRect, flip);
}




