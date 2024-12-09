inline ray3f offset_ray(
        const point& pt, const vec3f& w, const trace_params& params) {
      if (dot(w, pt.frame.z) > 0) {
        return ray3f(
            pt.frame.o + pt.frame.z * params.ray_eps, w, params.ray_eps);
      } else {
        return ray3f(
            pt.frame.o - pt.frame.z * params.ray_eps, w, params.ray_eps);
      }
    }