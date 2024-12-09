void update(int id, int l, int r, int k, ll val){   /// O(log n)
    //int id, int l, int r means currently in which id and l ,r for which range
    // example:( a range of value from 10 to 80 and here we havse started form bopttom and  added the sums and made this and assigned id)
    //id1:360
    //id2:100                         id3:260
    //id4:30             id5:70       id6:110          id7:150
    //id8:10 id9:20 id9:30 id10:40 id11:50 id12:60 id13:70 id14:80
    //value:10    20     30      40      50    60       70         80
    //index: 1    2       3      4        5     6       7           8
    // here id1:360 whose l=1 and r=n or 8;id 2:100 which actullay has l=1 , r=4 means that from index 1 to 4, if we sum that then one time we got 100 and thus for id6:110, we have l=5 and
    // base case  (Updating child )

    if(l == r){
        tree[id] = val;
        return;
    }

    //devide and conquer
    int mid = (l+r)/2;

    /// left child -> l, mid        right child -> mid+1, r

    if(k <= mid)
        update(2*id, l, mid, k, val);
    else
        update(2*id+1, mid+1, r, k, val);

    //Updating sum as child has been updated
    tree[id] = min(tree[2*id], tree[2*id+1]);
    return;
}