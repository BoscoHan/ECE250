all: openhtdriver orderedhtdriver

openhtdriver: openhttest.cpp

	g++ -std=c++11 -g openhttest.cpp -o openhtdriver

orderedhtdriver: orderedhttest.cpp

	g++ -std=c++11 -g orderedhttest.cpp -o orderedhtdriver	
	
clean:
	rm orderedhtdriver
	rm openhtdriver