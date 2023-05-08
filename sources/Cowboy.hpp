// Created by Shalev Ben David.

#ifndef SP2_EX4A_COWBOY_H
#define SP2_EX4A_COWBOY_H
#include "Character.hpp"

namespace ariel {
    class Cowboy : public Character {
        // Private attributes.
        int _bullets;

    public:
        // Constructors.
        Cowboy (int bullets) : _bullets (bullets) {}

        // Methods.
        void print ();


    }
}

#endif //SP2_EX4A_COWBOY_H


void Cowboy :: print () {
    std :: string info;
    info = "<<<<<<<<<<<<<<<<<<<<<<<<<< Character name: (C) [" + _name + "] >>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    // If the character is alive, print hit points.
    if (isAlive()) {
        info += "[Hit Points: " + std :: to_string(_hit_points) + "]\n";
    }
    info += "[Location: " + _location.toString() + "]\n";
    std :: cout << info;
}