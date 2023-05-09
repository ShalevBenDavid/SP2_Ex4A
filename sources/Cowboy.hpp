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

        // Get methods.
        int getBullets ();
    }
}

#endif //SP2_EX4A_COWBOY_H