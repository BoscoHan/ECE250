#include <string.h>
#include <vector>
#include <iostream>

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

    public:
        openAddress(int size) {
            //chainVector.reserve(size);
            vector<entry>().swap(openVector);
            openVector = vector<entry>(size, entry(status::empty));  //initiate vector of entrys all with empty status
        }

        int getOpenAddressVectorSize() {
            return openVector.size();
        }

        void printOccupancyStatus() {
            for (int i = 0; i < getOpenAddressVectorSize(); i++) {
                auto occupancy = openVector.at(i).status == status::empty ? "empty" : "occupied";
                cout << occupancy << endl;
            }
        }

};