#ifndef BLACK_JACK_H
#define BLACK_JACK_H

#include <iostream>
#include <string>
#include <array>
#include <utility>
#include <random>

enum CARDS_RANK {
	RANK_2 = 2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	JACK,
	QUEEN,
	KING,
	ACE
};

enum SUITS {
	CLUB,
	DIAMOND,
	HEART,
	SPADE
};

struct Card {
	CARDS_RANK rank;
	SUITS suit;
};

class Black_Jack {
private:
	Card card;
	std::array<Card, 52> deck;
	bool win{ false };
	int dealer{};
	int player{};
	int track{};

public:
	Black_Jack() {
		//
	}

	void printCard(const Card &card) {
		switch (card.rank)
		{
		case JACK:   std::cout << 'J';        break;
		case KING:   std::cout << 'K';        break;
		case QUEEN:  std::cout << 'Q';        break;
		case ACE:    std::cout << 'A';        break;
		default:     std::cout << card.rank;  break;
		}
		switch (card.suit)
		{
		case CLUB:    std::cout << 'C'; break;
		case DIAMOND: std::cout << 'D'; break;
		case HEART:   std::cout << 'H'; break;
		case SPADE:   std::cout << 'S'; break;
		default:                   break;
		}
	}

	void fillDeck() {
		int card = 0;
		for (int suit = 0; suit < 4; suit++) {
			for (int rank = 2; rank <= ACE; rank++) {
				deck[card].suit = static_cast<SUITS>(suit);
				deck[card].rank = static_cast<CARDS_RANK>(rank);
				card++;
			}
		}
	}

	void printDeck() {
		for (const auto &card : deck) {
			printCard(card);
			std::cout << ' ';
		}
	}

	void swapCard(Card &a, Card &b) {
		std::swap(a, b);
	}

	void shuffleDeck() {
		for (int i = 0; i < 52; i++) {
			std::random_device rd; // Use a hardware entropy source if available, otherwise use PRNG
			std::mt19937 rdm(rd()); // initialize our mersenne twister with a random seed
			swapCard(deck[i], deck[1 + (rdm() % 51)]);
		}
	}

	int getCardValue(const Card &card) {
		switch (card.rank)
		{
		case 10:
		case JACK:
		case QUEEN:
		case KING:
			return 10;
		case ACE:
			return 11;
		default:
			return card.rank;
		}
	}

	bool play() {
		//fillDeck(deck);
		//shuffleDeck(deck);
		std::cout << "The dealer is showing: " << getCardValue(deck[0]) << std::endl;
		//int track{};
		dealer += getCardValue(deck[track]);
		player += (getCardValue(deck[track + 1]) + getCardValue(deck[track + 2]));
		std::cout << "You have: " << player << std::endl;
		char stop{};
		int next{ 1 };
		while (stop != 's') {
			std::cout << "(h) to hit or (s) to stand: ";
			std::cin >> stop;
			std::cin.ignore(12313, '\n');
			if (stop == 'h') {
				player += getCardValue(deck[track + next + 2]);

				if (player > 21) {
					std::cout << player << " is bigger than 21. ";
					return EXIT_SUCCESS;
				}
				std::cout << "You have: " << player << std::endl;
			}

			next++;
		}
		while (dealer <= 17) {
			dealer += getCardValue(deck[track + next + 2]);
			std::cout << "The dealer now has: " << dealer << std::endl;
			next++;
		}
		if (dealer > 21) win = true;
		if (dealer < player && player <= 21) win = true;

		return win;

	}

};

#endif // !BLACK_JACK_H

