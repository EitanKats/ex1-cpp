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
        if (color1 == '\0' || color2 == '\0' || (bool) isspace(color1) || (bool) isspace(color2)) {
            throw std::invalid_argument("colors are either whitespace or null characters");
        }
    }

    string rugMatToStr(vector<vector<char> > myRug, int columns, int rows) {
        string matAsStr;
        for (int r = 0; r < rows; ++r) {
            for (int col = 0; col < columns; ++col) {
                matAsStr += myRug[r][col];
            }
            if (r < rows - 1) {
                matAsStr += "\n";

            }
        }
        return matAsStr;
    }

    string mat(int columns, int rows, char color1, char color2) {

        validateDimensions(columns, rows);
        validateColors(color1, color2);
        vector<vector<char> > myRug(rows, vector<char>(columns));
        int minDimension = columns > rows ? rows : columns;
        int layerNum = 0;

        // the `-1` is used here because otherwise we get an out of bound exception since the indexing starts from 0
        while (layerNum < minDimension) {
            char currColor = layerNum % 2 == 0 ? color1 : color2;
            for (int j = layerNum; j < columns - layerNum; ++j) {
                myRug[layerNum][j] = currColor;
                myRug[(rows - 1) - layerNum][j] = currColor;
            }
            for (int j = layerNum; j < rows - layerNum; ++j) {
                myRug[j][layerNum] = currColor;
                myRug[j][(columns - 1) - layerNum] = currColor;

            }
            layerNum++;
        }

        return rugMatToStr(myRug, columns, rows);
    }

}

