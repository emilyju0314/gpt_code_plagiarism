#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxx = 28;
const int NIL = -1;
struct node {
	int parent,left,right;
};
node tree[maxx];

int get_depth(int x){
	int depth=0;
	while(tree[x].parent!=NIL){
		x=tree[x].parent;
		depth++;
	}
	return depth;
}

int get_height(int x){
	int h1=0,h2=0;
	if((tree[x].left==NIL)&&(tree[x].right==NIL)) return 0;
	if(tree[x].left!=NIL) h1=get_height(tree[x].left)+1;
	if(tree[x].right!=NIL) h2=get_height(tree[x].right)+1;
	return max(h1,h2);
}

int main (){
	for(int i = 0;i<maxx;i++) {
	tree[i].parent=NIL;
	tree[i].left=NIL;
	tree[i].right=NIL;	
	}
	int n;
	cin>>n;
	int a,b,c;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		tree[a].left=b;
		tree[a].right=c;
		if(b!=NIL) tree[b].parent=a;
		if(c!=NIL) tree[c].parent=a;
	}
	for(int i=0;i<n;i++){
		printf("node %d: parent = %d",i,tree[i].parent);
		if(tree[i].parent==NIL) printf(", sibling = -1");
		else if(tree[tree[i].parent].left==i) printf(", sibling = %d",tree[tree[i].parent].right);
		else printf(", sibling = %d",tree[tree[i].parent].left);
		if(tree[i].left!=NIL){
			if(tree[i].right!=NIL) printf(", degree = 2"); else printf(", degree = 1");
		}
		else{
			if(tree[i].right!=NIL) printf(", degree = 1"); else printf(", degree = 0");
		}
		printf(", depth = %d",get_depth(i));
		printf(", height = %d",get_height(i));
		if(tree[i].parent==NIL) printf(", root");
		else if(tree[i].left==NIL&&tree[i].right==NIL) printf(", leaf");
		else printf(", internal node");
		printf("\n");
	}
	return 0;
}
