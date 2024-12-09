ModelSimulator(const shared_ptr<const MDP>& mdp, const Transition& initial, 
                        random_device::result_type seed = random_device{}()) :
                gen(seed), mdp(mdp), initial(initial){

        if(abs(initial.sum_probabilities() - 1) > SOLPREC)
            throw invalid_argument("Initial transition probabilities must sum to 1");
    }