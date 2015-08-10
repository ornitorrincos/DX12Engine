#include <SDL.h>

#include "WindowManager.h"
#include "DX12Device.h"

int main(int argc, char *argv[])
{
  WindowManager::Initialize("DX12Engine", 800, 600);
  DX12Device * dev = new DX12Device(true);

  bool quit = false;
  while (!quit)
  {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
      {
        quit = true;
      }
    }

    dev->Render();
  }


  WindowManager::Finalize();
	return 0;
}