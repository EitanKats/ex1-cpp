#include <iostream>
#include "mat.hpp"
#include <cstring>

using namespace std;
using namespace ariel;

int main(int argc, char **argv) {

    int columns, rows;
    char color1, color2;
    if (argc < 5) {
        cout << "You have entered " << argc - 1 << " arguments:" << endl;
        cout << "Please provide 4 valid arguments" << endl;
    }
    try {
        columns = atoi(argv[1]);
        rows = atoi(argv[2]);
        if (strlen(argv[3]) > 1 || strlen(argv[4]) > 1) {
            cout << "The arguments provided are in the wrong format" << endl;
            return 1;
        }
        color1 = argv[3][0];
        color2 = argv[4][0];

        cout << mat(columns, rows, color1, color2) << endl;
    } catch (exception &ex) {
        cout << ex.what() << endl;
        return 1;
    }

    return 0;
}