// Created by Shalev Ben David.
#include "Team.hpp"
#include <limits>
using namespace std;
using namespace ariel;

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
    // If the team is full, throw error.
    if (_warriors_count == MAX_NUM_OF_WARRIORS) {
        throw runtime_error("The team is full!\n");
    }
    // If member is null, throw exception.
    if (member == nullptr) {
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
 * Attacks enemy_team
 * @param enemy_team - the team we attack
 */
void Team :: attack (Team* enemy_team) {
    // Only if this team is alive, attack.
    if (stillAlive() > 0) {
        // If the current leader is dead, assign a new leader.
        if (!_leader -> _alive) {
            _leader = getClosest(this, _leader);
        }
        // Attack victims from the enemy team until a victim survives an attack or the enemy team is dead.
        while ((enemy_team -> stillAlive() > 0) && (attackVictim(getClosest(enemy_team, _leader)))) {}
    }
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

/**
 *
 * @param team - the team we choose a warrior from
 * @param leader - the leader from which we find the closest warrior
 * @return  - the closest warrior to the leader which is alive
 */
static Character* Team :: getClosest (Team* team, Character* leader) const {
    // Create a pointer to the warrior we will return.
    Character* warrior;
    // Save the minimum distance.
    int min_distance = numeric_limits <double> :: max();
    // Current distance for each of the warriors in team.
    double dist = 0;
    // Iterate over the team and return the closest warrior.
    for (size_t i = 0; i < team -> _warriors_count; i++) {
        dist = leader -> distance(team -> _warriors.at(i));
        if (team -> _warriors.at(i) -> isAlive() && dist < min_distance) {
            min_distance = dist;
            warrior = team -> _warriors.at(i);
        }
    }
    // Return the closest warrior found.
    return warrior;
}

bool Team :: attackVictim (Character* victim) {
    Cowboy* current_cowboy = nullptr;
    Ninja* current_ninja = nullptr;
    // Iterate first over the cowboys and shoot/reload at victim.
    for (size_t i = 0; i < _warriors_count; i++) {
        if (typeid(_warriors.at(i)) == typeid(Cowboy)) {
            current_cowboy = _warriors.at(i);
            // Only if the cowboy is alive, shoot/reload.
            if (current_cowboy -> isAlive()) {
                // If the cowboy has bullets, shoot the victim.
                if (current_cowboy -> hasboolets()) {
                    current_cowboy -> shoot(victim);
                }
                // Else, reload the weapon.
                else {
                    current_cowboy -> reload();
                }
            }
        }
    }
    // Iterate now over the ninjas and slash/move at victim.
    for (size_t i = 0; i < _warriors_count; i++) {
        if (typeid(_warriors.at(i)) == typeid(Ninja)) {
            current_ninja = _warriors.at(i);
            // Only if the ninja is alive, slash/move.
            if (current_ninja -> isAlive()) {
                // If the ninja is close, slash the victim.
                if (current_ninja -> getLocation().distance(victim -> getLocation()) <= 1) {
                    current_ninja -> slash(victim);
                }
                // Else, move ninja towards victim.
                else {
                    current_ninja -> move(victim);
                }
            }
        }
    }
    // If the victim is alive, return false. Else, return true.
    return !(victim -> isAlive())
}

// Get methods.
std :: array <Character*, MAX_NUM_OF_WARRIORS> Team :: getWarriors() const { return _warriors; }
size_t Team :: getWarriorsCount () const { return _warriors_count; }
Character* Team :: getLeader () const { return _leader; }

// Set methods.
void Team :: setWarriorsCount (size_t warriors_count) { _warriors_count = warriors_count; }
void Team :: setLeader (Character* leader) { _leader = leader; };