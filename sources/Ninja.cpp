// Created by Shalev Ben David.
#include "Ninja.hpp"
using namespace std;

/**
 * in case of valid victim, the victim looses 13 point
 * @param enemy - the victim the ninja slashes
 */
void Ninja :: slash (Character* enemy) const {
    // Only if this ninja isn't dead and enemy is at most 1 meter away.
    if (isAlive() && _location.distance(enemy -> _location) <= 1) {
        // Check if the enemy is valid.
        if (this == enemy || enemy == nullptr) {
            throw invalid_argument("Enter a valid enemy!\n");
        }
        // Decrease enemy hp by 40.
        enemy -> hit (NINJA_DAMAGE);
    }
}

/**
 * Moves this ninja closer to enemy based on his speed.
 * @param enemy - the enemy we move this ninja towards
 */
void Ninja :: move (Character* enemy) {
    // Check that this enemy isn't null.
    if (enemy == nullptr) {
        throw invalid_argument("Enemy can't be null!\n");
    }
    // Move this ninja location towards enemy.
    _location = moveTowards(_location, enemy._location, _speed);
}

/**
 * @return - string representing the ninja
 */
string Ninja :: print() const {
    string info;
    info = "<<<<<<<<<<<<<<<<<<<<<<<<<< Character name: (N) [" + _name + "] >>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    // If the character is alive, print hit points.
    if (isAlive()) {
        info += "[Hit Points: " + to_string(_hit_points) + "]\n";
    }
    info += "[Location: " + _location.toString() + "]\n";
    return info;
}

// Get methods.
int Ninja :: getSpeed () const { return _speed; }