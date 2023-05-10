// Created by Shalev Ben David.

#ifndef SP2_EX4A_COWBOY_H
#define SP2_EX4A_COWBOY_H
#include "Character.hpp"

const int BULLETS_SIZE = 6;
const int COWBOY_HP = 110;
const int COWBOY_DAMAGE = 10;

namespace ariel {
    class Cowboy : public Character {
    protected:
        int _bullets;

    public:
        // Constructors.
        Cowboy (const std :: string& name, Point& location) :
            Character(name, location), _bullets (BULLETS_SIZE), _hit_points(COWBOY_HP) {}

        // Methods.
        bool hasboolets () const;
        void shoot (Character*);
        void reload ();
        std :: string print () const;

        // Get methods.
        int getBullets () const;
    }
}

#endif //SP2_EX4A_COWBOY_H