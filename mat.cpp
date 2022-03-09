//
// Created by eitan on 03/03/2022.
//
#include "mat.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using std::vector;
using std::isspace;
namespace ariel {

    void validateDimensions(int columns, int rows) {
        //the separation of the if statements is for readability
        if (columns < 1 || rows < 1) {
            throw std::invalid_argument("Mat size is always odd and positive");
        }
        if (columns % 2 == 0 || rows % 2 == 0) {
            throw std::invalid_argument("Mat size is always odd");
        }
    }

    void validateColors(char color1, char color2) {
        if (color1 == '\0' || color2 == '\0' || isspace(color1) || isspace(color2)) {
            throw std::invalid_argument("colors are either whitespace or null characters");
        }
    }

    string mat(int columns, int rows, char color1, char color2) {

        validateDimensions(columns, rows);
        validateColors(color1, color2);
        string matAsStr;
        vector<vector<char> > myVector(rows, vector<char>(columns));

        int minDimension = columns > rows ? rows : columns;
        int counter = 0;

        while (counter < minDimension) {
            char currColor = counter % 2 == 0 ? color1 : color2;
            for (int j = counter; j < columns - counter; ++j) {
                myVector[counter][j] = currColor;
                myVector[(rows - 1) - counter][j] = currColor;
            }
            for (int j = counter; j < rows - counter; ++j) {
                myVector[j][counter] = currColor;
                myVector[j][(columns - 1) - counter] = currColor;

            }
            counter++;
        }

        for (int r = 0; r < rows; ++r) {
            for (int col = 0; col < columns; ++col) {
                matAsStr += myVector[r][col];
            }
            if (r < rows - 1) {
                matAsStr += "\n";

            }
        }
        return matAsStr;
    }


}

