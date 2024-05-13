#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

string randword(){
    vector<string> words = {"word", "cplusplus", "python", "javascript"};
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

void display(const string word, const vector<bool> c){
    for(size_t i=0; i < word.length(); i++){
        if(c[i]){
            cout << word[i] << " ";
        }
        else{
            cout << "_ ";
        }
    }
    cout << endl;
}

bool ifletter(char letter, const string secretWord) {
    return secretWord.find(letter) != string::npos;
}


bool ifall(vector<bool> c){
    for(bool i: c){
        if(!i){
            return false;
        }
    }
    return true;
}

int main(){
    cout << "Welcome to the game! Press [Y] to start the game\n";
    re:
    int stage = 0;
    string word = randword();
    const int end = word.length();
    vector<bool> guessed(word.length(), false);

    while(stage < end){
        cout <<"\nWord:";
        display(word, guessed);
        char letter;
        
        cout << "\nPlease guess a letter: ";
        cin >> letter;
        cout << letter << endl;

        if(ifletter(letter, word)){
            cout << "Correct! " << endl;
            for(size_t i=0; i < word.length(); i++){
                if(letter == word[i]){
                    guessed[i] = true;
                }
            }
        } else {
            cout << "Incorrect" << endl;
            stage++;
            cout << "You have " << end-stage << " lives" << endl;
        }

        bool guessedall;
        guessedall = ifall(guessed);

        if(guessedall){
            cout << "You won!\nThe word was: " << word << endl;
            break;
        }


    }
    char x;
    if(stage == end){
        cout << "Imagine losing to such easy game bro \n";
    }
    cout << "Continue?: [Y/N]";
    cin >> x;
    if(x == 'y' || x == 'Y'){
        goto re;
    }
    else{
        system("clear");
    }


    return 0;
}