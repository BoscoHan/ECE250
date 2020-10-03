#include <iostream>

#include <math.h>

#include <cmath>
#include <vector>
using namespace std;

struct node {
    long long key;
    string value;

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

        linkedlist(long long key, string name) {
            head=NULL;
            tail=NULL;

            this -> addnode(key, name);
        }

    void addnode (long long _key, string name) {
        //create new node first:
        node * tempNode = new node;
        tempNode -> key = _key; 
        tempNode -> value = name;
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
            cout<< temp->key << ";";
            cout<< temp->value << endl;
            temp = temp->next;
        }
        cout<< endl;
    }

    // //used for get
    // void copyList(vector<double> &listCopy) {
    //     node * tempNode = new node;
    //     tempNode = head;

    //     while(tempNode != NULL) {
    //         listCopy.push_back(tempNode->data);
    //         tempNode = tempNode->next;
    //     }
    //     return;
    // }

    void addList(vector<double> &resultList, vector<double> &p1List, vector<double> &p2List) {

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
    

    bool containsKey(long long key) {
        node *temp = new node;
        temp = head;
        while(temp!=NULL) {
            if (temp-> key == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    string get(long long key) {
        node *temp = new node;
        temp = head;
        while(temp!=NULL) {
            if (temp-> key == key)
                return temp->value;
            temp = temp->next;
        }
        return NULL;
    }

    bool removeNode(long long _key) {
        node *temp = new node;
        temp = head;

        while (temp && temp->next) {
            if (temp->next->key == _key) 
                temp->next = temp->next->next;
             else 
                temp = temp->next;           
        }

        if (head && head->key == _key) 
            head = head->next;

        return true;
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

