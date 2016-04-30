#include "fontTexture.hpp"
#include <SDL2/SDL_ttf.h>

FontTexture::FontTexture(int width, int height, TTF_Font* font) : Texture(width, height)
{
  mFont = font;
}

void FontTexture::createTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface)
{
  //Create texture from surface pixels
  mTexture = SDL_CreateTextureFromSurface(renderer, surface);
  if(mTexture == NULL)
  {
    printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
  }
  else
  {
    //Get image dimensions
    mWidth = surface->w;
    mHeight = surface->h;
  }
  //Get rid of old surface
  SDL_FreeSurface(surface);
}

bool FontTexture::loadFromFile(std::string text, SDL_Renderer* renderer, SDL_Color textColor)
{
  //Get rid of preexisting texture
  free();

  //Success flag
  bool success = true;

  //Render text surface
  SDL_Surface* textSurface = TTF_RenderText_Blended( mFont, text.c_str(), textColor);
  if(textSurface == NULL)
  {
    printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
  }
  else
  {
    createTextureFromSurface(renderer, textSurface);
  }
  //Return success
  return mTexture != NULL;
}

bool FontTexture::loadFromFile(std::string text, SDL_Renderer* renderer, SDL_Color textColor, SDL_Color backgroundColor)
{
  //Get rid of preexisting texture
  free();

  //Success flag
  bool success = true;

  //Render text surface
  SDL_Surface* textSurface = TTF_RenderText_Shaded( mFont, text.c_str(), textColor, backgroundColor );
  if(textSurface == NULL)
  {
    printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
  }
  else
  {
    createTextureFromSurface(renderer, textSurface);
  }
  //Return success
  return mTexture != NULL;
}
