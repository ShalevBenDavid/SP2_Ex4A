// Created by Shalev Ben David.
#include "Team2.hpp"
using namespace std;

void Team2 :: attack (Team *) { }

/**
 * prints all characters in the team (the order doesn't matter).
 */
void Team2 :: print() const {
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<< Printing Warriors In The Team >>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    for (size_t i = 0; i < _warriors_count; i++) {
        cout << _warriors.at(i) -> print() << endl;
    }
}