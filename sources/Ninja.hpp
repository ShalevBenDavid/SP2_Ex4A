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
        void slash (Character *);
        std::string print ();
        void move (Character *);

        // Get methods.
        int getSpeed ();
    }
}

#endif //SP2_EX4A_NINJA_H