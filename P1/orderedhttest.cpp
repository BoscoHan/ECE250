#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <string.h>

using namespace std;

void processString(std::string const& cmd);

const std::string new_str = "n";
const std::string insert_str = "i";
const std::string delete_str = "d";
const std::string print_str = "p";
const std::string search_str = "s";

//Chaining
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

void processString(std::string const& currCmd) {
    if (currCmd == "exit") return;

    string first_token = currCmd.substr(0, currCmd.find(' '));

    if (first_token.find(new_str) != std::string::npos) {
		//processCoeff(currCmd);
		cout << "n" << endl;
	} else if (first_token.find(insert_str) != std::string::npos) {
        cout << "i" << endl;
    } else if (first_token.find(delete_str) != std::string::npos) {
        cout << "d" << endl;
    } else if (first_token.find(print_str) != std::string::npos) {
        cout << "p" << endl;
    } else if (first_token.find(search_str) != std::string::npos) {
        cout << "s" << endl;
    } 


}