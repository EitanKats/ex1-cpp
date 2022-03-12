#include <iostream>
#include "mat.hpp"

using namespace std;
using namespace ariel;

string no_spaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}

int main() {
    string babi = no_spaces(
            "___________________________________________________\n_!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!_\n___________________________________________________");
    string nani = no_spaces(mat(51, 3, '_', '!'));
    cout << nani << endl; // Type a number and press enter
    cout << babi << endl; // Type a number and press enter
    return 0;
}