void SCCGraph::scR(const AstRelation* w, std::map<const AstRelation*, size_t>& preOrder, size_t& counter,
        std::stack<const AstRelation*>& S, std::stack<const AstRelation*>& P, size_t& numSCCs) {
    preOrder[w] = counter++;
    S.push(w);
    P.push(w);
    for (const AstRelation* t : precedenceGraph->graph().predecessors(w)) {
        if (preOrder[t] == (size_t)-1) {
            scR(t, preOrder, counter, S, P, numSCCs);
        } else if (relationToScc[t] == (size_t)-1) {
            while (preOrder[P.top()] > preOrder[t]) {
                P.pop();
            }
        }
    }
    if (P.top() == w) {
        P.pop();
    } else {
        return;
    }

    const AstRelation* v;
    do {
        v = S.top();
        S.pop();
        relationToScc[v] = numSCCs;
    } while (v != w);
    numSCCs++;
}