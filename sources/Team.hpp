// Created by Shalev Ben David.

#ifndef SP2_EX4A_TEAM_H
#define SP2_EX4A_TEAM_H
#include <array>
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

const int MAX_NUM_OF_WARRIORS = 10;

namespace ariel {
    class Team {
    protected:
        std :: array < Character *, MAX_NUM_OF_WARRIORS > _warriors;
        int _warriors_count;
        Character *_leader;

    public:
        // Constructors.
        Team (Character *leader);

        // Destructor.
        virtual ~Team () {
            for (int i = 0; i < _warriors.size(); i++) { delete _warriors.at(i); }
        }

        // Methods.
        void add (Character *);
        virtual void attack (Team *);
        int stillAlive () const;

        // Print method.
        virtual void print() const;
    };
}

#endif //SP2_EX4A_TEAM_H
