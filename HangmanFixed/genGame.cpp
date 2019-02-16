#include "genGame.h"
#include <iostream>
#include<time.h>
#include <fstream>

std::string genGame::getPhrase() const{
    return phrase;
}


void genGame::genPhrase(){
    std::cout << "Welcome to hangman!" << std::endl;

    srand(time(0));
    randnumb = rand() % 852 + 1;    //random number to determine which word will be pulled out of 852 words

    std::ifstream wordlist ("wordlist.txt");     //list of hangman words
    if (wordlist.is_open()){

        for (int i = 1; i <= randnumb; i++){

            getline(wordlist, phrase);       //get the word, set it equal to the phrase variable
        }
        wordlist.close();
    }
    std::cin.get();
}

