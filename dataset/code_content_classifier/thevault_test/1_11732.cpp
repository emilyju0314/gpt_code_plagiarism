inline float weight_light(const point& lpt, const point& pt) {
      if (!lpt.em) return 0;
      // support only one lobe for now
      switch (lpt.em.type) {
        case emission_type::env: {
          return 4 * pif;
        } break;
        case emission_type::point: {
          auto d = length(lpt.frame.o - pt.frame.o);
          return lpt.ist->shp->elem_cdf.back() / (d * d);
        } break;
        case emission_type::line: {
          assert(false);
          return 0;
        } break;
        case emission_type::diffuse: {
          auto d = length(lpt.frame.o - pt.frame.o);
          return lpt.ist->shp->elem_cdf.back() *
                 abs(dot(lpt.frame.z, lpt.wo)) / (d * d);
        } break;
        default: {
          assert(false);
          return 0;
        } break;
      }
    }