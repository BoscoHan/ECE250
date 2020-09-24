#include <iostream>

#include <math.h>

#include <cmath>
#include <vector>
using namespace std;

struct node {
	double data;
	node *next;
};	


class linkedlist
{
    private:
        node *head, *tail;
    public:
        linkedlist() {
            head=NULL;
            tail=NULL;
        }

        linkedlist(const int& size_p, const double coeff_p[]) {
            head=NULL;
            tail=NULL;

            for (int i = 0; i < size_p; i++) {
                this -> addnode(coeff_p[i]);
                
            }
        }

    void addnode (double value) {
        //create new node first:
        node * tempNode = new node;
        tempNode -> data = value;
        tempNode -> next = NULL;


        //if head not null, append to tail:
        if (head != NULL) {
            tail -> next = tempNode;
            tail = tempNode;
        } else {
            head = tempNode;
            tail = tempNode;
            tempNode = NULL;
        }
    }

    void displayEntireList()
    {
        node *temp = new node;
        temp = head;
        while(temp!=NULL) {
            cout<< temp->data <<" ";
            temp = temp->next;
        }
        cout<< endl;
    }

    //used for get
    void copyList(vector<double> &listCopy) {
        node * tempNode = new node;
        tempNode = head;

        while(tempNode != NULL) {
            listCopy.push_back(tempNode->data);
            tempNode = tempNode->next;
        }
        return;
    }

    void addList(vector<double> &resultList, vector<double> &p1List, vector<double> &p2List) {
        int p1 = 0, p2 = 0;

        while(p1List.size() > 0 || p2List.size() > 0) {
            if (p1List.size() == 0) {
                resultList.push_back(p2List.front());
                p2List.erase (p2List.begin());

            } else if (p2List.size() == 0) {
                resultList.push_back(p1List.front());
                p1List.erase (p1List.begin());

            } else {
                resultList.push_back(p2List.front() + p1List.front());
                p1List.erase (p1List.begin());
                p2List.erase (p2List.begin());
            }
        }
        return;
    }
    

    void delete_last()
    {
        node *current = new node;
        node *previous = new node;
        current=head;
        while(current->next!=NULL)
        {
            previous=current;
            current=current->next;	
        }
        tail=previous;
        previous->next=NULL;
        delete current;
    }

};


