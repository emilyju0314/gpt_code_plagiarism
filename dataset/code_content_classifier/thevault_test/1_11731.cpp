inline point eval_envpoint(const environment* env, const vec3f& wo) {
      // set shape data
      auto pt = point();

      // env
      pt.env = env;

      // direction
      pt.wo = wo;

      // maerial
      auto ke = env->ke;
      if (env->ke_txt) {
        auto w = transform_direction_inverse(env->frame, -wo);
        auto theta = acos(clamp(w.y, (float)-1, (float)1));
        auto phi = atan2(w.z, w.x);
        auto texcoord = vec2f{0.5f + phi / (2 * pif), theta / pif};
        ke *= eval_texture(env->ke_txt, texcoord).xyz();
      }

      // create emission lobe
      if (ke != zero3f) { pt.em = {emission_type::env, ke}; }

      // done
      return pt;
    }