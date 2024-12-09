void fix(int node, int color){
    if(color != 0){
        if(seen[node] == 1){
            remove(color);
        }else{
            add(color);
        }
        seen[node] ^= 1;
    }
}