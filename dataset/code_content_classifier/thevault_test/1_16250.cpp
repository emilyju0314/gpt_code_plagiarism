const WorldVector<double>
  * Quadrature::grdFAtQp(const std::function<WorldVector<double>(DimVec<double>)>& f,
                         WorldVector<double>* vec) const
  {
    static WorldVector<double>* quad_vec_d = NULL;
    static int size = 0;
    WorldVector<double>* val;
    WorldVector<double> grd;

    if (vec)
    {
      val = vec;
    }
    else
    {
      if (size < n_points)
      {
        int new_size = std::max(maxNQuadPoints[dim], n_points);
        if (quad_vec_d)
          delete [] quad_vec_d;
        quad_vec_d = new WorldVector<double>[new_size];
        size = new_size;
      }
      val = quad_vec_d;
    }

    int dow = Global::getGeo(WORLD);

    for (int i = 0; i < n_points; i++)
    {
      grd = f((*lambda)[i]);
      for (int j = 0; j < dow; j++)
        val[i][j] = grd[j];
    }

    return val;
  }