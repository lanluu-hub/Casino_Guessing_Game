// File: Casino Guessing Game
// Author: Lan Luu
// Create: 03/24/2025
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include "Player.h"

using namespace std;

void    Intro();
void    Rules();
void    Initialize_player(Player & player);
int     Place_a_bid(const Player&);
int     Guess();
int     Throw_dice();
bool    Result(int, int);
void    Check_out(const Player &);

int
main() 
{
    Player  player;
    int bid_amount{};
    int guess{};    // from 1 - 10
    int dice_result{};  // from 1 - 10
    char isReplay{};

    srand(time(0));

    Intro();

    Initialize_player(player);
    
    cout << "Welcome ";
    player.display();

    do {
        Rules();

        bid_amount = Place_a_bid(player);

        guess = Guess();

        dice_result = Throw_dice();
        
        cout << "\nYour guess: " << guess << "\tDice Roll: " << dice_result << endl;

        if(Result(guess, dice_result)){
            cout << "YOU WON.\n";
            bid_amount = bid_amount * 10;
            player.increaseBalance(bid_amount);
        } else {
            cout << "Ohh, too bad, better luck next time.\n";
            player.decreaseBalance(bid_amount);
        }

        player.checkBalance();
        if (!player.isOverBalance(0)) {
            cout << "\nPlay again? (y/n)\n>> ";
            cin >> isReplay;
        } else {
            cout << "\nSorry, You run out of Money.\n";
        }
    } while ((!player.isOverBalance(0)) && (isReplay == 'y' || isReplay == 'Y'));

    Check_out(player);

    return EXIT_SUCCESS;
}

void    Intro() 
{
    cout << "\n===============================================================================================";
	cout << "\n   CCCCC      A        SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     ";
	cout << "\n CC          A  A      SS             III     NN N   NN   OO      OO    ";
	cout << "\nCC          A    A     SSSSSSSSS      III     NN  N  NN   OO      OO    ";
	cout << "\n CC        AAAAAAAA           SS      III     NN   N NN   OO      OO    ";
	cout << "\n   CCCCC  A        A   SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     ";
	cout << "\n===============================================================================================\n";
}

void    Rules()
{
    cout << "\n===============================================================================================\n";
	cout << "\t\t\tGame Rules";
	cout << "\n===============================================================================================";
	cout << "\n1. Choose Number Between 1 To 10";
	cout << "\n2. Winning Amount Will Be 10 Times Of Bid Amount";
	cout << "\n3. Loose Amount Will Be Biding Amount";
	cout << "\n4. You Can Leave A Game Any Time";
	cout << "\n===============================================================================================\n";
}

void Initialize_player(Player &player)
{
    string name_holder;
    int balance_holder;
    cout << "\nPlease Enter your Name here:\n>> ";
    getline(cin, name_holder);
    while (name_holder == " ") {
        cout << "Name cannot be left blank, Please try again.\n>> ";
        cin.clear();
        cin.ignore(1024, '\n');
        getline(cin, name_holder);
    }

    cout << "Please Enter your Initial Balance:\n>> ";
    cin >> balance_holder;
    if (balance_holder < 0) {
        balance_holder = 0;
    }

    player.set_name(name_holder);
    player.set_balance(balance_holder);
}

int     Place_a_bid(const Player &player)
{
    int amount{};

    cout << "\nHow much do you want to bid:\n>> ";
    cin >> amount;
    while (amount < 0 || player.isOverBalance(amount)) {
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "You cannot bid that amount (bid must be greater than 0 and less than current balance.)\n>> ";
        cin >> amount;
    }

    return amount;
}

int     Guess()
{
    int guess;

    cout << "\nPlace your Guess:\n>> ";
    cin >> guess;
    while (guess < 1 || guess > 10) {
        cout << "That an invalid guess (1-10)\n>> ";
        cin.clear();
        cin.ignore(1024, '\n');
        cin >> guess;
    }

    return guess;
}

int     Throw_dice()
{
    int dice{};

    cout << "\nThrowing dice";
    for (int i = 0; i < 3; ++i) {
        this_thread::sleep_for(chrono::seconds(1));
        cout << "   .";
    }

    dice = rand() % 10 + 1;

    return dice;
}

bool     Result(int guess, int result)
{
    if (guess == result) {
        return true;
    } else {
        return false;
    }

    return false;
}

void    Check_out(const Player &player)
{
    cout << "\n===============================================================================================\n";
	cout << "Thanks For Playing Game Again ";
    player.checkBalance();
	cout << "\n===============================================================================================\n";
}