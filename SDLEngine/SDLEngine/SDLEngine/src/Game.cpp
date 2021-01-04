

#include<iostream>
#include "./Game.h"
#include "./Constants.h"
#include "../libs/glm/glm.hpp"
#include "./ECS_EntityManager.h"
#include "./ECS_AssetManager.h"
#include "./Components/ECS_Transform_Component.h"
#include "./Components/ECS_Rigidbody_Component.h"
#include "./Components/ECS_Sprite_Component.h"
#include "./Components//ECS_InputHandler_Component.h"
#include "./Map.h"
using namespace std;
/*float projectile_pos_x = 0.0f;
float projectile_pos_y = 0.0f;
float projectile_vel_x = 10.0f;
float projectile_vel_y =10.0f;*/

//Getting player transform for updating camera
ECS_Transform_Component* playerTransform;

ECS_EntityManager manager;
ECS_AssetManager* Game::assetManager = new ECS_AssetManager(&manager);
SDL_Renderer* Game::renderer;
SDL_Event Game::event;
SDL_Rect Game::camera;
Map* mapp;

//glm::vec2 projectile_pos = glm::vec2(0.0f, 0.0f);
//glm::vec2 projectile_vel = glm::vec2(10.0f, 10.0f);

bool Game::IsRunning() const
{
	return this->isRunning;
}

Game::Game()
{
	this->isRunning = false;
}

Game::~Game()
{

}


ECS_Entity& chopperEntity(manager.AddEntity("Chopper", PLAYER_LAYER));
void Game::LoadLevel(int levelnum)
{
	/*First, load all assets*/
	std::string tank_texture_filePath = "./assets/images/tank-panther-right.png";
	assetManager->AddTexture("Tank_Image", tank_texture_filePath);
	std::string chopper_texture_filePath = "./assets/images/chopper-spritesheet.png";
	assetManager->AddTexture("Chopper_Image", chopper_texture_filePath);
	std::string jungle_tileset_filePath = "./assets/tilemaps/jungle.png";
	assetManager->AddTexture("jungleTiles", jungle_tileset_filePath);

	mapp = new Map("jungleTiles", 2, 32);
	mapp->Map_Load("./assets/tilemaps/jungle.map", 25, 20);

	/*Then, start including assets and components*/
	ECS_Entity& tankEntity(manager.AddEntity("Tank",ENEMY_LAYER));
	ECS_Rigidbody_Component tank_rb2d = tankEntity.AddComponent<ECS_Rigidbody_Component>(20, 20);
	tankEntity.AddComponent<ECS_Transform_Component>(0, 0, 32, 32, 1, tank_rb2d);
	tankEntity.AddComponent<ECS_Sprite_Component>("Tank_Image");

	std::map<std::string, std::string> keyboardMapping, mouseMapping, gamepadMapping;
	keyboardMapping.emplace("Up", "MoveUp");
	keyboardMapping.emplace("Down", "MoveDown");
	keyboardMapping.emplace("Left", "MoveLeft");
	keyboardMapping.emplace("Right", "MoveRight");
	keyboardMapping.emplace("Space", "Shoot");
	
	
	ECS_Rigidbody_Component chopper_rb2d = chopperEntity.AddComponent<ECS_Rigidbody_Component>(0, 0);
	chopperEntity.AddComponent<ECS_Transform_Component>(100, 200, 32, 32, 1, chopper_rb2d);
	//playerTransform = chopperEntity.GetComponent<ECS_Transform_Component>();
	chopperEntity.AddComponent<ECS_Sprite_Component>("Chopper_Image",90,2,true,false);
	chopperEntity.AddComponent<ECS_InputHandler_Component>(keyboardMapping, mouseMapping, gamepadMapping);
}

void Game::Initialize(int win_width,int win_height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cerr << "Error: SDL Initialization Failed!" << endl;
		return;
	}
	this->window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win_width, win_height, SDL_WINDOW_BORDERLESS);
	if (this->window == NULL)
	{
		cerr << "Error: Window couldn't be created." << endl;
		return;
	}
	this->renderer = SDL_CreateRenderer(this->window, -1, 0);
	if (this->renderer == NULL)
	{
		cerr << "Error: Renderer couldn't be setup." << endl;
		return;
	}

	//If everything above works alright, we can start game loop
	LoadLevel(0);
	this->isRunning = true;
	return;
}

void Game::InputProcessing()
{
	//SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT: this->isRunning = false;
		break;
	case SDL_KEYDOWN: if (event.key.keysym.sym == SDLK_ESCAPE)
		this->isRunning = false;
	default:
		break;


	}
}

void Game::UpdateGame()
{
	//while (!SDL_TICKS_PASSED(SDL_GetTicks(), this->ticksLastFrame + TARGET_FRAME_TIME));

	int timeToWait = TARGET_FRAME_TIME - (SDL_GetTicks() - this->ticksLastFrame);

	if (timeToWait > 0 && timeToWait < TARGET_FRAME_TIME)
	{
		SDL_Delay(timeToWait);
	}

	float deltaTime = (SDL_GetTicks() - this->ticksLastFrame) / 1000.0f;
	//Clamp DeltaTime
	deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;
	this->ticksLastFrame = SDL_GetTicks();
	/*projectile_pos_x += projectile_vel_x*deltaTime;
	projectile_pos_y += projectile_vel_y*deltaTime;*/
	//projectile_pos += projectile_vel * deltaTime;
	manager.Update(deltaTime);
	HandleCameraUpdate();
}

void Game::Render()
{
	SDL_SetRenderDrawColor(this->renderer, 25, 25, 25, 255);
	SDL_RenderClear(this->renderer);

	/*SDL_Rect Projectile{
		(int)projectile_pos.x,
		(int)projectile_pos.y,
		10,
		10
	};

	SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(this->renderer, &Projectile);*/

	if (manager.HasNoEntities())
		return;

	manager.Render();

	SDL_RenderPresent(this->renderer);
}

void Game::HandleCameraUpdate()
{
	playerTransform = chopperEntity.GetComponent<ECS_Transform_Component>();
	camera.x = playerTransform->position2D.x - (WINDOW_WIDTH / 2);
	camera.y= playerTransform->position2D.y - (WINDOW_HEIGHT / 2);
	
	//Clamping camera view
	camera.x = camera.x < 0 ? 0 : camera.x;
	camera.y = camera.y < 0 ? 0 : camera.y;
	camera.x = camera.x > camera.w ? camera.w : camera.x;
	camera.y = camera.y > camera.h ? camera.h : camera.y;

}

void Game::Destroy()
{
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}