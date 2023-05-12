// Created by Shalev Ben David.
#include "doctest.h"
#include "sources/Team.hpp"
using namespace ariel;

TEST_CASE("Case 1: Point Checks.") {
    Point A (5, 6);
    Point B (-1, -2);
    Point C (1000, -500);
    Point D (-1000, 500);

    CHECK(A.distance(B) == 100 && B.distance(A) == 100);
    CHECK(A.moveTowards());
}

TEST_CASE("Case 2: CowBoy Checks.") {

}