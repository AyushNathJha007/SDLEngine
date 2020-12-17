

#include<iostream>
#include "./Game.h"
#include "./Constants.h"
#include "../libs/glm/glm.hpp"
using namespace std;
/*float projectile_pos_x = 0.0f;
float projectile_pos_y = 0.0f;
float projectile_vel_x = 10.0f;
float projectile_vel_y =10.0f;*/

glm::vec2 projectile_pos = glm::vec2(0.0f, 0.0f);
glm::vec2 projectile_vel = glm::vec2(10.0f, 10.0f);

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
	this->isRunning = true;
	return;
}

void Game::InputProcessing()
{
	SDL_Event event;
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
	projectile_pos += projectile_vel * deltaTime;
}

void Game::Render()
{
	SDL_SetRenderDrawColor(this->renderer, 25, 25, 25, 255);
	SDL_RenderClear(this->renderer);

	SDL_Rect Projectile{
		(int)projectile_pos.x,
		(int)projectile_pos.y,
		10,
		10
	};

	SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(this->renderer, &Projectile);

	SDL_RenderPresent(this->renderer);
}

void Game::Destroy()
{
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}