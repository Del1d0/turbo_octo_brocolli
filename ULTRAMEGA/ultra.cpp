#include "src/baseapp.h"
#include <iostream>

class UltraMega : public app::GameApp {
 public:
  UltraMega(int w, int h) : app::GameApp(w, h){};

 private:
  void Initialize() override {
    render::LoadResource("resources/images/apple.png");
  };
  void Render() override{
      render::DrawImage("apple.png", x, y, 100, 200);
  };
  void ProcessInput(const Uint8* keyboard) override {
      if (keyboard[SDL_SCANCODE_RIGHT]) {
          x += speed*1;
      }
      if (keyboard[SDL_SCANCODE_LEFT]) {
          x -= speed*1;
      }
      if (keyboard[SDL_SCANCODE_UP]) {
          y -= speed*1;
      }
      if (keyboard[SDL_SCANCODE_DOWN]) {
          y += speed*1;
      }
  };
  int x = 50;
  int y = 50;
  int speed = 10;
};

#undef main
int main() {
  try {
    UltraMega(800, 800).Run();
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}