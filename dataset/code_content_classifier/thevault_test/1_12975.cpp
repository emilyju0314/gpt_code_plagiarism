void Bitwidth::garbage_collect_support_structures(XEdge_iterator &inp_edges) {
  for (auto e : inp_edges) {
    auto pit = outcountmap.find(e.driver.get_node().get_compact());  // pit = parent iterator
    if (pit == outcountmap.end()) {
      continue;  // parent node not yet visited
    }

    auto n = pit->second;
    if (n <= 1) {  // I'm the only child, the parent bw_range object could be recycled
      outcountmap.erase(pit);
      for (auto parent_dpin : e.driver.get_node().out_connected_pins()) {
        auto it2 = bwmap.find(parent_dpin.get_compact());
        if (it2 != bwmap.end()) {  // Not all the nodes create bwmap (impossible to infer do not)
          forward_adjust_dpin(parent_dpin, it2->second);
          bwmap.erase(it2);
        }
      }
    } else {
      pit->second = n - 1;
    }
  }
}