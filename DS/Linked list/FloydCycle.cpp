#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct node{
    ll data;
    node *next;
    node(){
        next = NULL;
    }
};

node *root = NULL, *tail = NULL;

node* detectcycle(node *curr_node){
    if(!curr_node->next) return NULL;
    node *hare = curr_node, *tortoise = curr_node;

    while(hare){
        if(hare->next and hare->next->next) hare = hare->next->next;
        else return NULL;
        tortoise = tortoise->next;
        if(hare == tortoise) break;
    }
    node* tortoise2 = curr_node;
    while(tortoise2 != tortoise){
        tortoise2 = tortoise2->next;
        tortoise = tortoise->next;
    }
    return tortoise;
}

void append(ll data){
    if(root==NULL){
        root = new node();
        root->data = data;
        tail = root;
    }
    else{
        node *new_node = new node();
        new_node->data = data;
        tail->next = new_node;
        tail = tail->next;
    }
}

void print(){
    node *curr_node = root;
    while(curr_node != NULL){
        cout << curr_node->data << endl;
        curr_node = curr_node->next;
    }
}

int main(){
    ll n, i;
    cin >> n;
    for(i=0;i<n;i++){
        ll x; cin >> x;
        append(x);
    }
    print();
    node *newnode = new node();
    newnode->data = 66;
    newnode->next = root->next->next;
    tail->next = newnode;

    node* cyclenode = detectcycle(root);
    if(cyclenode!=NULL) cout << cyclenode->data << endl;
    else cout << "No Cycle" << endl;
    print();

    return 0;
}
