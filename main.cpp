#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random word
string getRandomWord() {
    vector<string> words = {"apple", "banana", "orange", "grape", "pineapple"};
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

// Function to display the current state of the word
void displayWord(const string secretWord, const vector<bool> guessed){
    for(size_t i = 0; i < secretWord.length(); ++i){
        if (guessed[i]) {
            cout << secretWord[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
    }


// Function to check if the letter is in the secret word
bool isLetterInWord(char letter, const string secretWord) {
    return secretWord.find(letter) != string::npos;
}

int main() {
    const int MAX_TRIES = 6;
    string secretWord = getRandomWord();
    vector<bool> guessed(secretWord.length(), false);
    int tries = 0;

    cout << "Welcome to Hangman!" << endl;

    while (tries < MAX_TRIES) {
        cout << "\nGuess the word: ";
        displayWord(secretWord, guessed);

        char guess;
        cout << "Enter a letter: ";
        cin >> guess;

        if (isLetterInWord(guess, secretWord)) {
            cout << "Correct guess!" << endl;
            for (size_t i = 0; i < secretWord.length(); ++i) {
                if (secretWord[i] == guess) {
                    guessed[i] = true;
                }
            }
        } else {
            cout << "Incorrect guess!" << endl;
            ++tries;
            cout << "You have " << MAX_TRIES - tries << " tries left." << endl;
        }

        bool allGuessed = true;
        for (bool letterGuessed : guessed) {
            if (!letterGuessed) {
                allGuessed = false;
                break;
            }
        }

        if (allGuessed) {
            cout << "\nCongratulations! You guessed the word: " << secretWord << endl;
            break;
        }
    }

    if (tries == MAX_TRIES) {
        cout << "\nSorry, you ran out of tries. The word was: " << secretWord << endl;
    }

    return 0;
}
