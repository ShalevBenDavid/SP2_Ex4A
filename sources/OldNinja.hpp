// Created by Shalev Ben David.

#ifndef SP2_EX4A_NINJA_H
#define SP2_EX4A_NINJA_H

namespace ariel {
    class Ninja : public Character {
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
