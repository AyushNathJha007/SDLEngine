#include "ECS_Sprite_Component.h"
#include "./ECS_Animation.h"

ECS_Sprite_Component::ECS_Sprite_Component(std::string textureID)
{
	this->isFixedOnScreen = false;
	this->isAnimated = false;
	SetTexture(textureID);
}

ECS_Sprite_Component::ECS_Sprite_Component(std::string textureID, int animSpeed, int numberOfFrames, bool hasDirections, bool isFixedOnScreen)
{
	this->isAnimated = true;
	this->numberOfFrames = numberOfFrames;
	this->animSpeed = animSpeed;
	this->isFixedOnScreen = isFixedOnScreen;

	if (hasDirections)
	{
		ECS_Animation downAnim = ECS_Animation(0, numberOfFrames, animSpeed);
		ECS_Animation rightAnim = ECS_Animation(1, numberOfFrames, animSpeed);
		ECS_Animation leftAnim = ECS_Animation(2, numberOfFrames, animSpeed);
		ECS_Animation upAnim = ECS_Animation(3, numberOfFrames, animSpeed);
		animations.emplace("DownAnimation", downAnim);
		animations.emplace("RightAnimation", rightAnim);
		animations.emplace("leftAnimation", leftAnim);
		animations.emplace("UpAnimation", upAnim);
		//The starting animation index
		this->animationIndex = 0;
		this->currentAnimationName = "DownAnimation";

	}
	else
	{
		ECS_Animation monoAnim = ECS_Animation(0, numberOfFrames, animSpeed);
		animations.emplace("MonoAnim", monoAnim);
		this->animationIndex = 0;
		this->currentAnimationName = "MonoAnim";
	}
	PlayAnimation(this->currentAnimationName);
	SetTexture(textureID);

}

void ECS_Sprite_Component::PlayAnimation(std::string currentAnimName)
{
	numberOfFrames = animations[currentAnimName].numberOfFrames;
	animationIndex = animations[currentAnimName].index;
	animSpeed = animations[currentAnimName].animationSpeed;
	currentAnimationName = currentAnimName;
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
	//For animation
	/*-----It is assumed that different animation frames are laid vertically on the sprite sheet------------*/
	if (isAnimated)
	{
		sourceRect.x = sourceRect.w*static_cast<int>((SDL_GetTicks() / animSpeed) % numberOfFrames);
	}
	sourceRect.y = animationIndex * transform->height;
	//Animation part ends
	destRect.x = (int)transform->position2D.x;
	destRect.y = (int)transform->position2D.y;
	destRect.w = transform->width*transform->scale;
	destRect.h= transform->height*transform->scale;
}

void ECS_Sprite_Component::Render()
{
	ECS_TextureManager::Draw(texture, sourceRect, destRect, flip);
}




