// Created by Shalev Ben David.
#include "doctest.h"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include <cmath>
using namespace ariel;
using namespace std;

TEST_CASE("Case 1: Point Checks.") {
    // Checking distance for both.
    Point A (5, 6);
    Point B (-1, -2);
    // sqrt{100} = 10.
    CHECK(A.distance(B) == 10);
    // sqrt{100} = 10.
    CHECK(B.distance(A) == 10);

    // Created as (0,0).
    Point C;
    Point D (4, 3);
    CHECK_EQ(C.distance(D), 5);

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
    CHECK_EQ(A, B);

    // Allow more distance to travel.
    A = Point :: moveTowards(A, C, 100);
    // A should now be (2,2).
    CHECK_EQ(A, C);

    // Complex move on the line y=x.
    // Get to the middle of the distance between D and E.
    D = Point :: moveTowards(D, E, sqrt(18) / 2);
    // D should now be (0,0).
    CHECK_EQ(D, Point(0, 0));

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
    CHECK_NE(steve.getLocation(), yuval.getLocation());

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
    CHECK_EQ(tom.isAlive(), true);
    // Kill tom.
    tom.hit(55);
    CHECK_EQ(tom.isAlive(), false);
    // Hit on dead is fine.
    CHECK_NOTHROW(tom.hit(2));

    // Hit more than hp.
    CHECK_NOTHROW(ron.hit(150));
    CHECK_EQ(ron.isAlive(), false);
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
    CHECK_EQ(tom.getLocation(), Point(100, 25));
    CHECK_EQ(ron.getLocation(), Point(10, -5));
}

TEST_CASE("Case 6: Ninja Location.") {
    Point A (33, 0);
    Point B (0, 0);
    YoungNinja tom ("Tom", A);
    OldNinja ron ("Ron", B);

    // Tom has 40 hp.
    tom.hit(60);

    for (int i = 0; i < 4; i++) {
        // Try and hit ron from far causes nothing.
        ron.slash(&tom);
        // Ron should still be alive.
        CHECK_EQ(tom.isAlive(), true);
        // Move towards ron at speed 14.
        ron.move(&tom);
    }
    // Killing ron now should work.
    CHECK_LE(ron.getLocation().distance(tom.getLocation()), 1);
    ron.slash(&tom);
    CHECK_EQ(tom.isAlive(), false);

    Point C (42, 0);
    TrainedNinja avi ("Avi", C);

    // Move exactly speed to meet tom.
    avi.move(&tom);
    CHECK_EQ(avi.getLocation(), tom.getLocation());
}

TEST_CASE("Case 7: Cowboy Shooting.") {
    Point A (5, -2.25);
    Point B (85, 12);
    Cowboy tom ("Tom", A);
    Cowboy ron ("Ron", B);

    for (int i = 0; i < 6; i++) {
        CHECK_EQ(tom.hasboolets(), true);
        tom.shoot(&ron);
    }
    // No bullets.
    CHECK_EQ(tom.hasboolets(), false);
    // Ron has 10 hp.
    ron.hit(40);

    // Shooting with no bullets shouldn't have affect.
    tom.shoot(&ron);
    CHECK_EQ(ron.isAlive(), true);

    // Shooting on NULL or himself.
    tom.reload();
    CHECK_EQ(tom.hasboolets(), true);
    CHECK_THROWS(tom.shoot(nullptr));
    CHECK_THROWS(tom.shoot(&tom));

    // Kill ron and try to reload.
    tom.shoot(&ron);
    CHECK_EQ(ron.isAlive(), false);
    CHECK_THROWS(ron.reload());

    // Try to shoot on a dead character.
    CHECK_NOTHROW(tom.shoot(&ron));

    // Tom has 10 hp.
    tom.hit(100);
    CHECK_EQ(tom.isAlive(), true);
    // Trying to shoot when dead should throw and have no affect.
    CHECK_THROWS(ron.shoot(&tom));
    CHECK_EQ(tom.isAlive(), true);

    // Try to reload twice.
    CHECK_NOTHROW(tom.reload());
    CHECK_NOTHROW(tom.reload());
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
    CHECK_EQ(tom.isAlive(), true);
    CHECK_EQ(ron.isAlive(), true);

    // Slashing tom should kill him.
    ron.slash(&tom);
    CHECK_EQ(tom.isAlive(), false);

    // Slashing NULL or himself.
    CHECK_THROWS(ron.slash(nullptr));
    CHECK_THROWS(ron.slash(&ron));

    // Slashing when you are dead should throw and have no affect.
    CHECK_THROWS(tom.slash(&ron));
    CHECK_EQ(ron.isAlive(), true);

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
        team.add(new Cowboy ("Same", B));
    }
    // Adding one more member should throw.
    Cowboy* last = new Cowboy ("Last", A);
    CHECK_THROWS(team.add(last));

    // Kill ron.
    ron -> hit(OLD_NINJA_HP);
    // Trying to add to team should still fail.
    CHECK_THROWS(team.add(last));
    delete last;
}

TEST_CASE("Case 10: Team Attack Check.") {
    Point A (1, 1);
    Point B (2, 2);
    Point C (0, 0);
    Point D (1, 1);
    Point E (2, 2);
    Point F (-1, -1);
    Point G (-2, -2);
    Cowboy* tom = new Cowboy ("Tom", A);
    OldNinja* yoni = new OldNinja ("Yoni", B);
    YoungNinja* yuval = new YoungNinja ("Yuval", C);
    Cowboy* shawn = new Cowboy ("Shawn", D);
    OldNinja* roni = new OldNinja ("Roni", E);
    YoungNinja* amir = new YoungNinja ("Amir", F);
    TrainedNinja* dolev = new TrainedNinja ("Dolev", G);

    // Adding members to team1 and team2.
    Team team1(tom);
    team1.add(yoni);
    team1.add(yuval);
    Team team2(shawn);
    team2.add(roni);
    team2.add(amir);
    team2.add(dolev);

    // Waste tom ammo.
    for (int i = 0; i < BULLETS_SIZE; i++) {
        tom -> shoot(roni);
    }
    CHECK_EQ(tom -> hasboolets(), false);

    // Kill 3 last members of team2.
    roni -> hit(OLD_NINJA_HP);
    amir -> hit(YOUNG_NINJA_HP);
    dolev -> hit(TRAINED_NINJA_HP);

    // Attack team2 (all should attack shon).
    team1.attack(&team2);
    CHECK_EQ(shawn -> isAlive(), true);

    // After 1 attack, tom has reloaded and yoni and all should be at shon's location.
    CHECK_EQ(tom -> hasboolets(), true);
    CHECK_EQ(tom -> getLocation(), D);
    CHECK_EQ(yoni -> getLocation(), D);
    CHECK_EQ(yuval -> getLocation(), D);

    // Continue attack.
    team1.attack(&team2);
    CHECK_EQ(shawn -> isAlive(), true);
    team1.attack(&team2);

    // After 3 attack, shon should be dead
    CHECK_EQ(shawn -> isAlive(), false);

    // Team2 is dead, so attacking them should throw
    CHECK_THROWS(team1.attack(&team2));

    // Kill team1.
    tom -> hit(COWBOY_HP);
    yoni -> hit(OLD_NINJA_HP);
    yuval -> hit(YOUNG_NINJA_HP);

    // Trying to attack with team1 should throw.
    TrainedNinja* temp = new TrainedNinja ("Temp", A);
    Team team3 (temp);
    CHECK_THROWS(team2.attack(&team3));
}

TEST_CASE("Case 12: Team2 Attack Check.") {
    Point A (0, 0);
    Point B (-5, 0);
    Point C (4, 0);
    Point D (1, 1);
    Point E (2, 2);
    Cowboy* tom = new Cowboy ("Tom", A);
    OldNinja* yoni = new OldNinja ("Yoni", B);
    YoungNinja* yuval = new YoungNinja ("Yuval", C);
    Cowboy* shawn = new Cowboy ("Shawn", D);
    OldNinja* roni = new OldNinja ("Roni", E);

    // Adding members to team1 and team2.
    Team2 team1(tom);
    team1.add(yoni);
    team1.add(yuval);
    Team2 team2(shawn);
    team2.add(roni);

    // Killing team1's leader (tom).
    tom -> hit(COWBOY_HP);
    CHECK_EQ(tom -> isAlive(), false);

    // Trying to attack team2 shouldn't throw.
    CHECK_NOTHROW(team1.attack(&team2));
    // The leader of team1 should be swapped to yuval since he is the closest.
    CHECK_EQ(team1.getLeader(), yuval);

    // Team2 attack team1.
    team2.attack(&team1);
    CHECK_GE(team1.stillAlive(), 1);
    team2.attack(&team1);
    CHECK_GE(team1.stillAlive(), 1);
    team2.attack(&team1);
    CHECK_GE(team1.stillAlive(), 1);
    team2.attack(&team1);

    // Last attack should kill team1.
    CHECK_GE(team1.stillAlive(), 1);
    team2.attack(&team1);

    // Now team1 is dead.
    CHECK_EQ(team1.stillAlive(), 0);

    // Now team2 can't attack team1 anymore.
    CHECK_THROWS(team2.attack(&team1));
}