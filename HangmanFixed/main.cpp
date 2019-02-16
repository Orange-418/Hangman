#include "genGame.h"
#include "buildGame.h"


int main()
{
    genGame startGame;
    buildGame build;
    startGame.genPhrase();
    build.play(startGame);
    return 0;
}
