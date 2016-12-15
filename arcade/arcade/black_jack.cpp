#include "black_jack.h"

void playBlackJack() {
	Black_Jack jack;
	jack.fillDeck();
	jack.shuffleDeck();
	jack.play() ? std::cout << "You win!\n" : std::cout << "You lost..\n";
}