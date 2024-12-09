void to_csv(const RMDP& rmdp, ostream& output, bool header = true) {

    //write header if so requested
    if(header){
        output << "idstatefrom," << "idaction," <<
            "idoutcome," << "idstateto," << "probability," << "reward" << endl;
    }

    //idstatefrom
    for(size_t i = 0l; i < rmdp.get_states().size(); i++){
        const auto& actions = rmdp.get_state(i).get_actions();
        //idaction
        for(size_t j = 0; j < actions.size(); j++){

            const auto& outcomes = actions[j].get_outcomes();
            //idoutcome
            for(size_t k = 0; k < outcomes.size(); k++){
                const auto& tran = outcomes[k];

                auto& indices = tran.get_indices();
                const auto& rewards = tran.get_rewards();
                const auto& probabilities = tran.get_probabilities();
                //idstateto
                for (size_t l = 0; l < tran.size(); l++){
                    output << i << ',' << j << ',' << k << ',' << indices[l] << ','
                            << probabilities[l] << ',' << rewards[l] << endl;
                }
            }
        }
    }
}