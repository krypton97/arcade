#ifndef SNAKE_H
#define SNAKE_H

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

enum Directon {
	STOP = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

Directon dir;

class Snake {
private:
	int width{ 60 };
	int height{ 20 };
	int snakeX[100];
	int snakeY[100];
	int fruitX;
	int fruitY;
	int tail{ 0 };
	int score{};
	int prevX;
	int prevY;

public:
	Snake(std::mt19937 &random) {
		fruitX = random() % width;
		fruitY = random() % height;
		snakeX[0] = width / 2;
		snakeY[0] = height / 2;
	}

	void draw() {
		system("cls");
		for (int i = 0; i < width + 2; i++) std::cout << char(219);
		std::cout << std::endl;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (j == 0) std::cout << char(219);
				if ((j == snakeX[0] && i == snakeY[0]) || (j == fruitX && i == fruitY)) std::cout << char(219);
				else {
					int empty = 0;
					for (int t = 1; t <= tail; t++) {
						if (snakeX[t] == j && snakeY[t] == i) {
							std::cout << char(219);
							empty++;
						}
					}
					if (!empty) std::cout << " ";
				}
				if (j == width - 1) std::cout << char(219);
			}
			std::cout << std::endl;
		}

		for (int i = 0; i < width + 2; i++) std::cout << 'ß';
		std::cout << std::endl << "Your score is: " << score;

	}

	void getKey() {
		if (_kbhit()) {
			switch (_getch())
			{
			case KEY_UP:
				dir = UP;
				break;
			case KEY_DOWN:
				dir = DOWN;
				break;
			case KEY_LEFT:
				dir = LEFT;
				break;
			case KEY_RIGHT:
				dir = RIGHT;
				break;
			default:
				break;
			}
		}
	}

	void getDirection() {
		switch (dir)
		{
		case UP:
			prevX = snakeX[0];
			prevY = snakeY[0];
			snakeY[0]--;
			break;
		case DOWN:
			prevX = snakeX[0];
			prevY = snakeY[0];
			snakeY[0]++;
			break;
		case LEFT:
			prevX = snakeX[0];
			prevY = snakeY[0];
			snakeX[0]--;
			break;
		case RIGHT:
			prevX = snakeX[0];
			prevY = snakeY[0];
			snakeX[0]++;
			break;
		default:
			break;
		}

	}

	void eat() {
		if (snakeX[0] == fruitX && snakeY[0] == fruitY) {
			tail++;
			fruitX = rand() % width;
			fruitY = rand() % height;
			score += 10;
		}
	}

	void run() {
		if (snakeX[0] > width - 1) snakeX[0] = 0;
		else if (snakeX[0] < 0) snakeX[0] = width - 1;
		if (snakeY[0] > height - 1) snakeY[0] = 0;
		else if (snakeY[0] < 0) snakeY[0] = height - 1;
		int saveX = prevX;
		int saveY = prevY;
		int newX, newY;

		for (int i = 1; i < tail + 1; i++) {
			newX = snakeX[i];
			newY = snakeY[i];
			snakeX[i] = saveX;
			snakeY[i] = saveY;
			saveX = newX;
			saveY = newY;
		}

	}

	bool isAlive() {

		for (int t = 1; t < tail + 1; t++) {
			if (snakeX[t] == snakeX[0] && snakeY[t] == snakeY[0]) return true;
		}
		return false;
	}
};

#endif // !SNAKE_H

