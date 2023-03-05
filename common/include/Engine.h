#pragma once

#include <SDL2/SDL.h>
#include <memory>

class Engine
{
  public:
    virtual ~Engine();
    static std::unique_ptr<Engine> sInstance;

    virtual int Run();
    void SetShouldKeepRunning(bool inShouldKeepRunning)
    {
        mShouldKeepRunning = inShouldKeepRunning;
    }
    virtual void HandleEvent(SDL_Event *inEvent);

  protected:
    Engine();

    virtual void DoFrame();

  private:
    int DoRunLoop();

    bool mShouldKeepRunning;
};
