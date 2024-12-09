inline float eval_ggx(float rs, float ndh, float ndi, float ndo, bool disney = false, const trace_params& params = trace_params()) {
      // evaluate GGX
      float d;
      double alpha2 = rs * rs;
      if(disney){
        d = static_cast<float>(params.d_constant / pow(((alpha2 * (ndh * ndh)) + (1 - (ndh * ndh))), params.d_gamma));
        alpha2 = pow((0.5f + rs/2),2); //specular G
      }
      else{
        auto di = (ndh * ndh) * (alpha2 - 1) + 1;
        d = static_cast<float>(alpha2 / (pif * di * di));
      }

      #ifndef YGL_GGX_SMITH
        auto lambda_o = (-1 + sqrt(1 + alpha2 * (1 - ndo * ndo) / (ndo * ndo))) / 2;
        auto lambda_i = (-1 + sqrt(1 + alpha2 * (1 - ndi * ndi) / (ndi * ndi))) / 2;
        auto g = 1 / (1 + lambda_o + lambda_i);
      #else
        auto go = (2 * ndo) / (ndo + sqrt(alpha2 + (1 - alpha2) * ndo * ndo));
        auto gi = (2 * ndi) / (ndi + sqrt(alpha2 + (1 - alpha2) * ndi * ndi));
        auto g = go * gi;
      #endif
      
      return static_cast<float>(d * g);
    
    }