// Created by Shalev Ben David.

#ifndef SP2_EX4A_NINJA_H
#define SP2_EX4A_NINJA_H
#include "Character.hpp"

namespace ariel {
    class Ninja : public Character {
        // Private attributes.
        int _speed;

    public:
        // Methods.
        std :: string print();
    }
}

std :: string Ninja :: print () {
    std :: string info;
    info = "<<<<<<<<<<<<<<<<<<<<<<<<<< Character name: (N) [" + _name + "] >>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    // If the character is alive, print hit points.
    if (isAlive()) {
        info += "[Hit Points: " + std :: to_string(_hit_points) + "]\n";
    }
    info += "[Location: " + _location.toString() + "]\n";
    return info;
}

#endif //SP2_EX4A_NINJA_H