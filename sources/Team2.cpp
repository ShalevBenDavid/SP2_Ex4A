// Created by Shalev Ben David.
#include "Team2.hpp"
using namespace std;
using namespace ariel;

void Team2 :: attack (Team *) { }

/**
 * prints all characters in the team (the order doesn't matter).
 */
void Team2 :: print() const {
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<< Printing Warriors In The Team >>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    for (size_t i = 0; i < getWarriorsCount(); i++) {
        cout << getWarriors().at(i) -> print() << endl;
    }
}