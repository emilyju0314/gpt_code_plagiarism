tuple<vector<vec4i>, vector<vec3f>, vector<vec3f>, vector<vec2f>>
  make_uvspherizedcube(int usteps, int vsteps, float radius) {
    vector<vec3f> pos, norm;
    vector<vec2f> texcoord;
    vector<vec4i> quads;
    tie(quads, pos, norm, texcoord) = make_uvcube(usteps, vsteps);
    for (auto i = 0; i < pos.size(); i++) {
      norm[i] = normalize(pos[i]);
      pos[i] *= 1 - radius;
      pos[i] += norm[i] * radius;
    }
    norm = compute_normals({}, {}, quads, pos, true);
    return {quads, pos, norm, texcoord};
  }