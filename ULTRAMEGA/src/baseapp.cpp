#include "baseapp.h"
#include <SDL.h>

namespace app {

GameApp::~GameApp() = default;

void GameApp::Run() {
  //Initialize();

  Uint32 time = SDL_GetTicks();

  for (bool exit = false; !exit && !is_over_;) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          exit = true;
          break;
      }
    }

    Uint32 delta_time = SDL_GetTicks() - time;
    time = SDL_GetTicks();    

    if (delta_time > 0) {
      Update(delta_time);
    }

    ProcessInput(SDL_GetKeyboardState(nullptr));
    SDL_SetRenderDrawColor(render::GetRenderer(), 255, 255, 255, 255);
    SDL_RenderClear(render::GetRenderer());

    Render();

    SDL_RenderPresent(render::GetRenderer());

    SDL_Delay(REFRESH_RATE);
  }

  Free();

  render::FreeAllResources();
}

void GameApp::GameOver() {
  is_over_ = true;
}

}  // namespace app
