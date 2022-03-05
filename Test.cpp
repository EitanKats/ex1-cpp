//
// Created by eitan on 03/03/2022.
//

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

TEST_CASE("Bad numbers supplied"){
    CHECK_THROWS(mat(10, 5, '$', '%'));
}