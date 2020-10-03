#include <string.h>
#include <vector>
#include <iostream>
#include "linkedlist.cpp"

using namespace std;

class chain {
    private:
    vector<linkedlist> chainVector;

    public:
        chain(int size) {
            //chainVector.reserve(size);
            chainVector = vector<linkedlist>(size);
        }

        int getChainSize() {
            return chainVector.size();
        }

        int primaryHash(int key) {
            return key % chainVector.size();
        }

        bool put(long long int key, string const& value) {    
            int slot = primaryHash(key);

            //if key already exists, return false;
            if (chainVector.at(slot).containsKey(key))
                return false;

            chainVector.at(slot).addnode(key, value);
            //cout<< slot <<endl; 
            //chainVector.at(slot).displayEntireList();
            return true;
        }

        pair<int, string> search(long long int key) {
            int slot = primaryHash(key);
            string nFound = "not found";
            if (!chainVector.at(slot).containsKey(key)) 
                return make_pair(-1, nFound);            

            string strResult = chainVector.at(slot).get(key); 
            strResult = strResult.empty() ? nFound : strResult;

            return make_pair(slot, strResult);
        }

        bool delete_by_key(long long int key) {
            int slot = primaryHash(key);

            //can't delete if doesn't exist:
            if (!chainVector.at(slot).containsKey(key))
                return false;

            return chainVector.at(slot).removeNode(key);
        }
};