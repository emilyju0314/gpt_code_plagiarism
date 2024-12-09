inline void dump(const glTF* val, json& js, parse_stack& err) {
      if (!js.is_object()) js = json::object();
      dump((const glTFProperty*)val, js, err);
      if (!val->extensionsUsed.empty())
        dump_attr(val->extensionsUsed, "extensionsUsed", js, err);
      if (!val->extensionsRequired.empty())
        dump_attr(val->extensionsRequired, "extensionsRequired", js, err);
      if (!val->accessors.empty())
        dump_attr(val->accessors, "accessors", js, err);
      if (!val->animations.empty())
        dump_attr(val->animations, "animations", js, err);
      dump_attr(val->asset, "asset", js, err);
      if (!val->buffers.empty()) dump_attr(val->buffers, "buffers", js, err);
      if (!val->bufferViews.empty())
        dump_attr(val->bufferViews, "bufferViews", js, err);
      if (!val->cameras.empty()) dump_attr(val->cameras, "cameras", js, err);
      if (!val->images.empty()) dump_attr(val->images, "images", js, err);
      if (!val->materials.empty())
        dump_attr(val->materials, "materials", js, err);
      if (!val->meshes.empty()) dump_attr(val->meshes, "meshes", js, err);
      if (!val->nodes.empty()) dump_attr(val->nodes, "nodes", js, err);
      if (!val->samplers.empty()) dump_attr(val->samplers, "samplers", js, err);
      if (val->scene.is_valid()) dump_attr(val->scene, "scene", js, err);
      if (!val->scenes.empty()) dump_attr(val->scenes, "scenes", js, err);
      if (!val->skins.empty()) dump_attr(val->skins, "skins", js, err);
      if (!val->textures.empty()) dump_attr(val->textures, "textures", js, err);
    }