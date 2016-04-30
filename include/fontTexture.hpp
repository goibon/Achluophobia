#ifndef FONT_TEXTURE
#define FONT_TEXTURE
#include "texture.hpp"
#include <SDL_ttf.h>

class FontTexture : public Texture {
private:
  TTF_Font* mFont;
  void createTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface);
public:
  FontTexture (int width, int height, TTF_Font* font);

  bool loadFromFile(std::string text, SDL_Renderer* renderer, SDL_Color textColor);
  bool loadFromFile(std::string text, SDL_Renderer* renderer, SDL_Color textColor, SDL_Color backgroundColor);
};

#endif
