glTF* load_binary_gltf(
      const string& filename, bool load_bin, bool load_img, bool skip_missing) {
    return _impl_gltf::load_binary_gltf(
        filename, load_bin, load_img, skip_missing);
  }