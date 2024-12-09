inline auto boundary(BoundaryType nr, Mesh* mesh = NULL)
    -> BoundaryWrapper
  {
    return {nr, mesh};
  }