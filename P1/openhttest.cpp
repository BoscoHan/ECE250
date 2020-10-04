#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <string.h>
#include <tuple>
#include "openAddress.cpp"
using namespace std;

void processString(std::string const& cmd);
vector<string> split(const std::string &str, char delim);
void processInitialization(string const& currCmd);
bool processInsertion(string const& currCmd);
pair<int, string> processSearch(string const& currCmd);
bool processDeletion(string const& currCmd);

const std::string new_str = "n";
const std::string insert_str = "i";
const std::string delete_str = "d";
const std::string print_str = "p";
const std::string search_str = "s";

openAddress *_openAddress;

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

    delete _openAddress;
    return 0;
}

void processString(string const& currCmd) {
    if (currCmd == "exit") return;
    string first_token = currCmd.substr(0, currCmd.find(' '));

    if (first_token.find(new_str) != std::string::npos) {
		processInitialization(currCmd);
        cout << "success" << endl;

	} else if (first_token.find(insert_str) != std::string::npos) {
        //strip the first token char:
        string cmdstr = currCmd.substr(currCmd.find(' ')+1, currCmd.size());
        auto insertionResult = processInsertion(cmdstr) ? "success" : "failure";
        cout << insertionResult << endl;

    } else if (first_token.find(delete_str) != std::string::npos) {
        auto deleteResult = processDeletion(currCmd) ? "success" : "failure";
        cout << deleteResult << endl;

    } else if (first_token.find(search_str) != std::string::npos) {
        auto slot_name_pair = processSearch(currCmd);

        if (slot_name_pair.first == -1 && slot_name_pair.second == "not found") 
            cout << "not found" << endl;
         else 
            cout << "found " << slot_name_pair.second << " in " << slot_name_pair.first << endl;
    }
}

void processInitialization(string const& currCmd) {
    auto cmdList = split(currCmd, ' ');
    _openAddress = new openAddress(stoi(cmdList.at(1)));
}

bool processInsertion(string const& currCmd) {
    auto cmdList = split(currCmd, ';');

    return _openAddress->put(stoll(cmdList[0]), cmdList[1]);
}

bool processDeletion(string const& currCmd) {
    auto cmdList = split(currCmd, ' ');
    return _openAddress->delete_by_key(stoll(cmdList.at(1)));
}

pair<int, string> processSearch(string const& currCmd) {
    auto cmdList = split(currCmd, ' ');    
    auto searchRes = _openAddress->search(stoll(cmdList.at(1)));
    return searchRes;
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