
struct node{
    ll l, r, mid, tree, op;
    node *left, *right;
    node(ll s, ll e){
        l = s, r = e, mid = (l+r)/2;
        tree = op = 0;
        left = right = NULL;
    }

    void push(ll val){
        op = val;
        tree += val;
    }

    void prop(){
        if(left==NULL) left = new node(l, mid);
        if(right==NULL) right = new node(mid+1, r);
        if(op==0) return;
        left->push(op);
        right->push(op);
        op = 0;
    }

    ll combine(ll a, ll b){
        return (a+b);
    }

    void update(ll b, ll e, ll val){
        prop();
        if(b<=l and r<=e){
            push(val);
            return;
        }
        if(e<l or r<b) return;
        left->update(b, e, val);
        right->update(b, e, val);
        tree = combine(left->tree, right->tree);
    }

    ll query(ll b, ll e){
        prop();
        if(b<=l and r<=e){
            return tree;
        }
        if(e<l or r<b) return 0;
        return combine(left->query(b, e),
                right->query(b, e));
    }
};
