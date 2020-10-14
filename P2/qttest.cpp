#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <string.h>
#include <tuple>
#include "TreeNode.cpp"
using namespace std;

void processString(std::string const& cmd);

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
    if (currCmd == "exit") return;

    string first_token = currCmd.substr(0, currCmd.find(' '));

}