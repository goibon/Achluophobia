#include "fontTexture.hpp"
#include <SDL2/SDL_ttf.h>

FontTexture::FontTexture(int width, int height, TTF_Font* font) : Texture(width, height)
{
  mFont = font;
}

bool FontTexture::loadFromFile(std::string text, SDL_Renderer* renderer, SDL_Color textColor)
{
  //Get rid of preexisting texture
  free();

  //Success flag
  bool success = true;

  //Render text surface
  SDL_Surface* textSurface = TTF_RenderText_Solid(mFont, text.c_str(), textColor);

  if(textSurface == NULL)
  {
    printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
  }
  else
  {
    //Create texture from surface pixels
    mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if(mTexture == NULL)
    {
      printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
    }
    else
    {
      //Get image dimensions
      mWidth = textSurface->w;
      mHeight = textSurface->h;
    }
    //Get rid of old surface
    SDL_FreeSurface(textSurface);
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
    //Create texture from surface pixels
    mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if(mTexture == NULL)
    {
      printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
    }
    else
    {
      //Get image dimensions
      mWidth = textSurface->w;
      mHeight = textSurface->h;
    }
    //Get rid of old surface
    SDL_FreeSurface(textSurface);
  }
  //Return success
  return mTexture != NULL;
}
