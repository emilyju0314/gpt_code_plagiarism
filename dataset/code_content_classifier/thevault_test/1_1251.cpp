void HelloVulkan::fillLanternVerts(std::vector<nvmath::vec3f>& vertices, std::vector<uint32_t>& indices)
{
  // Create a spherical lantern model by recursively tesselating an octahedron.
  struct VertexIndex
  {
    nvmath::vec3f vertex;
    uint32_t      index;  // Keep track of this vert's _eventual_ index in vertices.
  };
  struct Triangle
  {
    VertexIndex vert0, vert1, vert2;
  };

  VertexIndex posX{{m_lanternModelRadius, 0, 0}, 0};
  VertexIndex negX{{-m_lanternModelRadius, 0, 0}, 1};
  VertexIndex posY{{0, m_lanternModelRadius, 0}, 2};
  VertexIndex negY{{0, -m_lanternModelRadius, 0}, 3};
  VertexIndex posZ{{0, 0, m_lanternModelRadius}, 4};
  VertexIndex negZ{{0, 0, -m_lanternModelRadius}, 5};
  uint32_t    vertexCount = 6;

  // Initial triangle list is octahedron.
  std::vector<Triangle> triangles{{posX, posY, posZ}, {posX, posY, negZ}, {posX, negY, posZ}, {posX, negY, negZ},
                                  {negX, posY, posZ}, {negX, posY, negZ}, {negX, negY, posZ}, {negX, negY, negZ}};

  // Recursion: every iteration, convert the current model to a new
  // model by breaking each triangle into 4 triangles.
  for(int recursions = 0; recursions < 3; ++recursions)
  {
    std::vector<Triangle> new_triangles;
    for(const Triangle& t : triangles)
    {
      // Split each of three edges in half, then fixup the
      // length of the midpoint to match m_lanternModelRadius.
      // Record the index the new vertices will eventually have in vertices.
      VertexIndex v01{m_lanternModelRadius * nvmath::normalize(t.vert0.vertex + t.vert1.vertex), vertexCount++};
      VertexIndex v12{m_lanternModelRadius * nvmath::normalize(t.vert1.vertex + t.vert2.vertex), vertexCount++};
      VertexIndex v02{m_lanternModelRadius * nvmath::normalize(t.vert0.vertex + t.vert2.vertex), vertexCount++};

      // Old triangle becomes 4 new triangles.
      new_triangles.push_back({t.vert0, v01, v02});
      new_triangles.push_back({t.vert1, v01, v12});
      new_triangles.push_back({t.vert2, v02, v12});
      new_triangles.push_back({v01, v02, v12});
    }
    triangles = std::move(new_triangles);
  }

  vertices.resize(vertexCount);
  indices.clear();
  indices.reserve(triangles.size() * 3);

  // Write out the vertices to the vertices vector, and
  // connect the tessellated triangles with indices in the indices vector.
  for(const Triangle& t : triangles)
  {
    vertices[t.vert0.index] = t.vert0.vertex;
    vertices[t.vert1.index] = t.vert1.vertex;
    vertices[t.vert2.index] = t.vert2.vertex;
    indices.push_back(t.vert0.index);
    indices.push_back(t.vert1.index);
    indices.push_back(t.vert2.index);
  }
}