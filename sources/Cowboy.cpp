// Created by Shalev Ben David.
#include <exception>
#include <iostream>
#include "Cowboy.hpp"
using namespace std;
using namespace ariel;

/**
 * @return - if cowboy has bullets
 */
bool Cowboy :: hasboolets () const {
    return (_bullets > 0);
}

/**
 * in case of valid victim, the victim looses 1 point
 * @param enemy - the victim the cowboy shoots
 */
void Cowboy :: shoot (Character* enemy) {
    // Check if the enemy is valid.
    if (this == enemy || enemy == nullptr) {
        throw invalid_argument("Enter a valid enemy!");
    }
    // Only if this cowboy isn't dead, and he has bullets.
    if (isAlive() && _bullets > 0) {
        // Decrease enemy hp by 10.
        enemy -> hit(COWBOY_DAMAGE);
        // Decrease number of bullets by 1.
        _bullets -= 1;
    }
}

/**
 * Increase by 6 the cowboy's # of bullets.
 */
void Cowboy :: reload () {
    // If he is dead, throw error.
    if (!isAlive()) {
        throw runtime_error("A dead cowboy can't reload!");
    }
    _bullets += BULLETS_SIZE;
}

/**
 * @return - string representing the cowboy
 */
string Cowboy :: print () const {
    string info;
    info = "<<<<<<<<<<<<<<<<<<<<<<<<<< Character name: (C) [" + getName() + "] >>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    // If the character is alive, print hit points.
    if (isAlive()) {
        info += "[Hit Points: " + to_string(getHitPoints()) + "]\n";
    }
    info += "[Location: " + getLocation().toString() + "]\n";
    return info;
}

// Get methods.
int Cowboy :: getBullets () const { return _bullets; }