// Created by Shalev Ben David.
#include "Team2.hpp"
using namespace std;

virtual void Team2 :: attack (Team *) { }

/**
 * prints all characters in the team (the order doesn't matter).
 */
virtual void Team2 :: print() const override {
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<< Printing Warriors In The Team >>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    for (int i = 0; i < _warriors_count; i++) {
        cout << _warriors.at(i) -> print() << endl;
    }
}