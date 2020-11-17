#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <string.h>
#include <limits>
#include<iomanip>
using namespace std;

void processString(std::string const& cmd);
bool processInsertion(string const& currCmd);
void processSearch(string const& currCmd);
double processQ_MAX(string const& currCmd);
double processQ_MIN(string const& currCmd);
double processQ_Total(string const& currCmd);
vector<string> split(const std::string &str, char delim);

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
    return 0;
}

void processString(string const& currCmd) {

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