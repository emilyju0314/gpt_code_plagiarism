inline ray3f eval_camera(const camera* cam, const vec2f& uv, const vec2f& luv) {
      auto h = 2 * tan(cam->yfov / 2);
      auto w = h * cam->aspect;
      auto o = vec3f{luv.x * cam->aperture, luv.y * cam->aperture, 0};
      auto q = vec3f{w * cam->focus * (uv.x - 0.5f),
                     h * cam->focus * (uv.y - 0.5f), -cam->focus};
      return ray3f(transform_point(cam->frame, o),
                   transform_direction(cam->frame, normalize(q - o)));
    }