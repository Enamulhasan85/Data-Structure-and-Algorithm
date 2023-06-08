#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct node{
    ll value;
    node *next;
};

node *tail, *head;

void enqueue(ll value){
    if(head == NULL){
        head = new node();
        head->value = value;
        head->next = NULL;
        tail = head;
    }
    else{
        node *new_node = new node();
        new_node->value = value;
        new_node->next = NULL;
        tail->next = new_node;
        tail = tail->next;
    }
}

ll dequeue(){
    if(head==NULL) return NULL;
    ll val = head->value;
    node *tmp = head;
    head = head->next;
    delete tmp;
    return val;
}

void print(){
    node *curr_node = head;
    while(curr_node != NULL){
        cout << curr_node->value << endl;
        curr_node = curr_node->next;
    }
}

int main(){

    int i,j;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    enqueue(2);
    enqueue(3);
    dequeue();
    dequeue();
    enqueue(5);
    enqueue(7);
    dequeue();
    cout << dequeue() << endl;
    print();
}

