tuple<vector<vec4i>, vector<vec3f>, vector<vec3f>, vector<vec2f>>
  make_uvflipcapsphere(int usteps, int vsteps, float radius) {
    vector<vec3f> pos, norm;
    vector<vec2f> texcoord;
    vector<vec4i> quads;
    tie(quads, pos, norm, texcoord) = make_uvsphere(usteps, vsteps);
    for (auto i = 0; i < pos.size(); i++) {
      if (pos[i].z > radius) {
        pos[i].z = 2 * radius - pos[i].z;
        norm[i].x = -norm[i].x;
        norm[i].y = -norm[i].y;
      } else if (pos[i].z < -radius) {
        pos[i].z = -2 * radius - pos[i].z;
        norm[i].x = -norm[i].x;
        norm[i].y = -norm[i].y;
      }
    }
    return {quads, pos, norm, texcoord};
  }