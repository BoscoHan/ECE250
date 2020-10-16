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
bool processInsertion(string const& currCmd);
void processSearch(string const& currCmd);
vector<string> split(const std::string &str, char delim);

const std::string insert_str = "i";
const std::string size_str = "size";
const std::string print_str = "print";
const std::string search_str = "s";

TreeNode *root;

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
    delete root;
    return 0;
}

void processString(string const& currCmd) {
    if (currCmd == "exit") return;

    string first_token = currCmd.substr(0, currCmd.find(' '));

    if (first_token == insert_str) {
        string cmdstr = currCmd.substr(currCmd.find(' ')+1, currCmd.size()); //strip first token char
		auto insertResult = processInsertion(cmdstr) == true ? "success" : "failure";
        cout << insertResult <<endl;
	} else if (first_token == size_str) {
        cout <<"tree size " << root->countNodes(root) << endl;
    } else if (first_token == print_str) {

        vector<string> list;
        root->printInorder(root, list);
        for (int i = 0; i < list.size(); i++) {
            cout <<list.at(i);
            if (i < list.size()-1)
                cout << " ";
        }
        cout << endl;

    } else if (first_token == search_str) {
        string cmdstr = currCmd.substr(currCmd.find(' ')+1, currCmd.size());
        processSearch(cmdstr);
    } 
}


bool processInsertion(string const& currCmd) {
    auto cmdList = split(currCmd, ';');
    string city_name = cmdList[0];
    double longitude = stod(cmdList[1]);
    double latitude = stod(cmdList[2]);
    int population = stoi(cmdList[3]);
    int livingCost = stoi(cmdList[4]);
    int avgSalary = stoi(cmdList[5]);
    CityInfo* info = new CityInfo(city_name, longitude, latitude, population, livingCost, avgSalary);


    if (root == NULL) {
        root = new TreeNode(*info);
        return true;
    }

    bool foundDuplciates[] =  {false};
    root->insertNode(root, info, foundDuplciates);
    
    return !foundDuplciates[0]; //return true if no duplicates found  
}

void processSearch(string const& currCmd) {
    auto cmdList = split(currCmd, ';');
    auto searchResult = root->findInTree(root, stod(cmdList[0]), stod(cmdList[1]));    

    if (searchResult == "")
        cout<< "not found" << endl;
    else
        cout << "found " << searchResult << endl;
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