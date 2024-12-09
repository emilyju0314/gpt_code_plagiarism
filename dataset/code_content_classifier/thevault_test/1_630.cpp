Real Mesh::calculateConvexVolume() {
  Real totalVolume = 0.0;

  // Calculate center point of Mesh
  Vector3 mean = Vector3::Zero();
  for (int i = 0; i < vertices_.size(); i++) {
    mean += vertices_[i].position_;
  }
  mean /= vertices_.size();

  // For each facet determine the tetrahedron with the center point and
  // calculate its volume
  // and add it to the total volume
  for (int i = 0; i < triangles_.size(); i++) {
    Eigen::Matrix<Real, 4, 4> mat;
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        mat(j, k) = vertices_[triangles_[i].vertices_[j]].position_[k];
      }
    }
    for (int j = 0; j < 3; j++) {
      mat(3, j) = mean[j];
    }
    for (int j = 0; j < 4; j++) {
      mat(j, 3) = 1;
    }
    totalVolume += mat.determinant() / 6.0;
  }

  return totalVolume;
}