// Created by Shalev Ben David.
#include "doctest.h"
#include "sources/Team.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("Case 1: Point Checks.") {
    Point A (5, 6);
    Point B (-1, -2);
    Point C (1000, -500);
    Point D (-1000, 500);

    CHECK (A.distance(B) == 100 && B.distance(A) == 100);
    CHECK (A.moveTowards());

    Point E; // Created as (0,0).
    Point F (4, 3);
    CHECK_EQ (E.distance(F), 5);
}

TEST_CASE("Case 2: Character Constructor Checks.") {
    Point A (-1, -2);
    Point B (2, 1);

    // Create a cowboy with empty name.
    Cowboy unknown ("", A);
    CHECK (strcmp(unknown.getName(), "") == 0);

    // Create 2 characters in the same location.
    YoungNinja steve ("Steve", B);
    OldNinja yuval ("Yuval", B);
    CHECK(steve.getLocation() != yuval.getLocation()); // Deep copy.
    steve.move(unknown);
    CHECK(steve.getLocation().distance(yuval.getLocation() > 0); // Not the same location.

    // Create another character with the same name.
    Point C (0.5, 1.5);
    CHECK_NOTHROW(YoungNinja ("Steve", C)));
}

TEST_CASE("Case 3: Cowboy Locations.") {
    Point A (100, 25);
    Point B ;
    Cowboy tom ("Tom", )
}

TEST_CASE("Case 4: Character Hit.") {
    Point A (1, 2);
    Point B (2, 1);
    Cowboy tom ("Tom", A);
    Cowboy ron ("Ron", B);

    CHECK_THROWS(tom.hit(-1)); // Negative hit should throw.
    CHECK_NOTHROW(tom.hit(0)); // Neutral hit is fine.
    tom.hit(55);
    CHECK(tom.isAlive() == true);
    tom.hit(55); // Kill tom.
    CHECK(tom.isAlive() == false);

    CHECK_NOTHROW(ron.hit(150)); // Hit more than hp.
    CHECK(ron.isAlive() == false);
}

TEST_CASE("Case 5: Cowboy Shooting.") {
    Point A (5, -2.25);
    Point B (85, 12);
    Cowboy tom ("Tom", A);
    Cowboy ron ("Ron", B);

    for (int i = 0; i < 6; i++) {
        CHECK(tom.hasboolets() == true);
        tom.shoot(ron);
    }
    CHECK(tom.hasbooles() == false); // No bullets.
    ron.hit(40); // Ron has 10 hp.

    // Shooting with no bullets shouldn't have affect.
    tom.shoot(ron);
    CHECK(ron.isAlive() == true);

    // Shooting on NULL or himself.
    tom.reload();
    CHECK(tom.hasbooles() == true);
    CHECK_THROWS(tom.shoot(nullptr));
    CHECK_THROWS(tom.shoot(tom));

    // Kill ron and try to reload.
    tom.shoot(ron);
    CHECK(ron.isAlive() == false);
    CHECK_THROWS(ron.reload());

    // Try to shoot on a dead character.
    CHECK_NOTHROW(tom.shoot(ron));
}