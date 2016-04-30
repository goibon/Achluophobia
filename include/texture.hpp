#ifndef TEXTURE
#define TEXTURE
#include <SDL.h>
#include <string>

class Texture {
protected:
  SDL_Texture* mTexture;

  int mWidth;
  int mHeight;
public:
  Texture (int width, int height);

  ~Texture();

  //Get the texture
  SDL_Texture* getTexture();

  //Get dimensions
  int getWidth();
  int getHeight();

  //Load texture from path
  bool loadFromFile(std::string path, SDL_Renderer* renderer);

  void free();

  void render(SDL_Renderer* renderer, SDL_Rect* srcRect, SDL_Rect* dstrect, double angle = 0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
};

#endif
