inline tuple<vector<vec4i>, vector<vec3f>, vector<vec3f>, vector<vec2f>>
  make_uvhollowcutsphere1(int usteps, int vsteps, float radius) {
    auto quads = vector<vec4i>();
    auto pos = vector<vec3f>();
    auto norm = vector<vec3f>();
    auto texcoord = vector<vec2f>();

    vector<vec3f> mpos, mnorm;
    vector<vec2f> mtexcoord;
    vector<vec4i> mquads;
    vector<vec2i> _aux1;
    vector<vec3i> _aux2;

    tie(mquads, mpos, mnorm, mtexcoord) =
        make_uvcutsphere(usteps, vsteps, radius);
    for (auto& uv : mtexcoord) uv.y *= radius;
    for (auto i = (usteps + 1) * vsteps; i < mnorm.size(); i++)
      mnorm[i] = normalize(mnorm[i] + vec3f{0, 0, 1});
    tie(_aux1, _aux2, quads) =
        merge_elems((int)pos.size(), {}, {}, quads, {}, {}, mquads);
    pos += mpos;
    norm += mnorm;
    texcoord += mtexcoord;

    tie(mquads, mpos, mnorm, mtexcoord) =
        make_uvflippedcutsphere(usteps, vsteps, radius * 1.05f);
    for (auto& p : mpos) p *= 0.8f;
    tie(_aux1, _aux2, quads) =
        merge_elems((int)pos.size(), {}, {}, quads, {}, {}, mquads);
    pos += mpos;
    norm += mnorm;
    texcoord += mtexcoord;

    tie(mquads, mtexcoord) = make_uvquads(usteps, vsteps / 4);
    mpos.resize(mtexcoord.size());
    mnorm.resize(mtexcoord.size());
    for (auto i = 0; i < mtexcoord.size(); i++) {
      auto uv = mtexcoord[i];
      auto p = 1 - acos(radius) / pif;
      auto v = p + uv[1] * (1 - p);
      auto a = vec2f{2 * pif * uv[0], pif * (1 - v)};
      mpos[i] = {cos(a[0]) * sin(a[1]), sin(a[0]) * sin(a[1]),
                 (2 * radius - cos(a[1]))};
      mnorm[i] = {-cos(a[0]) * sin(a[1]), -sin(a[0]) * sin(a[1]), cos(a[1])};
      mtexcoord[i] = {uv[0], radius + (1 - radius) * uv[1]};
    }
    for (auto i = 0; i < (usteps + 1); i++)
      mnorm[i] = normalize(mnorm[i] + vec3f{0, 0, 1});
    tie(_aux1, _aux2, quads) =
        merge_elems((int)pos.size(), {}, {}, quads, {}, {}, mquads);
    pos += mpos;
    norm += mnorm;
    texcoord += mtexcoord;
    return {quads, pos, norm, texcoord};
  }