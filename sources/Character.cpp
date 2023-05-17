// Created by Shalev Ben David.

#include "Character.hpp"
using namespace std;
using namespace ariel;

/**
 * @param other - other character
 * @return - the distance between this character and other
 */
double Character :: distance (Character* other) const {
    return _location.distance(other -> getLocation());
}

/**
 * decrease the hp of the character by amount
 * @param amount - the amount of damage done
 */
void Character :: hit (int amount) {
    // If the amount of damage is negative, throw exception.
    if (amount < 0 ) {
        throw invalid_argument ("Damage must be >= 0!");
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
bool& Character :: getInTeam () { return _in_team; }

// Set methods.
void Character :: setLocation (Point location) { _location = location; }
void Character :: setHitPoints (int hit_points) { _hit_points = hit_points; }
void Character :: setAlive (bool alive) { _alive = alive; }

// ---------------------- For Tidy Only (Don't Check) ----------------------
// Copy Constructor.
Character :: Character (Character& other) {
    // Copy character.
    _name = other.name;
    _location = Point(other.getLocation().getX(), other.getLocation().getY());
    _hit_points = other._hit_points;
    _alive = other._alive;
    _in_team = other._in_team;
}

// Copy assignment operator.
Character& Character :: operator = (const Character& other) {
    if (this == &other) { return this; }

    // Copy character.
    _name = other.name;
    _location = Point(other._location.getX(), other._location.getY());
    _hit_points = other._hit_points;
    _alive = other._alive;
    _in_team = other._in_team;

    return this;
}

// Move Constructor.
Character :: Character (Character&& other) noexcept {
    if (this == &other) { return this; }

    // Move character to this object.
    _name = other.name;
    other.name = nullptr;
    _location = Point(other._location.getX(), other._location.getY());
    other._location = nullptr;
    _hit_points = other._hit_points;
    _alive = other._alive;
    _in_team = other._in_team;
}

// Move assignment operator.
Character& Character :: operator = (Character&& other) noexcept {
    if (this == &other) { return this; }

    // Move character to this object.
    _name = other.name;
    other.name = nullptr;
    _location = Point(other._location.getX(), other._location.getY());
    other._location = nullptr;
    _hit_points = other._hit_points;
    _alive = other._alive;
    _in_team = other._in_team;

    return *this;
}