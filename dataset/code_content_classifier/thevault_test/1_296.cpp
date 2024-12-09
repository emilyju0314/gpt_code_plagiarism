int backtrack(struct node cur, int i, int p, int alpha, int beta){
    if (i == n){
        return evaluate(cur);
    }

    int j, k, x;
    vector <struct node> ar = transition(cur, deck[i], p);

    for (j = 0; j < ar.size(); j++){
        x = backtrack(ar[j], i + 1, p ^ 1, alpha, beta);
        if (p == 0 && x > alpha) alpha = x; /// First player will maximize his score
        if (p == 1 && x < beta) beta = x; /// Second player will minimize his score
        if (alpha >= beta) break;
    }

    if (p == 0) return alpha;
    return beta;
}