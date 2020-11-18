#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <string.h>
#include <limits>
#include <iomanip>
#include "DisjointSet.cpp"
using namespace std;

const std::string n_str = "n";
const std::string i_str = "i";

void processString(std::string const& cmd);
void processN(string const& param);
void processI(string const& currCmd);
double processQ_MAX(string const& currCmd);
vector<string> split(const std::string &str, char delim);

DisjointSet * _ds;

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
    _ds->printDsuf();
    _ds->printAdjList();
    delete _ds;
    return 0;
}

void processString(string const& currCmd) {
    if (currCmd == "exit") return;
    string first_token = currCmd.substr(0, currCmd.find(' '));

    if (first_token == n_str) {
        string cmdstr = currCmd.substr(currCmd.find(' ')+1, currCmd.size()); //strip first token char
        processN(cmdstr);
        //_ds->printDsuf();

	} else if (first_token == i_str) {
        string cmdstr = currCmd.substr(currCmd.find(' ')+1, currCmd.size());
        
        processI(cmdstr);
    }
}

void processN(string const& param) {
    auto cmdList = split(param, ' ');
    int vertices = stoi(param);

    if (vertices <= 0 || cmdList.size() > 1){
        cout << "invalid argument" <<endl;
        return;
    }

    //initialize here
    _ds = new DisjointSet(vertices);
    cout << "success " << endl;
}

void processI(string const& currCmd) {
    auto cmdList = split(currCmd, ';');

    int from = stoi(cmdList[0]);
    int to = stoi(cmdList[1]);
    int weight = stoi(cmdList[2]);

    if (to < 0 || from < 0 || to > _ds->getV() || from > _ds->getV() || weight <= 0) {
        cout << "invalid argument" <<endl;
        return;
    }
    
    _ds->addWeightedEdge(from, to, weight);
    cout << "success " << endl;
}


vector<string> split(const std::string &str, char delim) {
	vector<string> result;
	stringstream s_stream(str); //create string stream from the string

	while(s_stream.good()) {
		string substr;
		getline(s_stream, substr, delim); //get first string delimitted
		result.push_back(substr);
	}
	return result;
}