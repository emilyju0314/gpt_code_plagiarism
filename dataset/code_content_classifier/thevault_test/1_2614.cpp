CpdJumpTrailSearch(CpdFocalHeuristic<State, G, V>& heuristic, IGoalChecker<State>& goalChecker, Supplier& supplier, Expander& expander, IStatePruner<State>& pruner, const CpdManager<G,V>& cpdManager, fractional_cost epsilon, unsigned int openListCapacity = 1024) : Super2{},
            heuristic{heuristic}, goalChecker{goalChecker}, supplier{supplier}, expander{expander}, pruner{pruner},
            epsilon{epsilon}, cpdManager{cpdManager},
            openList{nullptr} {
                debug("CpdJumpTrailSearch constructor started!");
                if (!heuristic.isConsistent()) {
                    throw cpp_utils::exceptions::InvalidArgumentException{"the heuristic is not consistent!"};
                }
                this->openList = new StaticPriorityQueue<State>{openListCapacity, true};
                debug("CpdJumpTrailSearch constructor ended!");
            }