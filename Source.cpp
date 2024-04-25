#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

void pressEnterToContinue() {
    cout << "Press enter to continue...";
    cin.get();
}

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    string filename;
    cout << "input file: ";
    getline(cin, filename);

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file. \n";
        pressEnterToContinue();
        return 1;
    }

    int wordCount = 0;
    int charCount = 0;
    string word;
    while (file >> word) {
        bool hasLetter = false;
        for (char c : word) {
            if (isLetter(c)) {
                charCount++;
                hasLetter = true;
            }
        }
        if (hasLetter) {
            wordCount++;
        }
    }

    cout << "Words: " << wordCount << endl;
    cout << "Characters: " << charCount << endl;
    pressEnterToContinue();
    return 0;
}