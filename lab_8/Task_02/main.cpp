#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool isVowel(char c) {
    string vowels = "aeiouAEIOU";
    return vowels.find(c) != string::npos;
}

bool hasRepeatingVowels(const string &word) {
    for (size_t i = 0; i < word.size(); ++i) {
        if (isVowel(word[i])) {
            for (size_t j = i + 1; j < word.size(); ++j) {
                if (word[j] == word[i]) return true;
            }
        }
    }
    return false;
}

int countVowels(const string &word) {
    int count = 0;
    for (char c : word) {
        if (isVowel(c)) ++count;
    }
    return count;
}

int main() {
    string input;
    cout << "Введите текст: ";
    getline(cin, input);

    vector<string> words;
    string word;
    
    for (char c : input) {
        if (isalpha(c))
            word += c;
        else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty()) words.push_back(word);

    bool condition = false;

    for (const string &w : words) {
        if (hasRepeatingVowels(w)) {
            condition = true;
            break;
        }
    }

    for (string &w : words) {
        if (condition) {
        
            string temp = "";
            for (char c : w) {
                if (isVowel(c)) temp += c;
            }
            w = temp;
        } else {
    
            if (countVowels(w) >= 3) {
                string temp = "";
                for (char c : w) {
                    temp += c;
                    if (isVowel(c)) temp += c;
                }
                w = temp;
            }
        }
    }

    
    sort(words.begin(), words.end());

    cout << "Результат:" << endl;
    for (const string &w : words) {
        cout << w << " ";
    }
    cout << endl;

    return 0;
}
