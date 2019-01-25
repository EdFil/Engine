#include "Engine.hpp"

int main()
{
    Engine* engine = new Engine();
    if(engine->initialize()) {
        engine->run();
    }

    return 0;
}