tuple<vector<vec4i>, vector<vec3f>, vector<vec3f>, vector<vec2f>>
  make_uvhemisphere(int usteps, int vsteps) {
    auto quads = vector<vec4i>();
    auto texcoord = vector<vec2f>();
    tie(quads, texcoord) = make_uvquads(usteps, vsteps);
    auto pos = vector<vec3f>(texcoord.size());
    auto norm = vector<vec3f>(texcoord.size());
    for (auto i = 0; i < texcoord.size(); i++) {
      auto uv = texcoord[i];
      auto a = vec2f{2 * pif * uv.x, pif * 0.5f * (1 - uv.y)};
      pos[i] = {cos(a.x) * sin(a.y), sin(a.x) * sin(a.y), cos(a.y)};
      norm[i] = {cos(a.x) * sin(a.y), sin(a.x) * sin(a.y), cos(a.y)};
    }
    return {quads, pos, norm, texcoord};
  }