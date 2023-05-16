// Created by Shalev Ben David.
#include "doctest.h"
#include "sources/Team.hpp"
#include <cmath>
using namespace ariel;
using namespace std;

TEST_CASE("Case 1: Point Checks.") {
    // Checking distance for both.
    Point A (5, 6);
    Point B (-1, -2);
    // sqrt{100} = 10.
    CHECK (A.distance(B) == 10);
    // sqrt{100} = 10.
    CHECK (B.distance(A) == 10);

    // Created as (0,0).
    Point C;
    Point D (4, 3);
    CHECK_EQ (C.distance(D), 5);

    // Distance from far points.
    Point G (-1, 1);
    Point H (-10153, 1415);
    // sqrt{105062500} = 10250ץ
    CHECK_EQ(G.distance(H), 10250);
}

TEST_CASE("Case 2: moveTowards() Checks.") {
    // Simple move on the line y=x.
    Point A (0, 0);
    Point B (1, 1);
    Point C (2, 2);
    Point D (-1.5, -1.5);
    Point E (1.5, 1.5);

    A = Point :: moveTowards(A, B, sqrt(2));
    // A should now be (1,1).
    CHECK(A.distance(B) == 0);

    // Allow more distance to travel.
    A = Point :: moveTowards(A, C, 100);
    // A should now be (2,2).
    CHECK(A.distance(C) == 0);

    // Complex move on the line y=x.
    // Get to the middle of the distance between D and E.
    D = Point :: moveTowards(D, E, sqrt(18) / 2);
    // D should now be (0,0).
    CHECK(D.distance(Point(0, 0)) == 0);

    // Check moveTowards throw when given negative dist.
    CHECK_THROWS(Point :: moveTowards(A, B, -1));
}

TEST_CASE("Case 3: Character Constructor Checks.") {
    Point A (-1, -2);
    Point B (2, 1);

    // Create a cowboy with empty name.
    Cowboy unknown ("", A);
    CHECK_EQ(unknown.getName(), "");

    // Create 2 characters in the same location.
    YoungNinja steve ("Steve", B);
    OldNinja yuval ("Yuval", B);
    steve.move(&unknown);
    // Not the same location.
    CHECK(steve.getLocation().distance(yuval.getLocation()) > 0);

    // Create another character with the same name.
    Point C (0.5, 1.5);
    CHECK_NOTHROW(YoungNinja ("Steve", C));
}

TEST_CASE("Case 4: Character Hit.") {
    Point A (1, 2);
    Point B (2, 1);
    Cowboy tom ("Tom", A);
    Cowboy ron ("Ron", B);

    // Negative hit should throw.
    CHECK_THROWS(tom.hit(-1));
    // Neutral hit is fine.
    CHECK_NOTHROW(tom.hit(0));
    tom.hit(55);
    CHECK(tom.isAlive() == true);
    // Kill tom.
    tom.hit(55);
    CHECK(tom.isAlive() == false);
    // Hit on dead is fine.
    CHECK_NOTHROW(tom.hit(2));

    // Hit more than hp.
    CHECK_NOTHROW(ron.hit(150));
    CHECK(ron.isAlive() == false);
}

TEST_CASE("Case 5: Cowboy Locations.") {
    Point A (100, 25);
    Point B (10, -5);
    Cowboy tom ("Tom", A);
    Cowboy ron ("Ron", B);

    // Location should stay the same no matter what (deep copy).
    A = Point :: moveTowards(A, B, 2);
    B = Point :: moveTowards(B, A, 2);
    tom.shoot(&ron);
    ron.shoot(&tom);
    CHECK(tom.getLocation().distance(Point(100, 25)) == 0);
    CHECK(ron.getLocation().distance(Point(10, -5)) == 0);
}

TEST_CASE("Case 6: Ninja Location.") {
    Point A (57, 0);
    Point B (0, 0);
    YoungNinja tom ("Tom", A);
    OldNinja ron ("Ron", B);

    // Ron has 40 hp.
    ron.hit(110);

    for (int i = 0; i < 4; i++) {
        // Try and hit ron from far causes nothing.
        tom.slash(&ron);
        // Ron should still be alive.
        CHECK(ron.isAlive() == true);
        // Move towards ron at speed 14.
        tom.move(&ron);
    }
    // Killing ron now should work.
    CHECK(tom.getLocation().distance(ron.getLocation()) <= 1);
    tom.slash(&ron);
    CHECK(ron.isAlive() == false);
}

TEST_CASE("Case 7: Cowboy Shooting.") {
    Point A (5, -2.25);
    Point B (85, 12);
    Cowboy tom ("Tom", A);
    Cowboy ron ("Ron", B);

    for (int i = 0; i < 6; i++) {
        CHECK(tom.hasboolets() == true);
        tom.shoot(&ron);
    }
    // No bullets.
    CHECK(tom.hasboolets() == false);
    // Ron has 10 hp.
    ron.hit(40);

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

    // Tom has 10 hp.
    tom.hit(100);
    CHECK(tom.isAlive() == true);
    // Trying to shoot when dead should throw and have no affect.
    CHECK_THROWS(ron.shoot(&tom));
    CHECK(tom.isAlive() == true);
}

TEST_CASE("Case 8: Ninja Slashing.") {
    Point A (0, 0);
    Point B (1, 0);
    YoungNinja tom ("Tom", A);
    TrainedNinja ron ("Ron", B);

    // Tom has 40 hp.
    tom.hit(60);
    // Ron has 10 hp.
    ron.hit(110);

    // Both are alive.
    CHECK(tom.isAlive() == true);
    CHECK(ron.isAlive() == true);

    // Slashing tom should kill him.
    ron.slash(&tom);
    CHECK(tom.isAlive() == false);

    // Slashing NULL or himself.
    CHECK_THROWS(ron.slash(nullptr));
    CHECK_THROWS(ron.slash(&ron));

    // Slashing when you are dead should throw and have no affect.
    CHECK_THROWS(tom.slash(&ron));
    CHECK(ron.isAlive() == true);

    // Try to slash a dead character.
    CHECK_NOTHROW(ron.slash(&tom));
}

TEST_CASE("Case 9: Team Constructor And Add Function.") {
    Point A (-15, 2);
    Point B (2, -1.5);
    Point C (1.23, -3);
    Cowboy* tom = new Cowboy ("Tom", A);
    OldNinja* ron = new OldNinja ("Ron", B);
    TrainedNinja* josh = new TrainedNinja ("Josh", C);

    // Create a new team with null as leader should throw.
    CHECK_THROWS(Team (nullptr));

    // Kill tom.
    tom -> hit(COWBOY_HP);
    // Make him the leader of a team should throw.
    CHECK_THROWS(Team (tom));
    delete tom;

    // Create 2 teams and assign ron to be the leader of both should throw.
    Team team (ron);
    CHECK_THROWS(Team (ron));

    // Adding null to team should throw.
    CHECK_THROWS(team.add(nullptr));

    // Adding ron again to his team should throw.
    CHECK_THROWS(team.add(ron));

    // Adding a member from other team to this team should throw.
    Team team1 (josh);
    CHECK_THROWS(team.add(josh));

    // Adding 9 more members to team.
    for (int i = 0; i < 9; i++) {
        team.add(new Cowboy("Same", B));
    }
    // Adding one more member should throw.
    Cowboy* last = new Cowboy ("Last", A);
    CHECK_THROWS(team.add(last));
    delete last;
}

TEST_CASE("Case 10: Team Destructor Check.") {
    Point A(1, 1);
    Point B(-1, -1);
    Point C(1, -1);
    Point D(-1, 1);
    Cowboy* tom = new Cowboy("Tom", A);
    OldNinja* yoni = new OldNinja("Yoni", B);
    YoungNinja* yuval = new YoungNinja("Yuval", C);
    TrainedNinja* ron = new TrainedNinja("Ron", D);

    // Adding members to team.
    Team myTeam(tom);
    myTeam.add(yoni);
    myTeam.add(yuval);
    myTeam.add(ron);
}