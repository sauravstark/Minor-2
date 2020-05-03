#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "renderer.hpp"
#include <SDL.h>
#include <vector>

class Window {
private:
	SDL_Window* window;
    Renderer* renderer;
public:
    Window();
    void update();
    void draw(std::vector<Vertex> &vertices);
};

Window::Window() {
    SDL_CreateWindowAndRenderer(1920, 1080, 0, &window, nullptr);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    GLCall(std::cout << glGetString(GL_VERSION) << std::endl);

    renderer = new Renderer();
}

void Window::update() {

}

void Window::draw(std::vector<Vertex> &vertices) {
    renderer->draw(vertices);
    SDL_GL_SwapWindow(window);
}

#endif //!WNDOW_HPP