inline point intersect_scene(const scene* scn, const ray3f& ray) {
      auto iid = 0, eid = 0;
      auto euv = zero4f;
      auto ray_t = 0.0f;
      if (intersect_ray(scn, ray, false, ray_t, iid, eid, euv)) {
        return eval_shapepoint(scn->instances[iid], eid, euv, -ray.d);
      } else if (!scn->environments.empty()) {
        return eval_envpoint(scn->environments[0], -ray.d);
      } else {
        return {};
      }
    }