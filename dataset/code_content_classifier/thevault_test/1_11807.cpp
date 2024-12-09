tuple<vector<vec2i>, vector<vec3f>, vector<vec3f>, vector<vec2f>, vector<float>>
  make_hair(int num, int usteps, const vec2f& len, const vec2f& rad,
            const vector<vec3i>& striangles, const vector<vec4i>& squads,
            const vector<vec3f>& spos, const vector<vec3f>& snorm,
            const vector<vec2f>& stexcoord, const vec2f& noise, const vec2f& clump,
            const vec2f& rotation, uint32_t seed) {
    vector<vec3f> bpos;
    vector<vec3f> bnorm;
    vector<vec2f> btexcoord;
    tie(bpos, bnorm, btexcoord) =
        sample_triangles_points(striangles + convert_quads_to_triangles(squads),
                                spos, snorm, stexcoord, num, seed);

    auto rng = init_rng(seed, 3);
    auto blen = vector<float>(bpos.size());
    for (auto& l : blen) l = lerp(len.x, len.y, next_rand1f(rng));

    auto cidx = vector<int>();
    if (clump.x > 0) {
      for (auto bidx : range(bpos.size())) {
        cidx += 0;
        auto cdist = flt_max;
        for (auto c = 0; c < clump.y; c++) {
          auto d = length(bpos[bidx] - bpos[c]);
          if (d < cdist) {
            cdist = d;
            cidx.back() = c;
          }
        }
      }
    }

    auto lines = vector<vec2i>();
    auto texcoord = vector<vec2f>();
    tie(lines, texcoord) = make_lines(num, usteps);
    auto pos = vector<vec3f>(texcoord.size());
    auto norm = vector<vec3f>(texcoord.size());
    auto radius = vector<float>(texcoord.size());
    for (auto i : range(texcoord.size())) {
      auto u = texcoord[i].x;
      auto bidx = i / (usteps + 1);
      pos[i] = bpos[bidx] + bnorm[bidx] * u * blen[bidx];
      norm[i] = bnorm[bidx];
      radius[i] = lerp(rad.x, rad.y, u);
      if (clump.x > 0) {
        pos[i] = lerp(pos[i], pos[i + (cidx[bidx] - bidx) * (usteps + 1)],
                      u * clump.x);
      }
      if (noise.x > 0) {
        auto nx = perlin_noise(pos[i] * noise.y + vec3f{0, 0, 0}) * noise.x;
        auto ny =
            perlin_noise(pos[i] * noise.y + vec3f{3, 7, 11}) * noise.x;
        auto nz =
            perlin_noise(pos[i] * noise.y + vec3f{13, 17, 19}) * noise.x;
        pos[i] += {nx, ny, nz};
      }
    }

    if (clump.x > 0 || noise.x > 0 || rotation.x > 0)
      norm = compute_normals(lines, {}, {}, pos);

    return {lines, pos, norm, texcoord, radius};
  }