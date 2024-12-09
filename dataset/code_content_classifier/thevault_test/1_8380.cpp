dijkstra_graph(size_type n, size_type m)
        : n(n),
          m(m),
          nodes(n + 1),
          node_visited(n, false),
          edge_targets(m),
          edge_lengths(m),
          temp_edges(n)
    {
        std::mt19937_64 randgen(seed);
        std::uniform_int_distribution<size_type> distr_node(0, n - 1);
        std::uniform_int_distribution<size_type> distr;

        for (size_type i = 0; i < m; ++i) {
            size_type source = distr_node(randgen);
            size_type target = distr_node(randgen);
            size_type length = distr(randgen);
            temp_edges[source].push_back(std::make_pair(target, length));
        }

        size_type offset = 0;

        for (size_type i = 0; i < n; ++i) {
            nodes[i] = offset;

            for (size_type j = 0; j < temp_edges[i].size(); ++j) {
                edge_targets[offset + j] = temp_edges[i][j].key;
                edge_lengths[offset + j] = temp_edges[i][j].second;
            }

            offset += temp_edges[i].size();
        }

        nodes[n] = offset;
        temp_edges.clear();
    }