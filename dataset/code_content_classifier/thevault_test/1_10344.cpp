inline
RMDP robustify(const MDP& mdp, bool allowzeros = false){
    // construct the result first
    RMDP rmdp;
    // iterate over all starting states (at t)
    for(size_t si : indices(mdp)){
        const auto& s = mdp[si];
        auto& newstate = rmdp.create_state(si);
        for(size_t ai : indices(s)){
            // make sure that the invalid actions are marked as such in the rmdp
            if(!s.is_valid(ai)){
                newstate.set_valid(ai,false);
                continue;
            }
            auto& newaction = newstate.create_action(ai);
            const Transition& t = s[ai].get_outcome();
            // iterate over transitions next states (at t+1) and add samples
            if(allowzeros){ // add outcomes for states with 0 transition probability
                numvec probabilities = t.probabilities_vector(mdp.state_count());
                numvec rewards = t.rewards_vector(mdp.state_count());
                for(size_t nsi : indices(probabilities)){
                    // create the outcome with the appropriate weight
                    Transition& newoutcome = 
                        newaction.create_outcome(newaction.size(), 
                                                probabilities[nsi]);
                    // adds the single sample for each outcome
                    newoutcome.add_sample(nsi, 1.0, rewards[nsi]);
                }    
            }
            else{ // add outcomes only for states with non-zero probabilities
                for(size_t nsi : indices(t)){
                    // create the outcome with the appropriate weight
                    Transition& newoutcome = 
                        newaction.create_outcome(newaction.size(), 
                                                t.get_probabilities()[nsi]);
                    // adds the single sample for each outcome
                    newoutcome.add_sample(t.get_indices()[nsi], 1.0, t.get_rewards()[nsi]);
                }    
            }
        }
    }    
    return rmdp;
}