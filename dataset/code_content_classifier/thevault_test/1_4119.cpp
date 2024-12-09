bool rendermodel_manager::poll() {
    // if (known_ready) return true; // short circuit
    //log("rendermodel")->info("polling for render models");

    bool result = true;

    // precache everything?
    /*
    for (int i = 0, n = model_count();i < n; ++i) {
      string name = model_name(i);
      result = poll_model(name) && result;
    }
    */

    // scan only active models
    for (auto i = vr::k_unTrackedDeviceIndex_Hmd + 1;i < vr::k_unMaxTrackedDeviceCount;++i) {
      if (!tracker.valid_device(i)) continue;
      string name = tracker.device_string(i, vr::Prop_RenderModelName_String);
      if (name == "") continue;
      result = poll_model(name, &tracked_rendermodels[i]) && result;
    }

    // for each model
    for (auto & p : models) {
      // check for textures
      if (!p.second->diffuse)
        result = poll_texture(p.first, p.second->vr_texture_id, &p.second->diffuse) && result;
      
      // are we missing parts?
      if (p.second->missing_components) {
        bool components_found = true;
        int N = component_count(p.first);
        for (int j = 0;j < N;++j) {
          // check for the component as already added to this model first.
          auto & parts = p.second->components;
          string cname = component_name(p.first, j);
          if (cname == "") continue;
          string cmodel = component_model(p.first, cname);
          if (cmodel == "") continue;
          auto iter(parts.lower_bound(cmodel));
          if (iter != parts.end() && cmodel >= iter->first) continue; // already in there
          shared_ptr<rendermodel> part;
          bool part_found = poll_model(cmodel, &part, true);
          components_found = components_found && part_found && part && part->diffuse;
          if (part_found && part != nullptr)
            parts.insert(iter, make_pair(cname, part));
        }
        p.second->missing_components = !components_found;
        result = components_found && result;
      }
    }
    known_ready = result;
    return result;
  }