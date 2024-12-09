#include <iostream>
#include <string>
#include <set>
using namespace std;

struct Node {
    Node *left, *right;
    int h;
    Node() { left = right = NULL; h = 1; }
    bool operator==(const Node &n) const {
        if(h==1 || n.h==1) return h == n.h;
        return *left==*(n.left) && *right==*(n.right);
    }
    bool operator<(const Node &n) const {
        if(h!=n.h) return h<n.h;
        if(h==1) return false;
        if(!(*left==*(n.left))) return *left<*(n.left);
        return *right<*(n.right);
    }
};

int normalize(Node *root) {
    if(root->left == NULL) return 1;
    int l = normalize(root->left);
    int r = normalize(root->right);

    if(l > r) swap(root->left,root->right);
    root->h = max(l,r)+1;
    return root->h;
}

set<Node> subset(Node *root) {

    if(root->left == NULL) {
        set<Node> ret; ret.insert(*root);
        return ret;
    }
    set<Node> l = subset(root->left);
    l.insert(*root);
    set<Node> r = subset(root->right);
    for(set<Node>::iterator it = r.begin(); it != r.end(); ++it)
        l.insert(*it);

    return l;
}

double simu(Node *root) {
    if(root->left == NULL) return 0;
    set<Node> l = subset(root->left);
    set<Node> r = subset(root->right);

    set<Node> intersect;
    for(set<Node>::iterator it = l.begin(); it != l.end(); ++it)
        if(r.find(*it) != r.end()) intersect.insert(*it);
    for(set<Node>::iterator it = l.begin(); it != l.end(); ++it)
        r.insert(*it);

    return (double)(intersect.size())/(double)(r.size());
}

int strongp(Node *x,Node *y) { // x > y
    double xd = simu(x), yd = simu(y);
    if(xd != yd) {
        return xd < yd ? 1 : -1;
    }
    if(x->left == NULL && y->left == NULL) return 0;

    Node *xs = (strongp(x->left,x->right) >= 0)?x->left:x->right;
    Node *ys = (strongp(y->left,y->right) >= 0)?y->left:y->right;

    if(strongp(xs,ys) != 0)
        return (strongp(xs,ys)>=0)?1:-1;

    Node *xw = (strongp(x->left,x->right) >= 0)?x->right:x->left;
    Node *yw = (strongp(y->left,y->right) >= 0)?y->right:y->left;
    if(strongp(xw,yw) != 0)
        return (strongp(xw,yw)>0)?1:-1;
    return 0;
}

void leftsort(Node *root);
void rightsort(Node *root) {
    if(root->left == NULL) return;
    if(strongp(root->left,root->right) >= 0) swap(root->left, root->right);
    leftsort(root->left);
    rightsort(root->right);
}

void leftsort(Node *root) {
    if(root->left == NULL) return;
    if(strongp(root->right,root->left) >= 0) swap(root->left,root->right);
    leftsort(root->left);
    rightsort(root->right);
}

void output(Node *root) {
    if(root->left == NULL) {
        cout<<"x";
        return;
    }

    cout<<"(";
    output(root->left);
    cout<<" ";
    output(root->right);
    cout<<")";
}

string in;
int ridx;
Node* input(int idx) {
    if(in[idx] == '(') {
        Node *left = input(idx+1);
        Node *right = input(ridx+1);
        ridx++;
        Node *ret = new Node();
        ret->left = left;
        ret->right = right;
        return ret;
    }

    Node *ret = new Node();
    ret->left = ret->right = NULL;
    ridx = idx+1;
    return ret;
}

int main() {
    while(getline(cin, in)) {
        if(in == "0") break;
        Node *tree = input(0);
        normalize(tree);
        leftsort(tree);
        output(tree);
        cout<<endl;
    }
}