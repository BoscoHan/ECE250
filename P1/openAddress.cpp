#include <string.h>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

enum class status { empty, deleted, occupied };

struct entry {
    long long key;
    string value;
    status status;
    entry (enum status st) : status(st) {}
};	

class openAddress {
    private:
    vector<entry> openVector;
    int curr_size; 

    public:
        openAddress(int size) {
            //chainVector.reserve(size);
            vector<entry>().swap(openVector);
            openVector = vector<entry>(size, entry(status::empty));  //initiate vector of entrys all with empty status
            curr_size = 0; 
        }

        bool isFull() {
            return curr_size == openVector.size();
        }

        int primaryHash(long long int key) {
            return key % openVector.size();
        }

        int secondaryHash(long long int key) {
            int val = floor(key/openVector.size());
            return val % openVector.size();
        }

        bool put(long long int key, string const& value) {
            if (isFull()) return false;

            int index = primaryHash(key);
            // cout<< "primary slot: " << index <<endl;
            // if collision occurs 
            if (openVector.at(index).status == status::occupied) {
                if (openVector.at(index).key == key) {
                    // cout << "BLOCKED INSERTING: "<< key << endl;
                    return false;
                }//block insertion of duplicate keys!

                int offset = secondaryHash(key);
                int i = 1; 
                while (1) {
                    // cout<< "collision occured slot: " << index << " offset: " << offset << " i: "<< i << endl;

                    int newIndex = (index + i * offset) % openVector.size(); 
                    // cout<< "attempting slot: " << newIndex <<endl;

                    if (openVector.at(newIndex).status == status::occupied && openVector.at(newIndex).key == key) {
                        // cout << "BLOCKED INSERTING: "<< key << endl;
                        return false;
                    }

                    //if collision resolved: 
                    if (openVector[newIndex].status != status::occupied) { 
                        openVector[newIndex].key = key; 
                        openVector[newIndex].value = value;
                        openVector[newIndex].status = status::occupied;
                        // cout<< "resolve collision, inserted in slot: " << newIndex <<endl;
                        break; 
                    }
                    i++;
                }
            } else {
                //no collision, simple insertion:
                openVector[index].key = key;
                openVector[index].value = value; 
                openVector[index].status = status::occupied;              
            }
            curr_size++;    
            
            return true;
        }

        bool delete_by_key(long long int key) {
            int index1 = primaryHash(key); 
            int index2 = secondaryHash(key); 
            int i = 0;
            int slot = (index1 + i * index2) % openVector.size();

            while (openVector[slot].key != key) {
                if (openVector[slot].status == status::empty) {
                    return false; //doesn't exist
                }
                i++;
                slot = (index1 + i * index2) % openVector.size();
            }           
            openVector[slot].status = status::deleted;
            return true;
        }

        pair<int, string> search(long long int key) 
        { 
            string nFound = "not found";
            int index1 = primaryHash(key); 
            int index2 = secondaryHash(key);   
            
            int i = 0;
            int slot = (index1 + i * index2) % openVector.size();

            while (openVector[slot].key != key) { 
                if (openVector[slot].status == status::empty) { 
                    return make_pair(-1, nFound);
                } 
                i++; 
                slot = (index1 + i * index2) % openVector.size();
            }

            if (openVector[slot].status == status::deleted) {
                return make_pair(-1, nFound);
            }

            return make_pair(slot, openVector[slot].value);
        } 
};