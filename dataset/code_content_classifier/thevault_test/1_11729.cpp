inline float weight_brdfcos(
        const point& pt, const vec3f& wi, bool delta = false) {
      // grab variables
      auto& fr = pt.fr;
      auto& wn = pt.frame.z;
      auto& wo = pt.wo;

      // skip if no component
      if (!fr) return 0;

      // probability of each lobe
      auto kdw = max_element(fr.kd).second, ksw = max_element(fr.ks).second,
          ktw = max_element(fr.kt).second;
      auto kaw = kdw + ksw + ktw;
      kdw /= kaw;
      ksw /= kaw;
      ktw /= kaw;

      // accumulate the probability over all lobes
      auto pdf = 0.0f;
      // sample the lobe
      switch (fr.type) {
        // reflection term
        case brdf_type::microfacet: {
          // compute wh
          auto wh = normalize(wi + wo);

          // compute dot products
          auto ndo = dot(wn, wo), ndi = dot(wn, wi), ndh = dot(wn, wh);

          // diffuse term (hemipherical cosine probability)
          if (kdw && ndo > 0 && ndi > 0) { pdf += kdw * ndi / pif; }

          // specular term (GGX)
          if (ksw && ndo > 0 && ndi > 0 && ndh > 0 && fr.rs) {
            // probability proportional to d adjusted by wh projection
            auto d = pdf_ggx(fr.rs, ndh);
            auto hdo = dot(wo, wh);
            pdf += ksw * d / (4 * hdo);
          }

          // specular term (mirror)
          if (ksw && ndo > 0 && ndi > 0 && !fr.rs && delta) {
            // probability proportional to d adjusted by wh projection
            pdf += ksw;
          }

          // transmission hack
          if (ktw && wi == -wo) pdf += ktw;

          // check
          assert(isfinite(pdf));
        } break;
          // hair (Kajiya-Kay)
        case brdf_type::kajiya_kay: {
          // diffuse and specular
          pdf += (kdw + ksw) * 4 * pif;
          // transmission hack
          if (wi == -wo) pdf += ktw;
        } break;
          // point
        case brdf_type::point: {
          // diffuse and specular
          pdf += (kdw + ksw) * 4 * pif;
          // transmission hack
          if (wi == -wo) pdf += ktw;
        } break;
        default: assert(false); break;
      }

      // check for missed pdf
      if (!pdf) return 0;

      // check
      assert(isfinite(pdf));

      // done
      return 1 / pdf;
    }