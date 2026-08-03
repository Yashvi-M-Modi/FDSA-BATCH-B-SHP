#include <iostream>
using namespace std;
int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    string word = "", longest = "";
    sentence += ' ';
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] != ' ') {
            word += sentence[i];
        } else {
            if (word.length() > longest.length()) {
                longest = word;
            }
            word = "";
        }
    }
    cout << "Longest Word: " << longest << endl;
    cout << "Length: " << longest.length() << endl;
}