// Created by Shalev Ben David.

#ifndef SP2_EX4A_COWBOY_H
#define SP2_EX4A_COWBOY_H
#include "Character.hpp"

const int BULLETS_SIZE 6;
const int COWBOY_HP 110;
const int COWBOY_DAMAGE 10;

namespace ariel {
    class Cowboy : public Character {
        // Private attributes.
        int _bullets;

    public:
        // Constructors.
        Cowboy () : _bullets (BULLETS_SIZE), _hit_points(COWBOY_HP) {}

        // Methods.
        bool hasboolets ();
        void shoot (Character*);
        void reload ();
        std :: string print ();
    }
}

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
    // Only if the cowboy isnt dead and has bullets.
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
        _bullets += 6;
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

#endif //SP2_EX4A_COWBOY_H