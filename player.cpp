#include "player.h"

Player::Player() {
    firstName = "";
    secondName = "";
    points = 0;
}

Player::Player(string& firstName, string& secondName, int& points) {
    this->firstName = firstName;
    this->secondName = secondName;
    this->points = points;

}

Player::Player(Player& player) {
    firstName = player.firstName;
    secondName = player.secondName;
    points = player.points;
}

Player::~Player() {

}

Player& Player::operator=(const Player& player) {
    firstName = player.firstName;
    secondName = player.secondName;
    points = player.points;
    return *this;
}

bool Player::operator==(const Player& player) {
    if (firstName != player.firstName) {
        return false;
    }

    if (secondName != player.secondName) {
        return false;
    }

    if (points != player.points) {
        return false;
    }

    return true;
}

bool Player::operator!=(const Player& player) {
    return !(*this == player);
}