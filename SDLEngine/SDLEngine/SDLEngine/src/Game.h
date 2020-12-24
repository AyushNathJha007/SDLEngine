#pragma once
#ifndef GAME_H
#define GAME_H

#include<SDL.h>
#include<SDL_ttf.h>
#include<SDL_image.h>

class ECS_AssetManager;

class Game {
private:
	bool isRunning;
	int ticksLastFrame;
	SDL_Window *window;
	
public:
	Game();
	~Game();
	static SDL_Renderer *renderer;
	static ECS_AssetManager* assetManager;
	static SDL_Event event;
	void LoadLevel(int LevelNum);
	bool IsRunning() const;
	void Initialize(int win_width, int win_height);
	void InputProcessing();
	void UpdateGame();
	void Render();
	void Destroy();
};

#endif
