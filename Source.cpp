#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

void pressEnterToContinue() {
    cout << "Press enter to continue...";
    cin.get();
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
        wordCount++;
        for (char c : word) {
            if (!isspace(c)) {
                charCount++;
            }
        }
    }

    cout << "Words: " << wordCount << endl;
    cout << "Characters: " << charCount << endl;
    pressEnterToContinue();
    return 0;
}