tuple<vector<vec4i>, vector<vec3f>, vector<vec4i>, vector<vec2f>>
  make_fvcube() {
    static auto cube_pos =
        vector<vec3f>{{-1, -1, -1}, {-1, +1, -1}, {+1, +1, -1}, {+1, -1, -1},
                      {-1, -1, +1}, {-1, +1, +1}, {+1, +1, +1}, {+1, -1, +1}};
    static auto cube_qpos = vector<vec4i>{{0, 1, 2, 3}, {7, 6, 5, 4},
                                          {4, 5, 1, 0}, {6, 7, 3, 2}, {2, 1, 5, 6}, {0, 3, 7, 4}};
    static auto cube_texcoord = vector<vec2f>{{0, 0}, {1, 0}, {1, 1}, {0, 1},
                                              {0, 0}, {1, 0}, {1, 1}, {0, 1}, {0, 0}, {1, 0}, {1, 1}, {0, 1}, {0, 0},
                                              {1, 0}, {1, 1}, {0, 1}, {0, 0}, {1, 0}, {1, 1}, {0, 1}, {0, 0}, {1, 0},
                                              {1, 1}, {0, 1}};
    static auto cube_qtexcoord = vector<vec4i>{{0, 1, 2, 3}, {4, 5, 6, 7},
                                               {8, 9, 10, 11}, {12, 13, 14, 15}, {16, 17, 18, 19}, {20, 21, 22, 23}};
    return {cube_qpos, cube_pos, cube_qtexcoord, cube_texcoord};
  }