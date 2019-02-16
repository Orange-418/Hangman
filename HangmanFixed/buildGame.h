#ifndef BUILDGAME_H
#define BUILDGAME_H
#include "genGame.h"
#include <string>
#include <vector>

class buildGame{
    public:
        void play(const genGame &startGame);
        std::vector<char> correctInputs;
        std::string userAnswer;

    private:
        void genInfo();
        void gameLoop();
        void check();
        void status();
        void loseGame();
        void winGame();
        void gui();
        void editCharLine(std::vector<std::string>& charLineRef);
        void buildCharLine(std::vector<std::string>& charLineRef);
        void correct(std::vector<char>& correctInputsRef);
        void writeChars(std::vector<char>& charsRef);
        bool checkDouble();
        bool correctLetter = false;
        bool alreadyGuessed = false;
        bool win = false;
        int charCount;
        int lives = 3;
        int counter = 0;
        std::string phraseCopy;
        std::string& phraseCopyRef = phraseCopy;
        std::vector<std::string> charLine;
        std::vector<char> charList;
        std::vector<char> charsLeftVec();
};

#endif
