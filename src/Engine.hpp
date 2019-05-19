#pragma once

#include <memory>

#include "EventDispatcher.hpp"

struct SDL_Window;
struct SDL_Renderer;
class Scene;
class TextureManager;

class Engine : public ApplicationEventDelegate {
public:
    Engine();

    bool initialize();
    void cleanup();
    void run();
    void setScene(std::unique_ptr<Scene>&& scene);

    TextureManager* textureManager() { return _textureManager.get(); }
    EventDispatcher* eventDispatcher() { return _eventDispatcher.get(); }


    void onQuit() override;

    SDL_Renderer* renderer() const { return _renderer; }

private:
    void mainLoop();

private:
    unsigned _lastGetTicksTime = 0;

    SDL_Window* _window = nullptr;
    SDL_Renderer* _renderer = nullptr;

    std::unique_ptr<Scene> _runningScene;
    std::unique_ptr<TextureManager> _textureManager;
    std::unique_ptr<EventDispatcher> _eventDispatcher;

    bool _isRunning = false;
};