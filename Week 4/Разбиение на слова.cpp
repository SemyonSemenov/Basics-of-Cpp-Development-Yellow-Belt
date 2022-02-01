#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<string> SplitIntoWords(const string& s) {
    vector<string> words;
    string word;
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (*it == ' ') {
            words.push_back(word);
            word.clear();
        }
        else {
            word += *it;
        }
    }
    words.push_back(word);
    return words;
}

int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}
