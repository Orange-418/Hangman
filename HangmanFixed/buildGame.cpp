#include "buildGame.h"
#include "genGame.h"
#include <iostream>
#include <vector>

//things to do:
//- set users input to all lowercase
//- add a toggle option for test mode to display the word being used
//- add an actual hangman character instead of a lives left line
//- break up the functions into class files
//- optimize code
//- when game ends, offer option to quit or play again

void buildGame::writeChars(std::vector<char>& charsRef){    //converts the phraseCopy string into a vector, in case a vector is wanted over a string
    for (int x = 0; x != phraseCopy.size(); ++x){
        charsRef.push_back(phraseCopy[x]);
    }
}


void buildGame::correct(std::vector<char>& correctInputsRef){   //when a correct letter is hit, adds it to the correctInputs
	correctInputsRef.push_back(userAnswer[0]);
}


void buildGame::genInfo(){
    std::cout << "Playing with phrase: " << phraseCopy << std::endl;    //generates the info to display to the user
}


void buildGame::buildCharLine(std::vector<std::string>& charLineRef){   //builds the character line according to # of words left
    for(int x = 0; x < phraseCopy.length(); ++x){
        charLineRef.push_back("__ ");
    }
}


void buildGame::editCharLine(std::vector<std::string>& charLineRef){    //allows for the editing of the charLine, through references
    for(int x = 0; x < phraseCopy.length(); ++x){
        if(charList[x] == userAnswer[0]){
            charLineRef[x] = userAnswer+" ";
        }
    }
}


bool buildGame::checkDouble(){     //checks to see if the user has already used that character (only checks correct, not incorrect yet)
    if(!correctInputs.empty()){
        for (int x = 0; x < correctInputs.size(); ++x){
            if (correctInputs[x] == userAnswer[0]) {
                std::cout << "You already guessed that letter correct!" << std::endl;
                return true;
            }

        }
    }
    return false;
}


void buildGame::gui(){      //builds the gui for the user. This consists of the number of lives and letters remaining
    for (int x = 0; x < phraseCopy.size(); ++x){
        std::cout << charLine[x];
    }
    std::cout << " [" << phraseCopy.length()-correctInputs.size() << "] letters, "
    << "[" << lives << "]"
    << " lives left" << std::endl;
    std::cout << "guess a letter: " << std::endl;
}


void buildGame::status(){   //checks the status of the player, to see if he can continue the game
    if (lives == 0){
        loseGame();
    }
    if(correctInputs.size()==phraseCopy.length()){
        winGame();
    }
    if (userAnswer.size() > 1){
        if (userAnswer == phraseCopy) {
            winGame();
        }
        else{
            loseGame();
        }
    }
}


void buildGame::loseGame(){     //sequence of events to play when the game is lost
    std::cout << "You lose!" << std::endl;
    lives = 0;
}


void buildGame::winGame(){      //sequence of events to play when the game is won
    std::cout << "You win!" << std::endl;
    lives = 0;
}


void buildGame::check(){    //analyzes the users input
    if(!checkDouble() && userAnswer.length() < 2){     //if no doubles are found and user input is a single character
        for (int x = 0; x != phraseCopy.length(); ++x) {
            if (userAnswer[0] == phraseCopy[x] && !alreadyGuessed) {     //if the user answer is correct, and they haven't guessed this turn, and the input is only 1 char
                for (int z = 0; z < phraseCopy.length(); ++z) {
                    if (phraseCopy[z] == userAnswer[0]) {
                        counter++;      //this is for when a word contains two of the same letters
                    }
                }
                if (counter != 0) {
                    for (int p = 0; p < counter; ++p) {     //adds all the same correct repeating characters to the correctInputs
                        correct(correctInputs);
                    }
                }
                std::cout << userAnswer + " was one of the letters!" << std::endl;
                correctLetter = true;      //gives the user the correctLetter pass
                alreadyGuessed = true;     //user has now already guessed
            }
        }
        if (correctLetter == false) {    //if the letter is incorrect
            std::cout << userAnswer + " was not one of the letters!" << std::endl;
            lives--;
        }
    }
}


void buildGame::gameLoop(){     //keeps the game going in repeat until conditions to end it are met
    while (correctInputs.size() < charList.size() && lives > 0) {
        counter = 0;                ///////////////////////////////////////////////////
        correctLetter = false;      //resets variables back to default for next run////
        alreadyGuessed = false;     ///////////////////////////////////////////////////
        userAnswer.clear();         ///////////////////////////////////////////////////

        gui();  //creates the gui
        std::cin >> userAnswer; //takes user input
        editCharLine(charLine); //updates the charline
        check();    //analyzes user input
        status();   //checks if the player can continue
    }
}


void buildGame::play(const genGame& startGame){     //runs the games core functions in order
    phraseCopyRef = startGame.getPhrase();      //initiates the copy of the phrase variable to be used between functions
    writeChars(charList);   //constructs the character list vector
    genInfo();  //outputs the info for the user
    buildCharLine(charLine);    //builds the character line
    gameLoop(); //runs the game loop
}
