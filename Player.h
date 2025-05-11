// File: Player.h
// Author: Lan Luu
// Create: 03/24/2025
#ifndef PLAYER_H
#define PLAYER_H
#include <cstdlib>
#include <string>

class Player {
    public:
        Player(std::string init_name = " ", int init_balance = 0);
        ~Player();
        void set_name(const std::string entry);
        void set_balance(const int amount);
        void increaseBalance(const int amount);
        void decreaseBalance(const int amount);
        void display() const;
        void checkBalance() const;
        bool isOverBalance(const int amount) const;
        

    protected:
        std::string name;
        int balance;
};

#endif