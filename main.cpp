#include <iostream>
#include "mat.hpp"
#include <cstring>

using namespace std;
using namespace ariel;

const int exitChar = -1;
const int rugCreation = 1;
const int rowsArgIdx = 2;
const int colsArgIdx = 1;
const int color1ArgIdx = 3;
const int color2ArgIdx = 4;


void handleRugInput() {
    int rows, columns;
    char color1, color2;
    cout << "enter rug size" << endl;
    cin >> rows >> columns;
    cout << "enter rug colors" << endl;
    cin >> color1 >> color2;
    cout << "Your rug :\n" << mat(columns, rows, color1, color2) << endl;
    return;
}

void startShopLoop() {
    cout << "press 1 to customize or -1 to confirm your order" << endl;
    int action;
    while (cin) {

        cin >> action;
        if (action == exitChar) {
            return;
        }
        if (action == rugCreation) {
            cout << "enter rug colors";
            handleRugInput();
            cout << "press 1 to customize or -1 to confirm your order" << endl;
        }
    }
}

int main(int argc, char **argv) {

    int columns, rows;
    char color1, color2;

    try {
        if (argc == 1) {
            startShopLoop();
            return 0;
        }
        if (argc < 5) {
            cout << "You have entered " << argc - 1 << " arguments:" << endl;
            cout << "Please provide 4 valid arguments" << endl;
            return 1;
        }
        columns = atoi(argv[colsArgIdx]);
        rows = atoi(argv[rowsArgIdx]);
        if (strlen(argv[3]) > 1 || strlen(argv[4]) > 1) {
            cout << "The arguments provided are in the wrong format" << endl;
            return 1;
        }
        color1 = argv[color1ArgIdx][0];
        color2 = argv[color2ArgIdx][0];

        cout << mat(columns, rows, color1, color2) << endl;
    } catch (exception &ex) {
        cout << ex.what() << endl;
        return 1;
    }

    return 0;
}