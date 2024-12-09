tuple<vector<vec4i>, vector<vec3f>, vector<vec3f>, vector<vec2f>>
  make_uvspherecube(int usteps, int vsteps) {
    vector<vec3f> pos, norm;
    vector<vec2f> texcoord;
    vector<vec4i> quads;
    tie(quads, pos, norm, texcoord) = make_uvcube(usteps, vsteps);
    for (auto i = 0; i < pos.size(); i++) {
      pos[i] = normalize(pos[i]);
      norm[i] = normalize(pos[i]);
    }
    return {quads, pos, norm, texcoord};
  }