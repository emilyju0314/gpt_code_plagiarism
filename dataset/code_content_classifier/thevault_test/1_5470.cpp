BOOST_AUTO_TEST_CASE(test0)
{
  typedef boost::graph_traits<undirected_graph>::vertex_descriptor vertex_descriptor;
  typedef boost::graph_traits<undirected_graph>::edge_descriptor edge_descriptor;
  
  edge_t edges[] = {{0, 1}, {1, 2}, {2, 3},
    {0, 4}, {1, 4}, {1, 5}, {2, 6}, {3, 6}, {3, 7}, {4, 5}, {5, 6}, {6, 7}};
  weight_type ws[] = {2, 3, 4, 3, 2, 2, 2, 2, 2, 3, 1, 3};
  undirected_graph g(edges, edges + 12, ws, 8, 12);
  
  weight_map_type weights = get(boost::edge_weight, g);
  std::map<int, bool> parity;
  boost::associative_property_map<std::map<int, bool> > parities(parity);
  int w = boost::stoer_wagner_min_cut(g, weights, boost::parity_map(parities));
  BOOST_CHECK_EQUAL(w, 4);
  const bool parity0 = get(parities, 0);
  BOOST_CHECK_EQUAL(parity0, get(parities, 1));
  BOOST_CHECK_EQUAL(parity0, get(parities, 4));
  BOOST_CHECK_EQUAL(parity0, get(parities, 5));
  const bool parity2 = get(parities, 2);
  BOOST_CHECK_NE(parity0, parity2);
  BOOST_CHECK_EQUAL(parity2, get(parities, 3));
  BOOST_CHECK_EQUAL(parity2, get(parities, 6));
  BOOST_CHECK_EQUAL(parity2, get(parities, 7));
}