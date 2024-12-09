inline ray3f offset_ray(
        const point& pt, const point& pt2, const trace_params& params) {
      auto ray_dist = (!pt2.env) ? length(pt.frame.o - pt2.frame.o) : flt_max;
      if (dot(-pt2.wo, pt.frame.z) > 0) {
        return ray3f(pt.frame.o + pt.frame.z * params.ray_eps, -pt2.wo,
                     params.ray_eps, ray_dist - 2 * params.ray_eps);
      } else {
        return ray3f(pt.frame.o - pt.frame.z * params.ray_eps, -pt2.wo,
                     params.ray_eps, ray_dist - 2 * params.ray_eps);
      }
    }