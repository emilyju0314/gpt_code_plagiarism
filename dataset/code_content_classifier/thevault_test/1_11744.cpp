inline void load_textures(
        obj_scene* asset, const string& dirname, bool skip_missing) {
      for (auto txt : asset->textures) {
        auto filename = dirname + txt->path;
        for (auto& c : filename)
          if (c == '\\') c = '/';
#if YGL_IMAGEIO
        if (is_hdr_filename(filename)) {
          txt->dataf =
              load_imagef(filename, txt->width, txt->height, txt->ncomp);
        } else {
          txt->datab =
              load_image(filename, txt->width, txt->height, txt->ncomp);
        }
#endif
        if (txt->datab.empty() && txt->dataf.empty()) {
          if (skip_missing) continue;
          throw runtime_error("cannot laod image " + filename);
        }
      }
    }