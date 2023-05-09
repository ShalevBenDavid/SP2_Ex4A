// Created by Shalev Ben David.

#ifndef SP2_EX4A_NINJA_H
#define SP2_EX4A_NINJA_H
#include "Character.hpp"
#include "Ninja.hpp"

const int TRAINED_NINJA_SPEED 12;
const int TRAINED_NINJA_HP 120;

namespace ariel {
    class TrainedNinja : public Ninja {
        // Private attributes.
    public:
        // Constructors.
        TrainedNinja () : _speed(TRAINED_NINJA_SPEED), _hit_points(TRAINED_NINJA_HP) {}
        // Methods.
    }
}

#endif //SP2_EX4A_NINJA_H
