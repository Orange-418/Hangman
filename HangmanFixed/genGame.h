#ifndef GENGAME_H
#define GENGAME_H
#include <string>

class genGame{
    public:
        void genPhrase();
        std::string getPhrase() const;

    private:
        std::string phrase;
        int randnumb;
};

#endif
