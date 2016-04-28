#ifndef FONT_TEXTURE
#define FONT_TEXTURE
#include "texture.hpp"
#include <SDL2/SDL_ttf.h>

class FontTexture : public Texture {
private:
  TTF_Font* mFont;
public:
  FontTexture (int width, int height, TTF_Font* font);

  bool loadFromFile(std::string text, SDL_Renderer* renderer, SDL_Color textColor);
};

#endif
