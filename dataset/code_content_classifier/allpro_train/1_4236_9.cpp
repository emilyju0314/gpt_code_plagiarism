#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>
using namespace std;

const int INF=1<<30;


/*
  Treap
  merge,split,insertが実装済み
  範囲の最小値も実装済み
  logオーダで各要素にindexでアクセスとかできる
 */
class Treap{
public:
  struct node_t{
    int val;// 値
    node_t *lch,*rch;// l,r
    int pri;// 優先度
    int cnt;// 部分木のサイズ
    int sum;// 部分木の値の和
    int minv;// 部分木の最小値
    node_t(int v,int p):val(v),pri(p),cnt(1),sum(v),minv(v){
      lch=rch=NULL;
    }
  };
  node_t* make_node(int val){
    return new node_t(val,rand());
  }
  int count(node_t *t){
    return !t?0:t->cnt;
  }
  int sum(node_t *t){
    return !t?0:t->sum;
  }
  int minimum(node_t *t){
    return !t?INF:t->minv;
  }
  node_t *update(node_t *t){
    t->cnt=count(t->lch)+count(t->rch)+1;
    t->sum=sum(t->lch)+sum(t->rch)+t->val;
    t->minv=min(t->val,min(minimum(t->lch),minimum(t->rch)));
    return t;
  }
  node_t *merge(node_t *l,node_t *r){
    if(!l||!r)return !l?r:l;
    // 優先順位が高い方を上に
    if(l->pri>r->pri){
      l->rch=merge(l->rch,r);
      return update(l);
    }
    else{
      r->lch=merge(l,r->lch);
      return update(r);
    }
  }
  // [0,k),[k,n)
  pair<node_t*,node_t*> split(node_t *t,int k){
    if(!t)return pair<node_t*,node_t*>(NULL,NULL);
    if(k<=count(t->lch)){
      pair<node_t*,node_t*> s=split(t->lch,k);
      t->lch=s.second;
      return make_pair(s.first,update(t));
    }
    else{
      pair<node_t*,node_t*> s=split(t->rch,k-count(t->lch)-1);
      t->rch=s.first;
      return make_pair(update(t),s.second);
    }
  }
  // posの値をvalに変更
  node_t *update(node_t *root,int pos,int val){
    pair<node_t*,node_t*> p1=split(root,pos);
    pair<node_t*,node_t*> p2=split(p1.second,1);
    delete p2.first;
    root=merge(p1.first,make_node(val));
    root=merge(root,p2.second);
    return root;
  }
  // posにvalの値を挿入
  // 半分未検証注意
  node_t *insert(node_t *root,int pos,int val){
    pair<node_t*,node_t*> p1=split(root,pos);
    root=merge(p1.first,merge(make_node(val),p1.second));
    return root;
  }
  // posの場所にある値をerase
  // 未検証注意
  node_t *erase(node_t *root,int pos,int val){
    pair<node_t*,node_t*> p1=split(root,pos);
    pair<node_t*,node_t*> p2=split(p1.second,1);
    root=merge(p1.first,p2.second);
    return root;
  }
  // [from,to]をcircular_shift
  node_t *circular_shift(node_t *root,int from,int to){
    pair<node_t*,node_t*> p1=split(root,from);
    pair<node_t*,node_t*> p2=split(p1.second,to-from+1);
    node_t* a=p1.first;
    node_t* b=p2.first;
    node_t* c=p2.second;
    pair<node_t*,node_t*> p3=split(b,to-from);
    b=merge(p3.second,p3.first);
    return merge(merge(a,b),c);
  }
  // [l,r)の最小値を計算
  int range_min_value(node_t *t,int l,int r){
    if(r<=l)return INF;
    // 範囲と個数が一致
    if(r-l==count(t))
      return minimum(t);
    // 左の子に完全に含まれる
    else if(count(t->lch)>=r)
      return range_min_value(t->lch,l,r);
    // 右の子に完全に含まれる
    else if(count(t->lch)<l)
      return range_min_value(t->rch,l-(count(t->lch)+1),r-(count(t->lch)+1));
    // 左と右に場合分けする
    return min(t->val,min(range_min_value(t->lch,l,count(t->lch))
                          ,range_min_value(t->rch,0,r-(count(t->lch)+1))));
  }
  // posの値を取り出す
  int getVal(node_t *t,int pos){
    return range_min_value(t,pos,pos+1);
  }
};

Treap tp;
int main(){
  Treap::node_t *root=NULL;
  int N,Q;
  cin>>N>>Q;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    root=tp.insert(root,i,a);
  }
  for(int i=0;i<Q;i++){
    int x,y,z;
    cin>>x>>y>>z;
    if(x==0)root=tp.circular_shift(root,y,z);
    else if(x==1)cout<<tp.range_min_value(root,y,z+1)<<endl;
    else if(x==2)root=tp.update(root,y,z);
  }
  
  
  return 0;
}