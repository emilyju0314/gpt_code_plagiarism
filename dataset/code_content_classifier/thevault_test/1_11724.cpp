inline vec3f eval_fresnel_dielectric(float cosw, const vec3f& eta_) {
      auto eta = eta_;
      if (cosw < 0) {
        eta = 1.0f / eta;
        cosw = -cosw;
      }

      auto sin2 = 1 - cosw * cosw;
      auto eta2 = eta * eta;

      auto cos2t = vec3f{1, 1, 1} - sin2 / eta2;
      if (cos2t.x < 0 || cos2t.y < 0 || cos2t.z < 0)
        return vec3f{1, 1, 1};  // tir

      auto t0 = vec3f{sqrt(cos2t.x), sqrt(cos2t.y), sqrt(cos2t.z)};
      auto t1 = eta * t0;
      auto t2 = eta * cosw;

      auto rs = (vec3f{cosw, cosw, cosw} - t1) / (vec3f{cosw, cosw, cosw} + t1);
      auto rp = (t0 - t2) / (t0 + t2);

      return (rs * rs + rp * rp) / 2.0f;
    }