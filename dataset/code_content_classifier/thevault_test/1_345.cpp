void Imc::InitializeGroups()
{
    if(!_do_imc) return;
    map<string, group_t *>::iterator group_iter;

    // clear all the pairs
    
    // iterator over all groups
    for (group_iter = _groups.begin(); group_iter != _groups.end(); ++group_iter) {
        group_t *grp = (*group_iter).second;      
        grp->_pairs.clear();
    
        int n = 0;
        // count number of bins needed in matrix
        for (list<interaction_t*>::iterator i1 = grp->_interactions.begin();
                i1 != grp->_interactions.end(); ++i1)
            n+=(*i1)->_average.getNBins();
    
        // handy access to matrix
        group_matrix &M = grp->_corr;
        
        // initialize matrix with zeroes
        M.resize(n,n);
        M = ub::zero_matrix<double>(n, n);
        
        // now create references to the sub matrices
        int i, j;
        i=0;j=0;
        // iterate over all possible compinations of pairs
        for (list<interaction_t*>::iterator i1 = grp->_interactions.begin();
                i1 != grp->_interactions.end(); ++i1) {
            int n1 = (*i1)->_average.getNBins();
            j = i;
            for (list<interaction_t*>::iterator i2 = i1;
                    i2 != grp->_interactions.end(); ++i2) {
                int n2 = (*i2)->_average.getNBins();
                
                // create matrix proxy with sub-matrix
                pair_matrix corr(M, ub::range(i, i+n1), ub::range(j, j+n2));
                // add the pair
                grp->_pairs.push_back(pair_t(*i1, *i2, i, j, corr));
                j+=n2;
            }
            i+=n1;
        }
    }
}