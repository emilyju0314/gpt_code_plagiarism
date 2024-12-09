inline vec3f eval_brdfcos_disney(
        const point& pt, const vec3f& wi, const trace_params& params, bool delta = false) {
      // grab variables

      auto& fr = pt.fr;
      auto& wn = pt.frame.z;
      auto& wo = pt.wo;

      // exit if not needed
      if (!fr) return zero3f;

      // accumulate brdfcos for each lobe
      auto brdfcos = zero3f;
      switch (fr.type) {
        // reflection terms
        case brdf_type::microfacet: {
          // compute wh
          auto wh = normalize(wo + wi);

          // compute dot products
          auto ndo = dot(wn, wo), ndi = dot(wn, wi),
              ndh = clamp(dot(wh, wn), (float)-1, (float)1);

          // diffuse term
          if (fr.kd != zero3f && ndi > 0 && ndo > 0) {
            auto odh = clamp(dot(wo, wh), 0.0f, 1.0f);
            brdfcos += eval_diffuse_disney(fr.kd * ndi, odh, fr.rs);;
          }

          // specular term (GGX)
          if (fr.ks != zero3f && ndi > 0 && ndo > 0 && ndh > 0 && fr.rs) {
            // microfacet term
            auto dg = eval_ggx(fr.rs, ndh, ndi, ndo, true, params);

            // handle fresnel
            auto odh = clamp(dot(wo, wh), 0.0f, 1.0f);
            auto ks = eval_fresnel_schlick(fr.ks, odh, fr.rs);
            // sum up
            brdfcos += ks * ndi * dg / (4 * ndi * ndo);
          }

          // specular term (mirror)
          if (fr.ks != zero3f && ndi > 0 && ndo > 0 && !fr.rs && delta) {
            // handle fresnel
            //auto ks = eval_fresnel_schlick(fr.ks, ndo, fr.rs, true, params);
            auto ks = eval_fresnel_schlick(fr.ks, ndo, fr.rs);

            // sum up
            brdfcos += ks;
          }

          // transmission hack
          if (fr.kt != zero3f && wo == -wi) brdfcos += fr.kt;
        }
        break;
          // hair (Kajiya-Kay)
        case brdf_type::kajiya_kay: {
          // compute wh
          auto wh = normalize(wo + wi);

          // compute dot products
          auto ndo = dot(wn, wo), ndi = dot(wn, wi),
              ndh = clamp(dot(wh, wn), (float)0, (float)1);

          // take sines
          auto so = sqrt(clamp(1 - ndo * ndo, (float)0, (float)1)),
              si = sqrt(clamp(1 - ndi * ndi, (float)0, (float)1)),
              sh = sqrt(clamp(1 - ndh * ndh, (float)0, (float)1));

          // diffuse term (Kajiya-Kay)
          if (fr.kd != zero3f && si > 0 && so > 0) {
            brdfcos += fr.kd * si / pif;
          }

          // specular term (Kajiya-Kay)
          if (fr.ks != zero3f && si > 0 && so > 0 && sh > 0) {
            auto ns = 2 / (fr.rs * fr.rs) - 2;
            auto d = (ns + 2) * pow(sh, ns) / (2 + pif);
            brdfcos += fr.ks * si * d / (4.0f * si * so);
          }

          // transmission hack
          if (fr.kt != zero3f && wo == -wi) brdfcos += fr.kt;
        } break;
          // points
        case brdf_type::point: {
          // diffuse term
          auto ido = dot(wo, wi);
          brdfcos += fr.kd * (2 * ido + 1) / (2 * pif);

          // transmission hack
          if (fr.kt != zero3f && wo == -wi) brdfcos += fr.kt;
        }
        break;
        default: assert(false); break;
      }

      // check
      assert(isfinite(brdfcos.x) && isfinite(brdfcos.y) && isfinite(brdfcos.z));

      // done
      return brdfcos;
    }