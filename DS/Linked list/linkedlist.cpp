#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct node{
    ll roll;
    node *next;
};

node *root, *tail;

void push(ll roll){
    if(root == NULL){
        root = new node();
        root->roll = roll;
        root->next = NULL;
        tail = root;
    }
    else{
        node *new_node = new node();
        new_node->roll = roll;
        new_node->next = NULL;
        tail->next = new_node;
        tail = tail->next;
    }
}

void delete_node(ll roll){
    node *curr_node = root;
    node *prev_node = NULL;

    while(curr_node->roll != roll){
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    if(curr_node == root){
        root = root->next;
    }
    else{
        prev_node->next = curr_node->next;
    }
    delete(curr_node);
}

void append_node(ll roll1, ll roll2){
    node *curr_node = root;
    node *prev_node = NULL;

    while(curr_node->roll != roll1){
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    node *new_node = new node();
    new_node->roll = roll2;
    new_node->next = curr_node->next;
    curr_node->next = new_node;
}

void print(){
    node *curr_node = root;
    while(curr_node != NULL){
        cout << curr_node->roll << endl;
        curr_node = curr_node->next;
    }
}

int main(){

    int i,j;

    push(2);
    push(3);
    append_node(2,4);
    push(5);
    delete_node(2);
    print();

}

