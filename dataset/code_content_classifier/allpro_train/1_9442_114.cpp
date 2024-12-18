#include<iostream>
#include<cstdlib>
using namespace std;
struct Node{
	int key;
	Node *right, *left, *parent;
};
Node *root, *NIL;

Node *treeMinimum(Node *x){
	while(x->left != NIL)
		x=x->left;
	return x;
}
Node *treeSuccessor(Node *x){
	if(x->right!=NIL)	return treeMinimum(x->right);
	Node *y=x->parent;
	while(y!=NIL && x==y->right){
		x=y;
		y=y->parent;
	}
	return y;
}
void treeDelete(Node *z){
	Node *y;
	Node *x;
	if(z->left==NIL || z->right==NIL)	y=z;
	else	y=treeSuccessor(z);
	if(y->left!=NIL){
		x=y->left;
	}else{
		x=y->right;
	}
	if(x!=NIL)
		x->parent=y->parent;
	if(y->parent==NIL)
		root=x;
	else{
		if(y==y->parent->left)
			y->parent->left=x;
		else
			y->parent->right=x;
	}
	if(y!=z)
		z->key=y->key;
	free(y);
}

Node *find(Node *u, int k){
	while(u!=NIL && k!=u->key){
		if(k<u->key)	u=u->left;
		else	u=u->right;
	}
	return u;
}
void insert(int k){
	Node *y=NIL;
	Node *x=root;
	Node *z;
	z=(Node *)malloc(sizeof(Node));
	z->key=k;
	z->left=NIL;
	z->right=NIL;

	while(x!=NIL){
		y=x;
		if(z->key < x->key){
			x=x->left;
		}
		else
			x=x->right;
	}
	z->parent=y;
	if(y==NIL){
		root=z;
	}else{
		if(z->key < y->key){
			y->left=z;
		}else{
			y->right=z;
		}
	}
}
void inorder(Node *u){
	if(u==NIL)	return ;
	inorder(u->left);
	cout<<" "<<u->key;
	inorder(u->right);
}
void preorder(Node *u){
	if(u==NIL)	return ;
	cout<<" "<<u->key;
	preorder(u->left);
	preorder(u->right);
}
int main(){
	int n, i, x;
	string com;
	cin>>n;
	while(n--){
		cin>>com;
		if(com=="insert"){
			cin>>x;
			insert(x);
		}
		else if(com=="print"){
			inorder(root);
			cout<<endl;
			preorder(root);
			cout<<endl;
		}
		else if(com=="find"){
			cin>>x;
			Node *t=find(root, x);
			if(t!=NIL)	cout<<"yes"<<endl;
			else	cout<<"no"<<endl;
		}
		else if(com=="delete"){
			cin>>x;
			treeDelete(find(root, x));
		}
	}
	return 0;
}
