// Created by Shalev Ben David.
#include "Team.hpp"
using namespace std;

// Constructor.
Team :: Team (Character *leader) : _warriors_count(0) {
    // If the leader is dead, throw exception.
    if (!leader -> isAlive()) {
        throw invalid_argument("Leader of the team must be alive!\n");
    }
    // Else, create the team and add the leader.
    add(leader);
    _leader = leader;
}

/**
 * adding member (Ninja or Cowboy) to the group
 * @param member - the member who joins the warrior group
 */
void Team :: add (Character* member) {
    // If the team is full, throw exception.
    if (_warriors_count == MAX_NUM_OF_WARRIORS) {
        throw exception("The team is full!\n");
    }
    // If member is null, throw exception.
    if (*leader == nullptr) {
        throw invalid_argument("Can't add null to the team!\n");
    }
    // If member is already in a team, throw exception.
    if (member -> getInTeam()) {
        throw invalid_argument("Member is already in a team!\n");
    }
    // Add member to the team.
    _warriors[_warriors_count++] = member;
    // Update his "in team" status to true.
    member -> getInTeam() = true;
}

/**
 * attack enemy_team
 * @param enemy_team - the team we attack
 */
void Team :: attack (Team* enemy_team) {

}

/**
 * @return - the number of team members that are alive
 */
int Team :: stillAlive () const {
    int count = 0;
    // Iterate first over the cowboys.
    for (size_t i = 0; i < _warriors_count; i++) {
        if (typeid (_warriors.at(i)) == typeid (Cowboy)) {
            if (_warriors.at(i) -> isAlive()) { count++; }
        }
    }
    // Iterate now over the ninjas.
    for (size_t i = 0; i < _warriors_count; i++) {
        if (typeid (_warriors.at(i)) == typeid (Ninja)) {
            if (_warriors.at(i) -> isAlive()) { count++; }
        }
    }
    return count;
}

/**
 * prints all characters in the team
 */
void Team :: print() const {
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<< Printing Warriors In The Team >>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    // Iterate first over the cowboys.
    for (size_t i = 0; i < _warriors_count; i++) {
        if (typeid (_warriors.at(i)) == typeid (Cowboy)) {
            cout << _warriors.at(i) -> print() << endl;
        }
    }
    // Iterate now over the ninjas.
    for (size_t i = 0; i < _warriors_count; i++) {
        if (typeid (_warriors.at(i)) == typeid (Ninja)) {
            cout << _warriors.at(i) -> print() << endl;
        }
    }
}
