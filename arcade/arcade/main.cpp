#include <iostream>
#include <conio.h>

void playSnake();
void playHiLo();
void playBlackJack();

int main()
{
	std::cout << "Insert the number of the game you'd like to play\n 1) Snake\n 2) Black Jack\n 3) High-Low\n\n ";
	int pick;

	while (1) {
		std::cin >> pick;
		if (std::cin.fail() || (pick < 1 && pick > 3)) {
			std::cin.clear();
			std::cin.ignore(12331, '\n');
			std::cout << "Ops, invalid input. Please try again" << std::endl;
		}
		else break;
	}
	switch (pick) {
	case 1:
		playSnake();
		break;
	case 2:
		system("cls");
		playBlackJack();
		break;
	case 3:
		system("cls");
		playHiLo();
		break;
	default:
		break;
	}

	system("pause");
	return 0;
}