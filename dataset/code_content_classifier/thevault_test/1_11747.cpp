inline void save_textures(
        const obj_scene* asset, const string& dirname, bool skip_missing) {
      for (auto txt : asset->textures) {
        if (txt->datab.empty() && txt->dataf.empty()) continue;
        auto filename = dirname + txt->path;
        for (auto& c : filename)
          if (c == '\\') c = '/';
        auto ok = false;
#if YGL_IMAGEIO
        if (!txt->datab.empty()) {
          ok = save_image(filename, txt->width, txt->height, txt->ncomp,
                          txt->datab.data());
        }
        if (!txt->dataf.empty()) {
          ok = save_imagef(filename, txt->width, txt->height, txt->ncomp,
                           txt->dataf.data());
        }
#endif
        if (!ok) {
          if (skip_missing) continue;
          throw runtime_error("cannot save image " + filename);
        }
      }
    }