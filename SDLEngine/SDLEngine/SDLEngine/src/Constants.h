#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include<string>
#include<map>

//Window width
const unsigned int WINDOW_WIDTH = 800;

//Window Height
const unsigned int WINDOW_HEIGHT = 600;

//Target FPS
const unsigned int FPS = 60;

//Target Frame Rate
const unsigned int TARGET_FRAME_TIME = 1000 / FPS;

//SDLKeyStringCodes
const std::map<std::string,std::string> SDLKeyStringCode=
{
	{"Up","1073741906"},
	{"Down","1073741905"},
	{"Left","1073741904"},
	{"Right","1073741903"},
	{"Space","32"}
};


//Add Different layers here
enum Layer {
	TILEMAP_LAYER = 0,
	VEGETATION_LAYER = 1,
	ENEMY_LAYER = 2,
	PLAYER_LAYER = 3,
	PROJECTILE_LAYER=4,
	UI_LAYER=5
};

const unsigned int NUM_LAYERS = 6;

#endif