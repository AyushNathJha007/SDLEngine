#include <iostream>

#include <SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include<glm/glm.hpp>
#include<imgui/imgui.h>
#include<sol/sol.hpp>
#include"./Game.h"
#include"./Constants.h"

void TestInitialisation()
{
	sol::state lua;
	lua.open_libraries(sol::lib::base);
	glm::vec2 velocity = glm::vec2(2.0, -1.0);
	SDL_Init(SDL_INIT_EVERYTHING);
	std::cout << "Initialisation Success!" << std::endl;
}

int main(int argc, char* argv[]) {

	//TestInitialisation();

	Game *game = new Game();

	game->Initialize(WINDOW_WIDTH, WINDOW_HEIGHT);
	//Game Loop
	while (game->IsRunning())
	{
		game->InputProcessing();
		game->UpdateGame();
		game->Render();
	}

	//if player exits or for any reason game crashes
	game->Destroy();

    return 0;
}
