#ifndef DISPLAY_H
#define DISPLAY_H
#include <SDL.h>
#include <glew.h>
#include <string>

class Display {
public:
	Display(int widht, int height, std::string title);
	~Display();

	void Swap();
	void Clean_Display(float r, float g, float b, float a);
private:
	SDL_Window* window;
	SDL_GLContext context;
};

#endif