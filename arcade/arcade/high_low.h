#ifndef HILO_H
#define HILO_H

#include <iostream>
#include <random>

class High_Low {
private:
	int generator;
	bool win{ false };
	int tries{ 1 };
	int number; // watch here!
public:
	High_Low() {
		//
	}

	void generateNumber() {
		std::random_device rd;
		std::mt19937 random(rd());
		std::uniform_int_distribution<> range(1, 100); // 
		generator = range(random);
	}

	void startGame() {
		std::cout << "Let's play a game.  I'm thinking of a number between 1 to 100.  You have 7 tries to guess what it is.\n";
		using namespace std;

		while (tries <= 7) {
			while (1) {
				cout << "Guess #" << tries << " ";
				std::cin >> number;
				std::cin.ignore(4324, '\n');
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(12331, '\n');
					std::cout << "Ops, invalid input. Please try again" << std::endl;
				}
				else break;
			}
			if (number > generator) {
				std::cout << "Too high!\n";
			}
			if (number < generator) {
				std::cout << "Too low!\n";
			}
			if (number == generator) {
				std::cout << "You won!\n";
				win = true;
				break;
			}

			tries++;
		}
		win ? std::cout << "You did great! " : std::cout << "Sorry, you lost. The correct number was " << generator << ".\n";
	}

};

#endif // !HILO_H

