// Created by Shalev Ben David.

#ifndef SP2_EX4A_TRAINEDNINJA_H
#define SP2_EX4A_TRAINEDNINJA_H
#include "Ninja.hpp"

const int TRAINED_NINJA_SPEED = 12;
const int TRAINED_NINJA_HP = 120;

namespace ariel {
    class TrainedNinja : public Ninja {

    public:
        // Constructors.
        TrainedNinja () : _speed(TRAINED_NINJA_SPEED), _hit_points(TRAINED_NINJA_HP) {}
    }
}

#endif //SP2_EX4A_TRAINEDNINJA_H
