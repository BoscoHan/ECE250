/**
    ECE250
    Polynomial.cpp
    Purpose: Class to represent a polynomial with a single variable.
    Provides services such as add, multiply and evaluate two polynomials.

    Author Tiuley Alguindigue
    Version 1.0  - 17/12/2019
*/



#include <iostream>
using namespace std;

#include <math.h>
using namespace std;

#include <cmath>
using namespace std;

#include "Polynomial.h"

#include <algorithm>
/**
initializes current polynomial object with values in given array 

Params:
size_p int (in) - size of array
coeff_p[] double(in) - array with coefficients ie.{1.0,3.5,4.3} - corresponding to polynomial x + 3.5x + 4.3 X**2


*/

Polynomial::Polynomial (const int& size_p, const double coeff_p[]) {
 	size= size_p;
    coeff = new double[size];
    

    for(int i = 0; i < size_p; i++){
    		coeff[i] = coeff_p[i];

	}

 }



/**
initializes current polynomial object to 0 (empty polynomial)
*/
 Polynomial::Polynomial() {
 	coeff = 0;
 	size = 0;

 }


/**
copies polynomial in parameter to current polynomial object 
*/
Polynomial::Polynomial (const Polynomial &polynomial_to_copy){
	this->size = polynomial_to_copy.size ;
	coeff = new double[size];


	for(int i = 0; i < size; i++){
    	this->coeff[i] =  polynomial_to_copy.coeff[i] ;
	}

}


/**
Delete all elements of coeff array
*/
 Polynomial::~Polynomial() {
 	delete [] coeff ; // delete array that starts at address stored in coeff
 }
 
/**
Assignment operator - current and parameter passed

Params:
right Polynomial (in) -  second polynomial for assignment
Returns:
Polynomial - current object updated with assignment
*/
 

//
// assignment operator that is exception safe - uses the copy-swap idiom
Polynomial& Polynomial::operator=(const Polynomial& other) // copy assignment
{
	// make a copy of th eright hand side
	Polynomial temp(other);

	//Now, swap the data members with the temporary (exception safe)
	std::swap(size,temp.size);
	std::swap(coeff,temp.coeff);

	return *this ;

}


/**
Compare two polynomials - current and parameter passed

Params:
right Polynomial (in) -  second polynomial for comparison
Returns:
bool - true if equal, false if not equal
*/
bool Polynomial::operator==(const Polynomial& right )
{
	const double TOLERANCE = 0.02; //used when comparing double type
    if (right.size == size) {
        for(int i = 0 ; i < right.size; ++i){
            if( abs(right.coeff[i] - coeff[i])  >  TOLERANCE) return false;
        }
        return true;
    }

    return false ;

}


/**
Compare two polynomials - current and parameter passed

Params:
right Polynomial (in) -  second polynomial for comparison
Returns:
bool - true if not equal, false if equal
*/

bool Polynomial::operator!=(const Polynomial& right ){
    return !(*this == right);
}

/**
Add two polynomials: the current Polynomial object + Polynomial object passed as parameter


Params:
right Polynomial (in) -  second polynomial for addition
Returns:
Polynomial - result of addition
*/



Polynomial Polynomial::add( const Polynomial& right) const {
	 	int temp_size = max(this->size,right.size);

        double *temp = new double[temp_size]; // allocate temp array

        int t_max ;
        // if degree of right is the largest
	    if ( right.size > this->size) {

			 t_max = this->size;


			 for(int i = 0; i < t_max; i++){
	    		temp[i] = this->coeff[i] + right.coeff[i];
			}

			for(int i = t_max ; i < right.size ; i++){
	    		temp[i] = right.coeff[i] ;
			}


		}

		else //if degree of this-> is the largest
		if ( right.size <= this->size) {

			 t_max = right.size ;


			 for(int i = 0; i < t_max; i++){
	    		temp[i] = this->coeff[i] + right.coeff[i];
			}

			for(int i = t_max; i < this ->size ; i++){
	    		temp[i] = this -> coeff[i] ;
			}

		}


        Polynomial p(temp_size,temp) ;

        delete [] temp; // delete temp array

        return p;

	}
/**
Override operator "+"
Add two polynomials: the current Polynomial object + Polynomial object passed as parameter


Params:
right Polynomial (in) -  second polynomial for addition
Returns:
Polynomial - result of addition
*/



	Polynomial Polynomial::operator+(const Polynomial& right) {
		int temp_size = max(this->size,right.size);

        double *temp = new double[temp_size]; // allocate temp array

        int t_max ;
        // if degree of right is the largest
	    if ( right.size > this->size) {

			 t_max = this->size;


			 for(int i = 0; i < t_max; i++){
	    		temp[i] = this->coeff[i] + right.coeff[i];
			}

			for(int i = t_max ; i < right.size ; i++){
	    		temp[i] = right.coeff[i] ;
			}


		}

		else //if degree of this-> is the largest
		if ( right.size <= this->size) {

			 t_max = right.size ;


			 for(int i = 0; i < t_max; i++){
	    		temp[i] = this->coeff[i] + right.coeff[i];
			}

			for(int i = t_max; i < this ->size ; i++){
	    		temp[i] = this -> coeff[i] ;
			}

		}


        Polynomial p(temp_size,temp) ;

        delete [] temp; // delete temp array

        return p;


	}



 void Polynomial::print(){
    for(int i = 0; i < size; i++){
    	cout << coeff[i] << " ";
	}

	cout << endl ;
}
/**
Evaluate a polynomial at value x

Params:
x double (in) - value for calculation of polynomial f(x)

Returns:
double - value of f(x)
   
*/

 double Polynomial::evaluate( const double &x) const {
 	
 	
 	// TO DO
 		
	 
	return 0.0;

 }

 
/**
multiply two polynomials: the current Polynomial object x Polynomial object passed as parameter, using horner's rule for optimization

Params:
right Polynomial (in) -  second polynomial for multiplication
Returns:
Polynomial - result of multiplication
   
*/

double Polynomial::evaluate_horner( const double &x) const {
 	
   // TO DO

    return 0.0 ; 
 }
 
/**
multiply two polynomials: the current Polynomial object x Polynomial object passed as parameter

Params:
right Polynomial (in) -  second polynomial for multiplication
Returns:
Polynomial - result of multiplication
   
*/
 
 Polynomial Polynomial::mult( const Polynomial& right) const {
	 
	 // TO DO
 	
 	
 	
 	
 }
 
 


