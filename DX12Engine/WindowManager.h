#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <SDL.h>
#include <Windows.h>
#include <string>

class WindowManager
{
public:
  static void Initialize(const char * title, int width, int height, int x = 100, int y = 100);
  static void Finalize();

  static void ChangeTitle(const char * title);
  static HWND GetHandle();

  static int GetWidth();
  static int GetHeight();
  //static HDC GetDC();

  static void Message(const char * title, const char * msg);

private:
  static SDL_Window * window_;
  static int width_;
  static int height_;
  static std::string title_;
};
