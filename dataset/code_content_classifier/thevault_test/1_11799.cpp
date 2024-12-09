tuple<vector<vec4i>, vector<vec3f>> make_cube() {
    static auto cube_pos =
        vector<vec3f>{{-1, -1, -1}, {-1, +1, -1}, {+1, +1, -1}, {+1, -1, -1},
                      {-1, -1, +1}, {-1, +1, +1}, {+1, +1, +1}, {+1, -1, +1}};
    static auto cube_quads = vector<vec4i>{{0, 1, 2, 3}, {7, 6, 5, 4},
                                           {4, 5, 1, 0}, {6, 7, 3, 2}, {2, 1, 5, 6}, {0, 3, 7, 4}};
    static auto cube_quad_uv = vector<vec2f>{{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    return {cube_quads, cube_pos};
  }