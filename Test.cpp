// Created by Shalev Ben David.
#include "doctest.h"
#include "sources/Team.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("Case 1: Point Checks.") {
    // Checking distance for both.
    Point A (5, 6);
    Point B (-1, -2);
    CHECK (A.distance(B) == 10); // sqrt{100} = 10.
    CHECK (B.distance(A) == 10); // sqrt{100} = 10.

    Point C; // Created as (0,0).
    Point D (4, 3);
    CHECK_EQ (C.distance(D), 5);

    // Distance with complex point.
    Point E (3.5, 5);
    Point F (3.9, 5.3);
    CHECK_EQ(E.distance(F), 0.5); // sqrt{1/4} = 1/2.

    // Distance from far points.
    Point G (-1, 1);
    Point H (-10153, 1415);
    CHECK_EQ(G.distance(H), 10250); // sqrt{105062500} = 10250
}

TEST_CASE("Case 2: Character Constructor Checks.") {
    Point A (-1, -2);
    Point B (2, 1);

    // Create a cowboy with empty name.
    Cowboy unknown ("", A);
    CHECK_EQ(unknown.getName(), "");

    // Create 2 characters in the same location.
    YoungNinja steve ("Steve", B);
    OldNinja yuval ("Yuval", B);
    steve.move(&unknown);
    CHECK(steve.getLocation().distance(yuval.getLocation()) > 0); // Not the same location.

    // Create another character with the same name.
    Point C (0.5, 1.5);
    CHECK_NOTHROW(YoungNinja ("Steve", C));
}

TEST_CASE("Case 3: Character Hit.") {
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

TEST_CASE("Case 4: Cowboy Locations.") {
    Point A (100, 25);
    Point B (10, -5);
    Cowboy tom ("Tom", A);
    Cowboy ron ("Ron", B);

    // Location should stay the same no matter what.
    tom.shoot()
}

TEST_CASE("Case 5: Ninja Location.") {
    Point A (5, -2.25);
    Point B (85, 12);
    YoungNinja tom ("Tom", A);
    OldNinja ron ("Ron", B);
}

TEST_CASE("Case 6: Cowboy Shooting.") {
    Point A (5, -2.25);
    Point B (85, 12);
    Cowboy tom ("Tom", A);
    Cowboy ron ("Ron", B);

    for (int i = 0; i < 6; i++) {
        CHECK(tom.hasboolets() == true);
        tom.shoot(&ron);
    }
    CHECK(tom.hasboolets() == false); // No bullets.
    ron.hit(40); // Ron has 10 hp.

    // Shooting with no bullets shouldn't have affect.
    tom.shoot(&ron);
    CHECK(ron.isAlive() == true);

    // Shooting on NULL or himself.
    tom.reload();
    CHECK(tom.hasboolets() == true);
    CHECK_THROWS(tom.shoot(nullptr));
    CHECK_THROWS(tom.shoot(&tom));

    // Kill ron and try to reload.
    tom.shoot(&ron);
    CHECK(ron.isAlive() == false);
    CHECK_THROWS(ron.reload());

    // Try to shoot on a dead character.
    CHECK_NOTHROW(tom.shoot(&ron));
}

TEST_CASE("Case 6: Ninja Slashing.") {
    Point A (0, 0);
    Point B (1, 0);
    YoungNinja tom ("Tom", A);
    TrainedNinja ron ("Ron", B);

    tom.hit(60); // Tom has 40 hp.
    ron.hit(110); // Rob has 10 hp.

    // Both are alive.
    CHECK(tom.isAlive() == true);
    CHECK(ron.isAlive() == true);

    // Slashing tom should kill him.
    ron.slash(&tom);
    CHECK(tom.isAlive() == false);

    // Slashing NULL or himself.
    CHECK_THROWS(ron.slash(nullptr));
    CHECK_THROWS(ron.slash(&ron));

    // Slashing when you are dead has no affects.
    tom.slash(&ron);
    CHECK(ron.isAlive() == true);

    // Try to slash a dead character.
    CHECK_NOTHROW(ron.slash(&tom));
}

TEST_CASE("Case 10: Team Destructor Check.") {
    Point A(1, 1);
    Point B(-1, -1);
    Point C(1, -1);
    Point D(-1, 1);
    Cowboy* tom = nullptr;
    OldNinja* yoni = nullptr;
    YoungNinja* yuval = nullptr;
    TrainedNinja* ron = nullptr;
    // Creating characters on the heap with "new" and adding to team.
    {
        tom = new Cowboy("Tom", A);
        yoni = new OldNinja("Yoni", B);
        yuval = new YoungNinja("Yuval", C);
        ron = new TrainedNinja("Ron", D);
        // Adding members to team.
        Team myTeam (tom);
        myTeam.add(yoni);
        myTeam.add(yuval);
        myTeam.add(ron);
    }

    // When exiting the block, the destructor is called.
    CHECK(tom == nullptr);
    CHECK(yoni == nullptr);
    CHECK(yuval == nullptr);
    CHECK(ron == nullptr);
}