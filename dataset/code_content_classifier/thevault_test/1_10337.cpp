RandomizedPolicy(const Sim& sim, const vector<numvec>& probabilities,random_device::result_type seed = random_device{}()):
        gen(seed), distributions(probabilities.size()), sim(sim){

        for(auto pi : indices(probabilities)){
            
            // check that this distribution is correct
            const numvec& prob = probabilities[pi];
            prec_t sum = accumulate(prob.begin(), prob.end(), 0.0);
            
            if(abs(sum - 1) > SOLPREC){
                throw invalid_argument("Action probabilities must sum to 1 in state " + to_string(pi));
            } 
            distributions[pi] = discrete_distribution<long>(prob.begin(), prob.end());
        }
    }