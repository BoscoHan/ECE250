/**
    ECE250
    Polynomial.h
    Purpose: Class to represent a polynomial with a single variable.
    Provides services to add, multiply and evaluate two polynomials.

    Author Tiuley Alguindigue
    Version 1.0  - 17/12/2019
*/

#include <iostream>
using namespace std;

// Polynomial for single variable X

class Polynomial {

    // class variables
	private:
	double    *coeff;  // coefficients
	int size ;  // degree + 1


    // class functions
    public:
    Polynomial (const int& size_p, const double coeff_p[]);
    Polynomial();
    ~Polynomial();

    // copy constructor and equal operator
    Polynomial (const Polynomial &polynomial_to_copy);
    Polynomial& operator=(const Polynomial& other) ;
	
	/* comparison operator == and != */

	bool operator==(const Polynomial& right );
	bool operator!=(const Polynomial& right );

    // add and +
	Polynomial add( const Polynomial& right) const ;
	Polynomial operator+(const Polynomial& right) ;
	
	// multiply
    Polynomial mult( const Polynomial& right) const ;
    //evaluate a polynomial
    double evaluate( const double &x) const ;
    double evaluate_horner( const double &x) const ;

    // print the polynomial
    void print();

};
