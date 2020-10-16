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
int processQ_MAX(string const& currCmd);
vector<string> split(const std::string &str, char delim);

const std::string insert_str = "i";
const std::string size_str = "size";
const std::string print_str = "print";
const std::string search_str = "s";
const std::string q_max_str = "q_max";

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
    } else if (first_token == q_max_str) {
        string cmdstr = currCmd.substr(currCmd.find(' ')+1, currCmd.size());

        auto q_MaxRes = processQ_MAX(cmdstr);
        if (q_MaxRes == -1) 
            cout << "failure" << endl;
        else 
            cout << "max " << q_MaxRes << endl;
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


int processQ_MAX(string const& currCmd) {
    auto cmdList = split(currCmd, ';');
    double longitude = stod(cmdList[0]);
    double latitude = stod(cmdList[1]);
    string direction = cmdList[2];
    string attribute = cmdList[3];

    TreeNode *refNode = root->findInTree(root, longitude, latitude);

    if (direction == "NE")
        refNode = refNode->NE;
    else if (direction == "NW")
        refNode = refNode->NW;
    else if (direction == "SW")
        refNode = refNode->SW;
    else if (direction == "SE")
        refNode = refNode->SE;

    if (attribute == "p") {
        int maxPopulation = -1;
        root->findMaxPopulation(refNode, maxPopulation);        
        return maxPopulation == -1 ? -1 : maxPopulation;

    } else if (attribute == "r") {

    } else if (attribute == "s") {

    }
}

void processSearch(string const& currCmd) {
    auto cmdList = split(currCmd, ';');
    auto searchResult = root->findInTree(root, stod(cmdList[0]), stod(cmdList[1]));    

    if (searchResult == nullptr)
        cout<< "not found" << endl;
    else
        cout << "found " << searchResult->info.name << endl;
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