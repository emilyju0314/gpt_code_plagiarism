inline void dump(const glTFNode* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFChildOfRootProperty*)val, js, err);
      if (val->camera.is_valid()) dump_attr(val->camera, "camera", js, err);
      if (!val->children.empty()) dump_attr(val->children, "children", js, err);
      if (val->skin.is_valid()) dump_attr(val->skin, "skin", js, err);
      if (val->matrix !=
          mat4f{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}})
        dump_attr(val->matrix, "matrix", js, err);
      if (val->mesh.is_valid()) dump_attr(val->mesh, "mesh", js, err);
      if (val->rotation != quat4f{0, 0, 0, 1})
        dump_attr(val->rotation, "rotation", js, err);
      if (val->scale != vec3f{1, 1, 1}) dump_attr(val->scale, "scale", js, err);
      if (val->translation != vec3f{0, 0, 0})
        dump_attr(val->translation, "translation", js, err);
      if (!val->weights.empty()) dump_attr(val->weights, "weights", js, err);
    }