void Mesh::closeHoles() {
  // Find edges that only have one adjacent triangle (are next to a hole)
  bool inf = true;
  bool done = true;
  while (inf && done) {
    inf = false;
    done = false;
    for (int i = 0; i < edges_.size(); i++) {
      if (edges_[i].triangles_.size() == 1) {
        // Determine all edges that are adjacent to the current whole by
        // searching along the hole
        // This is achieved by following along the edges of the hole until the
        // starting vertex
        // is reached again
        int startVertex = edges_[i].vertices_[0];
        int lastVertex = startVertex;
        int lastEdge = i;
        std::vector<Index> currentHoleEdges;
        bool quit = false;
        while (!quit) {
          Vertex v = vertices_[lastVertex];
          for (int j = 0; j < v.edges_.size(); j++) {
            if (edges_[v.edges_[j]].triangles_.size() == 1 &&
                v.edges_[j] != lastEdge) {
              lastEdge = v.edges_[j];
              currentHoleEdges.push_back(lastEdge);
              if (lastVertex == edges_[lastEdge].vertices_[0]) {
                lastVertex = edges_[lastEdge].vertices_[1];
              } else {
                lastVertex = edges_[lastEdge].vertices_[0];
              }
              if (startVertex == lastVertex) {
                quit = true;
              }
              break;
            }
          }
          if (currentHoleEdges.size() > 10000) {
            inf = true;
            break;
          }
        }
        if (inf) {
          continue;
        }

        // Calculate the center point of all edges of the whole
        Vector3 mean = Vector3::Zero();
        for (int j = 0; j < currentHoleEdges.size(); j++) {
          for (int k = 0; k < 2; k++) {
            mean +=
                vertices_[edges_[currentHoleEdges[j]].vertices_[k]].position_;
          }
        }
        mean /= 2.0 * currentHoleEdges.size();
        Index centerVertex = addVertex(mean);

        // Fill the whole by adding the necessary triangles
        for (int j = 0; j < currentHoleEdges.size(); j++) {
          addTriangle(edges_[currentHoleEdges[j]].vertices_[0],
                      edges_[currentHoleEdges[j]].vertices_[1], centerVertex);
        }
        std::cout << "Filled hole with " << currentHoleEdges.size()
                  << " vertices" << std::endl;
        done = true;
      }
    }
  }
}