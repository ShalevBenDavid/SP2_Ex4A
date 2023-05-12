// Created by Shalev Ben David.
#include "Ninja.hpp"

/**
 * in case of valid victim, the victim looses 13 point
 * @param enemy - the victim the ninja slashes
 */
void Ninja :: slash (Character* enemy) const {
    // Only if this ninja isn't dead and enemy is at most 1 meter away.
    if (isAlive() && _location.distance(enemy -> _location) <= 1) {
        // Check if the enemy is valid.
        if (*this == *enemy || enemy == nullptr) {
            throw std :: invalid_argument("Enter a valid enemy!");
        }
        // Decrease enemy hp by 40.
        *enemy -> hit(NINJA_DAMAGE);
    }
}

void Ninja :: move (Character *) { }

/**
 * @return - string representing the ninja
 */
Ninja :: print() const {
    std :: string info;
    info = "<<<<<<<<<<<<<<<<<<<<<<<<<< Character name: (N) [" + _name + "] >>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    // If the character is alive, print hit points.
    if (isAlive()) {
        info += "[Hit Points: " + std::to_string(_hit_points) + "]\n";
    }
    info += "[Location: " + _location.toString() + "]\n";
    return info;
}

// Get methods.
int Ninja :: getSpeed () const { return _speed; }