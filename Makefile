all: polynomialtestdriver

polynomialtestdriver: polynomialtest.cpp Polynomial.cpp

	g++ -std=c++11 -o polynomialtestdriver polynomialtest.cpp Polynomial.cpp

clean:
	rm polynomialtestdriver