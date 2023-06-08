#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct node{
    ll roll;
    node *left,*right;
    node() //initialize the node using null
	{
		left=NULL;
		right=NULL;
	}
};

node *root;

void insert_node(ll roll){
    if(root == NULL){
        root = new node();
        root->roll = roll;
    }
    else{
        node *curr_node = root, *parent;
        while(curr_node != NULL){
            if(curr_node->roll <= roll){
                parent = curr_node;
                curr_node = curr_node->right;
            }
            else{
                parent = curr_node;
                curr_node = curr_node->left;
            }
        }
        node *newnode = new node();
        newnode->roll = roll;
        if(parent->roll <= roll) parent->right = newnode;
        else parent->left = newnode;
    }
}

struct node* minvalright(struct node* curr_node){
    node *parent = NULL;
    while(curr_node->left!=NULL){
        parent = curr_node;
        curr_node = curr_node->left;
    }
    return parent;
}

void delete_node(ll roll){
    node *curr_node = root, *parent = NULL;
    while(curr_node->roll != roll){
        if(curr_node->roll <= roll){
            parent = curr_node;
            curr_node = curr_node->right;
        }
        else{
            parent = curr_node;
            curr_node = curr_node->left;
        }
    }
    //cout << curr_node->roll << endl;
    if(curr_node->left==NULL and curr_node->right==NULL){
        if(parent->left == curr_node) parent->left = NULL;
        else if(parent->right == curr_node) parent->right = NULL;
        free(curr_node);
    }
    else if(curr_node->left==NULL ){
        if(parent->left == curr_node) parent->left = curr_node->right;
        else if(parent->right == curr_node) parent->right = curr_node->right;
        free(curr_node);
    }
    else if(curr_node->right==NULL ){
        if(parent->left == curr_node) parent->left = curr_node->left;
        else if(parent->right == curr_node) parent->right = curr_node->left;
        free(curr_node);
    }
    else{
        node *tmp = minvalright(curr_node->right);
        curr_node->roll = tmp->left->roll;
        free(tmp->left);
        tmp->left = NULL;
    }
}

void print(node *curr_node){
    if(curr_node == NULL) return;
    cout << curr_node->roll << endl;
    print(curr_node->left);
    print(curr_node->right);
}

int main(){

    ll i,j;
    insert_node(50);
    insert_node(150);
    insert_node(90);
    insert_node(75);
    insert_node(25);
    print(root);
    delete_node(50);
    //cout << root->right->roll << endl;
    print(root);

}
