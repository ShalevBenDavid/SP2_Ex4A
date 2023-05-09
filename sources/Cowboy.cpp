// Created by Shalev Ben David.
#include "Cowboy.hpp"

/**
 * @return - if cowboy has bullets
 */
bool Cowboy :: hasboolets () {
    return (_bullets > 0);
}

/**
 * in case of valid victim, the victim looses 1 point
 * @param enemy - the victim the cowboy shoots
 */
void Cowboy :: shoot (Character* enemy) {
    // Only if this cowboy isnt dead and he has bullets.
    if (isAlive() && _bullets > 0) {
        // Check if the enemy is valid.
        if (*this == *enemy || enemy == NULL) {
            throw std::invalid_argument("Enter a valid enemy!");
        }
        // Decrease enemy hp by 10.
        *enemy -> hit(COWBOY_DAMAGE);
        // Decrease number of bullets by 1.
        _bullets -= 1;
    }
}

/**
 * Increase by 6 the cowboy's # of bullets.
 */
void Cowboy :: reload () {
    // Only if he is alive.
    if (isAlive()) {
        _bullets += BULLETS_SIZE;
    }
}

/**
 * @return - string representing the cowboy
 */
std :: string Cowboy :: print () {
    std :: string info;
    info = "<<<<<<<<<<<<<<<<<<<<<<<<<< Character name: (C) [" + _name + "] >>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    // If the character is alive, print hit points.
    if (isAlive()) {
        info += "[Hit Points: " + std :: to_string(_hit_points) + "]\n";
    }
    info += "[Location: " + _location.toString() + "]\n";
    return info;
}

// Get methods.
int Cowboy :: getBullets () { return _bullets; }