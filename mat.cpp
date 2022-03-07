//
// Created by eitan on 03/03/2022.
//
#include "mat.hpp"
#include <iostream>
#include <stdexcept>


namespace ariel {

    void test(char **mat, int leftIdx, int rightIdx, int upIdx, int lowIdx, char color1, char color2) {
        for (int j = leftIdx; j < rightIdx; ++j) {
            mat[lowIdx][j] = '3';
            mat[upIdx - 1][j] = '3';
        }
        for (int i = lowIdx; i < upIdx; ++i) {
            mat[i][leftIdx] = '3';
            mat[i][rightIdx - 1] = '3';

        }


    }

    string mat(int columns, int rows, char color1, char color2) {

//        if (columns % 2 == 0 || rows % 2 == 0) {
//            throw std::invalid_argument("Mat size is always odd");
//        }

        string matAsStr;

//        char **mati = new char *[rows];
//        for (int r = 0; r < rows; ++r) {
//            mati[r] = new char[columns];
//        }
//
//        for (int r = 0; r < rows; ++r) {
//            for (int col = 0; col < columns; ++col) {
//                mati[r][col] = color1;
//            }
//        }

//        test(mati, 0, columns, rows, 0, color1, color2);
//
//        for (int r = 0; r < rows; ++r) {
//            for (int col = 0; col < columns; ++col) {
//                matAsStr += mati[r][col];
//            }
//            matAsStr += "\n";
//        }

//        std::cout << matAsStr << std::endl;
        return matAsStr;
    }

}

