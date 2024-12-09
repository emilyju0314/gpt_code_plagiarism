inline tuple<vec3f, bool> sample_brdfcos(
        const point& pt, float rnl, const vec2f& rn) {
      // grab variables
      auto& fr = pt.fr;
      auto& wn = pt.frame.z;
      auto& fp = pt.frame;
      auto& wo = pt.wo;

      // skip if no component
      if (!fr) return {zero3f, false};

      // probability of each lobe
      auto kdw = max_element(fr.kd).second, ksw = max_element(fr.ks).second,
          ktw = max_element(fr.kt).second;
      auto kaw = kdw + ksw + ktw;
      kdw /= kaw;
      ksw /= kaw;
      ktw /= kaw;

      // sample selected lobe
      switch (fr.type) {
        // reflection term
        case brdf_type::microfacet: {
          // compute cosine
          auto ndo = dot(wn, wo);

          // check to make sure we are above the surface
          if (ndo <= 0) return {zero3f, false};

          // sample according to diffuse
          if (rnl < kdw) {
            // sample wi with hemispherical cosine distribution
            auto rz = sqrtf(rn.y), rr = sqrtf(1 - rz * rz),
                rphi = 2 * pif * rn.x;
            // set to wi
            auto wi_local = vec3f{rr * cosf(rphi), rr * sinf(rphi), rz};
            return {transform_direction(fp, wi_local), false};
          }
            // sample according to specular GGX
          else if (rnl < kdw + ksw && fr.rs) {
            // sample wh with ggx distribution
            auto wh_local = sample_ggx(fr.rs, rn);
            auto wh = transform_direction(fp, wh_local);
            // compute wi
            return {normalize(wh * 2.0f * dot(wo, wh) - wo), false};
          }
            // sample according to specular mirror
          else if (rnl < kdw + ksw && !fr.rs) {
            // compute wi
            return {normalize(wn * 2.0f * dot(wo, wn) - wo), true};
          }
            // transmission hack
          else if (rnl < kdw + ksw + ktw) {
            // continue ray direction
            return {-wo, true};
          } else
            assert(false);
        } break;
          // hair (Kajiya-Kay)
        case brdf_type::kajiya_kay: {
          // diffuse and specular
          if (rnl < kdw + ksw) {
            // sample wi with uniform spherical distribution
            auto rz = 2 * rn.y - 1, rr = sqrtf(1 - rz * rz),
                rphi = 2 * pif * rn.x;
            auto wi_local = vec3f{rr * cosf(rphi), rr * sinf(rphi), rz};
            return {transform_direction(fp, wi_local), false};
          }
            // transmission hack
          else if (rnl < kdw + ksw + ktw) {
            // continue ray direction
            return {-wo, true};
          } else
            assert(false);
        } break;
          // diffuse term point
        case brdf_type::point: {
          // diffuse and specular
          if (rnl < kdw + ksw) {
            // sample wi with uniform spherical distribution
            auto rz = 2 * rn.y - 1, rr = sqrtf(1 - rz * rz),
                rphi = 2 * pif * rn.x;
            auto wi_local = vec3f{rr * cosf(rphi), rr * sinf(rphi), rz};
            return {transform_direction(fp, wi_local), false};
          }
            // transmission hack
          else if (rnl < kdw + ksw + ktw) {
            // continue ray direction
            return {-wo, true};
          } else
            assert(false);
        } break;
        default: assert(false); break;
      }

      // done
      return {zero3f, false};
    }