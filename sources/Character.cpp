// Created by Shalev Ben David.

#include "Character.hpp"
using namespace std;

/**
 * @param other - other character
 * @return - the distance between this character and other
 */
double Character :: distance (Character* other) {
    return _location.distance(other._location);
}

/**
 * decrease the hit points of the character by amount
 * @param amount - the amount of damage done
 */
void Character :: hit (int amount) {
    // If too much damage occurred, the character is dead.
    if (amount >= _hit_points) {
        _hit_points = 0;
        _alive = false;
    }
    else {
        _hit_points -= amount;
    }
}

// Get methods.
string Character :: getName () { return _name; }
Point Character :: getLocation () { return _location; }
int Character :: getHitPoints () { return _hit_points; }
bool Character :: isAlive () { return _alive; }