inline void dump(const glTFMeshPrimitiveMode& val, json& js, parse_stack& err) {
      static map<glTFMeshPrimitiveMode, int> table = {
          {glTFMeshPrimitiveMode::Points, 0},
          {glTFMeshPrimitiveMode::Lines, 1},
          {glTFMeshPrimitiveMode::LineLoop, 2},
          {glTFMeshPrimitiveMode::LineStrip, 3},
          {glTFMeshPrimitiveMode::Triangles, 4},
          {glTFMeshPrimitiveMode::TriangleStrip, 5},
          {glTFMeshPrimitiveMode::TriangleFan, 6},
      };
      auto v = table.at(val);
      dump(v, js, err);
    }