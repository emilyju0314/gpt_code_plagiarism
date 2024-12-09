tuple<vector<vec4i>, vector<vec3f>, vector<vec3f>, vector<vec2f>> make_uvcube(
      int usteps, int vsteps) {
    frame3f frames[6] = {frame3f{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {0, 0, 1}},
                         frame3f{{-1, 0, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, -1}},
                         frame3f{{-1, 0, 0}, {0, 0, 1}, {0, 1, 0}, {0, 1, 0}},
                         frame3f{{1, 0, 0}, {0, 0, 1}, {0, -1, 0}, {0, -1, 0}},
                         frame3f{{0, 1, 0}, {0, 0, 1}, {1, 0, 0}, {1, 0, 0}},
                         frame3f{{0, -1, 0}, {0, 0, 1}, {-1, 0, 0}, {-1, 0, 0}}};
    vector<vec3f> quad_pos, quad_norm;
    vector<vec2f> quad_texcoord;
    vector<vec4i> quad_quads;
    tie(quad_quads, quad_pos, quad_norm, quad_texcoord) =
        make_uvquad(usteps, vsteps);
    vector<vec3f> pos, norm;
    vector<vec2f> texcoord;
    vector<vec4i> quads;
    for (auto i = 0; i < 6; i++) {
      pos.insert(pos.end(), quad_pos.begin(), quad_pos.end());
      norm.insert(norm.end(), quad_norm.begin(), quad_norm.end());
      texcoord.insert(
          texcoord.end(), quad_texcoord.begin(), quad_texcoord.end());
      quads.insert(quads.end(), quad_quads.begin(), quad_quads.end());
    }
    auto quad_verts = quad_pos.size();
    for (auto i = 0; i < 6; i++) {
      for (auto j = quad_verts * i; j < quad_verts * (i + 1); j++)
        pos[j] = transform_point(frames[i], pos[j]);
      for (auto j = quad_verts * i; j < quad_verts * (i + 1); j++)
        norm[j] = transform_direction(frames[i], norm[j]);
    }
    auto quad_faces = quad_quads.size();
    for (auto i = 0; i < 6; i++) {
      for (auto j = quad_faces * i; j < quad_faces * (i + 1); j++) {
        quads[j].x += quad_verts * i;
        quads[j].y += quad_verts * i;
        quads[j].z += quad_verts * i;
        quads[j].w += quad_verts * i;
      }
    }
    return {quads, pos, norm, texcoord};
  }