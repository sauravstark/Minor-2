#include <functional>
#include <emscripten.h>

#include "includes/game.hpp"

std::function<void()> loop;
void main_loop() { loop(); }

int main()
{

	Game game;

    loop = [&]
    {
      game.updateTimeStep();
      game.Update();
      game.LateUpdate();
      game.Draw();
    };

    emscripten_set_main_loop(main_loop, 0, true);

    return EXIT_SUCCESS;
}
