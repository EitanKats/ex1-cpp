//
// Created by eitan on 03/03/2022.
//
#include "mat.hpp"
#include <iostream>

namespace ariel {

    void test(char **mat, int leftIdx, int rightIdx, int upIdx, int lowIdx) {
        for (int j = leftIdx; j < rightIdx; ++j) {
            mat[lowIdx][j] = '3';
            mat[upIdx-1][j] = '3';
        }
        for (int i = lowIdx; i < upIdx; ++i) {
            mat[i][leftIdx]='3';
            mat[i][rightIdx-1]='3';

        }


    }

    char **mat(int columns, int rows, char color1, char color2) {
        char **mati = (char **) malloc(sizeof(char *) * rows);
        for (int r = 0; r < rows; ++r) {
            mati[r] = (char *) malloc(sizeof(char) * columns);
        }

        for (int r = 0; r < rows; ++r) {
            for (int col = 0; col < columns; ++col) {
                mati[r][col] = color1;
            }
        }

        test(mati, 0, columns, rows , 0);
        for (int r = 0; r < rows; ++r) {
            for (int col = 0; col < columns; ++col) {
                std::cout << mati[r][col];
            }
            std::cout << "\n";
        }


        return mati;
    }

}

