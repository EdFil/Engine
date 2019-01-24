#include "Engine.hpp"

int main(int argc, char* argv[])
{
    Engine* engine = new Engine();
    if(engine->initialize()) {
        engine->run();
    }

    return 0;
}