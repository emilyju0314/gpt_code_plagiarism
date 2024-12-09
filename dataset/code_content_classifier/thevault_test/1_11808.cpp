inline tuple<vector<vec4i>, vector<vec3f>, vector<vec3f>, vector<vec2f>>
  make_uvhollowcutsphere(int usteps, int vsteps, float radius) {
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
    tie(_aux1, _aux2, quads) =
        merge_elems((int)pos.size(), {}, {}, quads, {}, {}, mquads);
    pos += mpos;
    norm += mnorm;
    texcoord += mtexcoord;

    tie(mquads, mpos, mnorm, mtexcoord) =
        make_uvflippedcutsphere(usteps, vsteps, radius);
    for (auto& p : mpos) p *= radius;
    tie(_aux1, _aux2, quads) =
        merge_elems((int)pos.size(), {}, {}, quads, {}, {}, mquads);
    pos += mpos;
    norm += mnorm;
    texcoord += mtexcoord;

    // dpdu = [- s r s0 s1, s r c0 s1, 0] === [- s0, c0, 0]
    // dpdv = [s c0 s1, s s0 s1, s c1] === [c0 s1, s0 s1, c1]
    // n = [c0 c1, - s0 c1, s1]
    tie(mquads, mtexcoord) = make_uvquads(usteps, vsteps);
    mpos.resize(mtexcoord.size());
    mnorm.resize(mtexcoord.size());
    for (auto i = 0; i < mtexcoord.size(); i++) {
      auto uv = mtexcoord[i];
      auto a = vec2f{2 * pif * uv[0], pif * (1 - radius)};
      auto r = (1 - uv[1]) + uv[1] * radius;
      mpos[i] = {r * cos(a[0]) * sin(a[1]), r * sin(a[0]) * sin(a[1]),
                 r * cos(a[1])};
      mnorm[i] = {-cos(a[0]) * cos(a[1]), -sin(a[0]) * cos(a[1]), sin(a[1])};
      mtexcoord[i] = {uv[0], radius + (1 - radius) * uv[1]};
    }
    tie(_aux1, _aux2, quads) =
        merge_elems((int)pos.size(), {}, {}, quads, {}, {}, mquads);
    pos += mpos;
    norm += mnorm;
    texcoord += mtexcoord;
    return {quads, pos, norm, texcoord};
  }