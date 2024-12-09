inline vec3f eval_fresnel_metal(
        float cosw, const vec3f& eta, const vec3f& etak) {
      if (etak == zero3f) return eval_fresnel_dielectric(cosw, eta);

      cosw = clamp(cosw, (float)-1, (float)1);
      auto cos2 = cosw * cosw;
      auto sin2 = clamp(1 - cos2, (float)0, (float)1);
      auto eta2 = eta * eta;
      auto etak2 = etak * etak;

      auto t0 = eta2 - etak2 - vec3f{sin2, sin2, sin2};
      auto a2plusb2_2 = t0 * t0 + 4.0f * eta2 * etak2;
      auto a2plusb2 =
          vec3f{sqrt(a2plusb2_2.x), sqrt(a2plusb2_2.y), sqrt(a2plusb2_2.z)};
      auto t1 = a2plusb2 + vec3f{cos2, cos2, cos2};
      auto a_2 = (a2plusb2 + t0) / 2.0f;
      auto a = vec3f{sqrt(a_2.x), sqrt(a_2.y), sqrt(a_2.z)};
      auto t2 = 2.0f * a * cosw;
      auto rs = (t1 - t2) / (t1 + t2);

      auto t3 = vec3f{cos2, cos2, cos2} * a2plusb2 +
                vec3f{sin2, sin2, sin2} * vec3f{sin2, sin2, sin2};
      auto t4 = t2 * sin2;
      auto rp = rs * (t3 - t4) / (t3 + t4);

      return (rp + rs) / 2.0f;
    }