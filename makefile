final: go_fish.o card.o player.o deck.o
	g++ -o gofish go_fish.o card.o player.o deck.o
go_fish.o: go_fish.cpp card.h player.h deck.h
	g++ -c go_fish.cpp  card.h player.h deck.h
player.o: player.cpp player.h card.h
	g++ -c player.cpp player.h card.h
deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp deck.h card.h
card.o: card.cpp card.h
	g++ -c -std=c++11 card.cpp card.h
