void to_csv(const MDP& mdp, ostream& output, bool header = true) {
    //write header if so requested
    if(header){
        output << "idstatefrom," << "idaction," << "idstateto," << "probability," << "reward" << endl;
    }

    //idstatefrom
    for(size_t i = 0l; i < mdp.get_states().size(); i++){
        const auto& actions = mdp.get_state(i).get_actions();
        //idaction
        for(size_t j = 0; j < actions.size(); j++){
            const auto& tran = actions[j].get_outcome();

            const auto& indices = tran.get_indices();
            const auto& rewards = tran.get_rewards();
            const auto& probabilities = tran.get_probabilities();
            //idstateto
            for (size_t l = 0; l < tran.size(); l++){
                output << i << ',' << j << ',' << indices[l] << ','
                        << probabilities[l] << ',' << rewards[l] << endl;
            }
        }
    }
}