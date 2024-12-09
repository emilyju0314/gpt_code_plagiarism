inline ScenePoint(const Vec3& X, uint32_t f_id)
      : _X(X), _X_original(X)
  {
    _f.reserve(8);
    _f.push_back(f_id);
  }