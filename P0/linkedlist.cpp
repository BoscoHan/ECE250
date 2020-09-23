#include <iostream>
using namespace std;

#include <math.h>
using namespace std;

#include <cmath>
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
        node *temp=new node;
        temp=head;
        while(temp!=NULL) {
            cout<< temp->data <<" ";
            temp = temp->next;
        }
        cout<< endl;
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


