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
        ~linkedlist() {
            delete head;
            delete tail;
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

    void displayEntireSortedList()
    {
        node *temp = new node;
        temp = head;
        temp = sortList(temp);

        while(temp!=NULL) {
            cout<< temp->key << " ";
            temp = temp->next;
        }
        cout<< endl;
    }

    //sort linkedlist by its keys in place recursively using mergeSort and return the head reference: 
    //time: O(NlogN), N = # of nodes, space: O(1)
    node* sortList(node* head) {
        if (head == NULL) return head;
        if (head->next == NULL) return head;
        
        node *p1 = head;
        node *p2 = head;
        node *pre = head;
        
        //at each iteration, p1 moves one, p2 moves two 
        //split the list in two halves, head points to beginning, p1 points to mid
        while (p2!=NULL && p2->next!=NULL) {
            pre = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        pre->next = NULL;
        
        node *head1 = sortList(head);
        node *head2 = sortList(p1);
        
        return mergeSort(head1, head2);
    }

    node* mergeSort (node *h1, node *h2) {
        if (h1 == NULL) return h2;
        if (h2 == NULL) return h1;
        
        if (h1->key < h2->key) {
            h1->next = mergeSort(h1->next, h2);
            return h1;
        } else {
            h2->next = mergeSort(h2->next, h1);
            return h2;
        }
    }

    bool isEmpty() {
        return head == NULL;
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
            if (temp->next->key == _key) {
                temp->next = temp->next->next;
            }
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

