# SDLEngine

Note: This project is under development, and hence is unstable.

An attempt to build a 2D game engine from scratch using C++ and SDL.

Considering the different core structures of various Game Engines, and their pros and cons, I decided to move ahead with Entity Component System (ECS) for the basic structure of the 2D Game Engine.

The development and implementation of various Engine components have been done in the given order:-
1. Framing a basic logic for a game loop (Input->Update->Render cycle). ✔️
2. Configuring SDL Binaries for proper compatibility with the engine. ✔️
3. Simple Draw Test. ✔️
4. Implementing the concept of deltaTime for frame independent updates. ✔️
5. Handling inputs (keyboard only, till now). ✔️
6. Implementing the Entity Class, and an Entity Manager Class. ✔️
7. Creating components (Transform, Rigidbody, Sprite, InputHandler, Animation, Tile Components until now; more will be added) ✔️
8. Implementing classes for Texture Management, and Asset Management. ✔️
9. Implementing a map class for tile based map generation using a text file. ✔️
10. Implementing a camera (logic not working properly currently). ❌

Source codes are available in the src folder. Continous additions and improvements, as well as bug fixes will be done by me whenever I get time.

I am also working on a documentation for this game engine, so that willing contributors as well as developers can extend functionalities of this engine later.
