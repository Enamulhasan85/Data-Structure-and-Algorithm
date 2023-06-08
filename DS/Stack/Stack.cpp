#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct node{
    ll value;
    node *prev;
};

node *root, *head;

void push(ll value){
    if(root == NULL){
        root = new node();
        root->value = value;
        root->prev = NULL;
        head = root;
    }
    else{
        node *new_node = new node();
        new_node->value = value;
        new_node->prev = head;
        head = new_node;
    }
}

ll pop(){
    ll val = head->value;
    head = head->prev;
    return val;
}

void print(){
    node *curr_node = head;
    while(curr_node != NULL){
        cout << curr_node->value << endl;
        curr_node = curr_node->prev;
    }
}

int main(){

    int i,j;

    push(2);
    push(3);
    push(5);
    push(7);
    cout << pop() << endl;
    print();
}

