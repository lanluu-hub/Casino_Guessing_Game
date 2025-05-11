// File: Player.cpp
// Author: Lan Luu
// Create: 03/24/2025
#include <cstdlib>
#include <iostream>
#include <string>
#include "Player.h"

Player::Player(std::string a_name, int a_balance): name(a_name), balance(a_balance) {

}

Player::~Player() {
    // Blank
}

void Player::set_name(const std::string entry){
    name = entry;
}

void Player::set_balance(const int amount) {
    balance = amount;
}

void Player::increaseBalance(const int amount) {
    balance += amount;
}
void Player::decreaseBalance(const int amount){
    balance -= amount;
}

void Player::display() const{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Balance: " << this->balance << std::endl;
}

void Player::checkBalance() const {
    std::cout << "\nCurrent Balance: $" << balance;
}

bool Player::isOverBalance(const int amount) const {
    if (amount > balance || balance <= 0) {
        return true;
    } else {
        return false;
    }
    return true;
}