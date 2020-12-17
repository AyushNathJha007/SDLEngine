#pragma once
#ifndef GAME_H
#define GAME_H

#include<SDL.h>
#include<SDL_ttf.h>
#include<SDL_image.h>

class Game {
private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
public:
	Game();
	~Game();
	bool IsRunning() const;
	void Initialize(int win_width, int win_height);
	void InputProcessing();
	void UpdateGame();
	void Render();
	void Destroy();
};

#endif
