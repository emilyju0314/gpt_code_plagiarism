inline
pair<numvec,prec_t> worstcase_l1(numvec const& z, numvec const& q, prec_t t){
    assert(*min_element(q.cbegin(), q.cend()) >= - THRESHOLD);
    assert(*max_element(q.cbegin(), q.cend()) <= 1 + THRESHOLD);
    assert(z.size() > 0);
    assert(t >= 0.0 && t <= 2.0);
    assert(z.size() == q.size());

    size_t sz = z.size();

    vector<size_t> smallest = sort_indexes<prec_t>(z);
    numvec o(q);

    auto k = smallest[0];
    auto epsilon = min(t/2, 1-q[k]);

    o[k] += epsilon;

    auto i = sz - 1;
    while(epsilon > 0){
        k = smallest[i];
        auto diff = min( epsilon, o[k] );
        o[k] -= diff;
        epsilon -= diff;
        i -= 1;
    }

    auto r = inner_product(o.begin(),o.end(),z.begin(), (prec_t) 0.0);
    return make_pair(move(o),r);
}