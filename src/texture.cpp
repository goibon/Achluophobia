#include "texture.hpp"
#include <SDL2/SDL_image.h>

Texture::Texture(int width, int height){
  mWidth = width;
  mHeight = height;
}

Texture::~Texture(){
  free();
}

void Texture::free()
{
  SDL_DestroyTexture(mTexture);
  mTexture = NULL;
}

SDL_Texture* Texture::getTexture()
{
  return mTexture;
}

int Texture::getWidth()
{
  return mWidth;
}

int Texture::getHeight()
{
  return mHeight;
}

bool Texture::loadFromFile(std::string path, SDL_Renderer* renderer)
{
  //Get rid of preexisting texture
  free();

  //Success flag
  bool success = true;

  //The final texture
  SDL_Texture* newTexture = NULL;
  //Load image at specified path
  SDL_Surface* loadedSurface = IMG_Load(path.c_str());

  if (loadedSurface == NULL)
  {
    printf("Unable to load texture %s! SDL_image Error:%s\n", path.c_str(), IMG_GetError());
  }
  else
  {
    //Color key image
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
    //Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if(newTexture == NULL)
    {
      printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
    }
    else
    {
      //Get image dimensions
      mWidth = loadedSurface->w;
      mHeight = loadedSurface->h;
    }
    //Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);
  }
  //Return success
  mTexture = newTexture;
  return mTexture != NULL;
}

void Texture::render(SDL_Renderer* renderer, SDL_Rect* srcRect, SDL_Rect* dstrect, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
  SDL_RenderCopyEx(renderer, mTexture, srcRect, dstrect, angle, center, flip);
}
