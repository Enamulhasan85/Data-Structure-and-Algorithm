#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct node{
    bool endmark;
    node *next[26+1];
    node(){
        for(ll i=0;i<26;i++) next[i] = NULL;
        endmark = false;
    }
};

node *root;

void insert(string s){
    ll n = s.size();
    node *curr = root;
    for(ll i=0;i<n;i++){
        if(curr->next[s[i]-'a']==NULL) curr->next[s[i]-'a'] = new node();
        curr = curr->next[s[i]-'a'];
    }
    curr->endmark = 1;
}

bool search(string s){
    ll n = s.size();
    node *curr = root;
    for(ll i=0;i<n;i++){
        if(curr->next[s[i]-'a']==NULL) return false;
        curr = curr->next[s[i]-'a'];
    }
    return curr->endmark;
}

void del(node* curr){
    for(ll i=0;i<26;i++){
        if(curr->next[i]!=NULL) del(curr->next[i]);
    }
    delete (curr);
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //seive(1e6+2);
    root = new node();
    ll i, n;
    cin >> n;
    for(i=0;i<n;i++){
        string s;
        cin >> s;
        insert(s);
    }
    ll q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        if(search(s)) cout << "Found" << endl;
        else cout << "Not Found" << endl;
    }
    del(root);
}
