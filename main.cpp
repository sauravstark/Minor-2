#include <functional>
#include <emscripten.h>

#include "includes/Game/Game.hpp"

std::function<void()> loop;
void main_loop() { loop(); }

int main()
{

	Game game;

    loop = [&]
    {
      game.captureInput();
      game.updateTimeStep();
      game.update();
      game.lateUpdate();
      game.draw();
    };

    emscripten_set_main_loop(main_loop, 0, true);

    return EXIT_SUCCESS;
}
