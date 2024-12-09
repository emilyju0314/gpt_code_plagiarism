MDPI(const shared_ptr<const MDP>& mdp, const indvec& state2observ, const Transition& initial):
             mdp(mdp), state2observ(state2observ), initial(initial),
              obscount(1+max_value(state2observ)),
              action_counts(obscount, -1){
        check_parameters(*mdp, state2observ, initial);

        for(auto state : range((size_t) 0, mdp->state_count())){
            auto obs = state2observ[state];

            // check the number of actions
            auto ac = mdp->get_state(state).action_count();
            if(action_counts[obs] >= 0){
                if(action_counts[obs] != (long) ac){
                    throw invalid_argument("Inconsistent number of actions: " + to_string(ac) +
                                           " instead of " + to_string(action_counts[obs]) +
                                           " in state " + to_string(state));
                }
            }else{
                action_counts[obs] = ac;
            }
        }
    }