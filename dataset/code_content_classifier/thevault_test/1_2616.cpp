CpdFocalSearch(CpdFocalHeuristic<State, G, V>& heuristic, IGoalChecker<State>& goalChecker, IStateSupplier<State, nodeid_t, cpd_search_generated_e>& supplier, CpdFocalExpander<G, V>& expander, IStatePruner<State>& pruner, const CpdManager<G,V>& cpdManager, const fractional_number<cost_t>& focalListWeight, const fractional_number<cost_t>& epsilon) : Super2{},
            heuristic{heuristic}, goalChecker{goalChecker}, supplier{supplier}, expander{expander}, pruner{pruner},
            epsilon{epsilon}, cpdManager{cpdManager}
            {

            this->focalList = new FocalList<State, internal::OpenListOrderer<G,V>, internal::FocalListOrderer<G,V>, internal::GraphFocalStateGetCost<G,V>, cost_t>{focalListWeight};
            if (!heuristic.isConsistent()) {
                throw cpp_utils::exceptions::InvalidArgumentException{"the heuristic is not consistent!"};
            }
        }