#include <RoboCatClientPCH.h>
#include <SDL2/SDL_image.h>

std::unique_ptr<TextureManager> TextureManager::sInstance;

void TextureManager::StaticInit()
{
    sInstance.reset(new TextureManager());
}

TextureManager::TextureManager()
{
    const char *prefix = "/home/erik/prog/cpp/multiplayer/chapter-6/robo-cat-action/res/sprites/";
    CacheTexture("cat", (std::string(prefix) + "cat.png").c_str());
    CacheTexture("mouse", (std::string(prefix) + "mouse.png").c_str());
    CacheTexture("yarn", (std::string(prefix) + "yarn.png").c_str());
}

TexturePtr TextureManager::GetTexture(const string &inTextureName)
{
    return mNameToTextureMap[inTextureName];
}

bool TextureManager::CacheTexture(string inTextureName, const char *inFileName)
{
    SDL_Texture *texture = IMG_LoadTexture(GraphicsDriver::sInstance->GetRenderer(), inFileName);

    if (texture == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to load texture: %s", inFileName);
        return false;
    }

    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);

    // Set the blend mode up so we can apply our colors
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);

    TexturePtr newTexture(new Texture(w, h, texture));

    mNameToTextureMap[inTextureName] = newTexture;

    return true;
}
