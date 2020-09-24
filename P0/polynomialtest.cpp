/**
    ECE250
    Polynomialtest.cpp
    Purpose: Tester file for Polynonial class
    Invoke methods on polynomial class read from standard input
	and write expected output to standard output

    Author Tiuley Alguindigue
    Version 1.0  - 17/12/2019
*/

using namespace std;

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

#include "Polynomial.h" // Class to represent polynomials

void processString(std::string const& cmd);
void processCoeff(std::string const& cmd);
bool processGet(std::string const& cmdLn);
bool processAdd(std::string const& cmdLn);
std::vector<std::string> split(const std::string &str, char delim);

const std::string coeff_p1 = "coeff_p1";
const std::string coeff_p2 = "coeff_p2";
const std::string getStr = "get"; 
const std::string addStr = "add";

const double EPSILON = 0.00000001;
linkedlist *l1;
linkedlist *l2;

int main()
{
		string cmdline;

		getline(cin, cmdline);
		processString(cmdline);

		while (! cin.eof()) {
			if (cmdline == "exit") break;
			getline(cin, cmdline);

			processString(cmdline);
		}
		

	  /*   double p1_array[] = {0.0, 1.0, 3.0};
		Polynomial p1(3,p1_array); // 3 -terms - 0 + X + 3X**2
		cout << "p1: " << endl; 
		p1.print();
		cout << endl; 

		double p2_array[] = {1.0,0.0,1.0,2.0};
		Polynomial p2(4,p2_array);  //4-terms  1 + X**2 + 2X**3
		cout << "p2: " << endl; 
		p2.print();
		cout << endl; 


		Polynomial p3; // empty polynomial
		cout << "p3: " << endl; 
		p3.print();
		cout << endl; 

		Polynomial p1copy(p1); // declaring polynomial with value of p1
		cout << "p1copy: " <<  endl ;
		p1copy.print();
		cout << endl; 

		Polynomial p4;
		p4 = p1.add(p2); // needs = operator
		cout << "p4 = p1 + p2:  " << endl ;
		p4.print();
		cout << endl; 


        // adding with "+"
		Polynomial p5;
		p5 = p1 + p2;
		cout << "p5 = p1 + p2: " << endl ;
		p5.print();
		cout << endl;  */

		/*
		Add here your code to test other methods you implement
		Examples:

		- evaluate  (returns the value of polynomial at given x)
		- derivative (returns the polynomial representing the derivative)
		- diff (you could alternatively overraide "-" )
		- mult  (you could alternatively overraide "*" )
		*/

		delete l1;
		delete l2;
		return 0;
}


void processString(std::string const& currCmd) {
	//if curr line contains coeff_p1
	if (currCmd.find(coeff_p1) != std::string::npos) {
		processCoeff(currCmd);
		cout << "success" << endl;
	} else if (currCmd.find(coeff_p2) != std::string::npos) {
		processCoeff(currCmd);
		cout << "success" << endl;
	} else if (currCmd.find(getStr) != std::string::npos) {
		auto getResult = processGet(currCmd) ? "success" : "failure";
		cout << getResult << endl;

	} else if (currCmd.find(addStr) != std::string::npos) {
		auto getResult = processAdd(currCmd) ? "success" : "failure";
		cout << getResult << endl;
	}

}


bool processGet(std::string const& cmdLn) {
	vector<string> splited = split(cmdLn, ';'); 
	vector<double> coeffList(splited.size());
	
	for (int i = 0; i < splited.size(); i++) {
		//rm first whitespace
		auto pos = splited.at(i).find_first_not_of(' ');
		auto Trimmed = splited.at(i).substr(pos != std::string::npos ? pos : 0);

		//get have structure like this: get 0 14.0, we get the second element on first itr
		if (i == 0) {
			coeffList.at(i) = stod(split(Trimmed, ' ').at(2));			
			continue;
		}

		coeffList.at(i) = stod(split(Trimmed, ' ').at(1));
	}

	//read the linkedList into a list, compare length of both and contents:
	vector<double> listCopy;
	l1->copyList(listCopy);

	if (listCopy.size() != coeffList.size())
		return false;

	for (int i = 0; i < coeffList.size(); i++) {
		if (coeffList.at(i) != listCopy.at(i))
			return false;
	}

	return true;
}

bool processAdd(std::string const& cmdLn) {
	vector<string> splited = split(cmdLn, ';'); 
 	vector<double> coeffList(splited.size());

	for (int i = 0; i < splited.size(); i++) {
		//rm first whitespace
		auto pos = splited.at(i).find_first_not_of(' ');
		auto Trimmed = splited.at(i).substr(pos != std::string::npos ? pos : 0);

		//add have structure like this: get 0 14.0, we get the second element on first itr
		if (i == 0) {
			coeffList.at(i) = stod(split(Trimmed, ' ').at(2));			
			continue;
		}

		coeffList.at(i) = stod(split(Trimmed, ' ').at(1));
	} 

	vector<double> p1List;
	l1->copyList(p1List);

	vector<double> p2List;
	l2->copyList(p2List);

	vector<double> resultList;
	l1->addList(resultList, p1List, p2List);

	if (coeffList.size() != resultList.size()) 
		return false;

	for (int i = 0; i < resultList.size(); i++) {

		//comparing doubles abit tricky, since values aren't exact
		if (abs(resultList.at(i) - coeffList.at(i)) > EPSILON)  {
			return false;
		}
	}

	return true;
}


void processCoeff(std::string const& cmdLn) {
	vector<string> splited = split(cmdLn, ';'); 

	vector<string> cmdPair = split(splited.at(0), ' '); 
	string cmd = cmdPair.at(0); 
	int size = std::stoi(cmdPair.at(1));
	
	vector<double> coeffList(size);
	for (int i = 1; i < splited.size(); i++) {
		//rm first whitespace
		auto pos = splited.at(i).find_first_not_of(' ');
		auto Trimmed = splited.at(i).substr(pos != std::string::npos ? pos : 0);

		coeffList.at(i-1) = stod(split(Trimmed, ' ').at(1));
	}

	if (cmd == coeff_p1) {
		l1 = new linkedlist(size, &coeffList[0]);
		//l1->displayEntireList();
	}

	if (cmd == coeff_p2) {
		l2 = new linkedlist(size, &coeffList[0]);
		//l2->displayEntireList();
	}
}



std::vector<std::string> split(const std::string &str, char delim) {
	vector<string> result;
	stringstream s_stream(str); //create string stream from the string

	while(s_stream.good()) {
		string substr;
		getline(s_stream, substr, delim); //get first string delimitted
		result.push_back(substr);
	}

	return result;
}
