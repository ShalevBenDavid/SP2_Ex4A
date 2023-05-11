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
 * decrease the hp of the character by amount
 * @param amount - the amount of damage done
 */
void Character :: hit (int amount) {
    // If the amount of damage is negative, throw exception.
    if (amount < 0 ) {
        throw std :: invalid_argument ("Damage must be >= 0!")
    }
    // Only if the character is alive, allow hp decrease.
    if (isAlive()) {
        // If too much damage occurred, the character is dead.
        if (amount >= _hit_points) {
            _hit_points = 0;
            _alive = false;
        }
        else {
            _hit_points -= amount;
        }
    }
}

// Get methods.
string Character :: getName () const { return _name; }
Point Character :: getLocation () const { return _location; }
int Character :: getHitPoints () const { return _hit_points; }
bool Character :: isAlive () const { return _alive; }