#include <iostream>
#include <random>
#include "console.h"
#include "snake.h"

void playSnake() {
	ShowConsoleCursor(false);
	system("Color 0A");
	std::random_device rd;
	std::mt19937 random(rd());
	Snake snake(random);
	while (true) {
		snake.draw();
		snake.getKey();
		snake.getDirection();
		snake.eat();
		snake.run();
		snake.isAlive();
		Sleep(30);
		if (snake.isAlive()) break;
	}
	std::cout << std::endl << "GAME OVER!" << std::endl;
}