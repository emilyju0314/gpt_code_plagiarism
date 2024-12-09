CpdHeuristic(const compressed_path_database::CpdManager<G, V>& cpdManager, const IImmutableGraph<G, V, PerturbatedCost>& perturbatedGraph): 
            cpdManager{cpdManager}, 
            hOriginalCache{cpdManager.getReorderedGraph().numberOfVertices(), cost_t::INFTY}, 
            hPerturbatedCache{cpdManager.getReorderedGraph().numberOfVertices(), cost_t::INFTY},
            lastPathActualCost{cost_t::INFTY}, lastPathOriginalCost{cost_t::INFTY}, 
            perturbatedGraph{perturbatedGraph} {

            debug("CPDHeuristic constructor start");
            if (!cpdManager.isCpdLoaded()) {
                throw cpp_utils::exceptions::InvalidStateException<compressed_path_database::CpdManager<G, V>>{cpdManager};
            }
            debug("CPDHeuristic constructor end");
        }