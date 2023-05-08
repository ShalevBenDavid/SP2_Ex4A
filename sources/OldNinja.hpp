// Created by Shalev Ben David.

#ifndef SP2_EX4A_NINJA_H
#define SP2_EX4A_NINJA_H

const int OLD_NINJA_SPEED 8;
const int OLD_NINJA_HP 150;

namespace ariel {
    class OldNinja : public Character {
        // Private attributes.
        int _bullets;

    public:
        // Constructors.
        Cowboy (int bullets) : _bullets (bullets) {}

        // Methods.
        void print ();


    }
}

#endif //SP2_EX4A_NINJA_H
