// Created by Shalev Ben David.

#ifndef SP2_EX4A_NINJA_H
#define SP2_EX4A_NINJA_H
#include "Character.hpp"

const int NINJA_DAMAGE 13;

namespace ariel {
    class Ninja : public Character {
        // Private attributes.
        int _speed;

    public:
        // Methods.
        void slash (Character*);
        std::string print();

        void move(Character *);
    }

/**
 * in case of valid victim, the victim looses 13 point
 * @param enemy - the victim the ninja slashes
 */
    void Ninja :: slash (Character* enemy) {
        // Only if this ninja isn't dead and enemy is at most 1 meter away.
        if (isAlive() && _location.distance(enemy -> _location) < 1) {
            // Check if the enemy is valid.
            if (*this == *enemy || enemy == NULL) {
                throw std::invalid_argument("Enter a valid enemy!");
            }
            // Decrease enemy hp by 13.
            *enemy -> hit(NINJA_DAMAGE);
        }
    }

    Ninja :: print() {
        std :: string info;
        info = "<<<<<<<<<<<<<<<<<<<<<<<<<< Character name: (N) [" + _name + "] >>>>>>>>>>>>>>>>>>>>>>>>>>\n";
        // If the character is alive, print hit points.
        if (isAlive()) {
            info += "[Hit Points: " + std::to_string(_hit_points) + "]\n";
        }
        info += "[Location: " + _location.toString() + "]\n";
        return info;
    }
}

#endif //SP2_EX4A_NINJA_H