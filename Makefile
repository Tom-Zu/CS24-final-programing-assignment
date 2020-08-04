CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

game: main.o cards.o
	$(CXX) $(CXXFLAGS) main.o cards.o -o game

main.o: main.cpp cards.h
	$(CXX) $(CXXFLAGS) main.cpp -c

cards.o: cards.cpp cards.h
	$(CXX) $(CXXFLAGS) cards.cpp -c

testcards.o: testcards.cpp testcards.h cards.h
	$(CXX) $(CXXFLAGS) testcards.cpp -c

testcards: testcards.o cards.o
	$(CXX) $(CXXFLAGS) testcards.o cards.o -o testcards
	
clean:
	rm -f main testcard *.o