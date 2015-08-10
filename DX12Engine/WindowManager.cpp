#include "WindowManager.h"
#include <SDL_syswm.h>

SDL_Window * WindowManager::window_;
int WindowManager::width_;
int WindowManager::height_;
std::string WindowManager::title_;

void WindowManager::Initialize(const char * title, int width, int height, int x, int y)
{
  width_ = width;
  height_ = height;
  title_ = title;

  window_ = SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_SHOWN);
}

void WindowManager::Finalize()
{
  SDL_DestroyWindow(window_);
}

void WindowManager::ChangeTitle(const char * title)
{
  title_ = title;
  SDL_SetWindowTitle(window_, title);
}

HWND WindowManager::GetHandle()
{
  SDL_SysWMinfo info;

  SDL_VERSION(&info.version);
  SDL_GetWindowWMInfo(window_, &info);

  // actual HWND
  return info.info.win.window;
}

//HDC WindowManager::GetDC()
//{
  //return GetDC(WindowManager::GetHandle());
//}

int WindowManager::GetWidth()
{
  return width_;
}

int WindowManager::GetHeight()
{
  return height_;
}

void WindowManager::Message(const char * title, const char * msg)
{
  SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, title, msg, NULL);
}
