void StarFieldGUI::sl_make_tetrahedron() {
    cout << "tetra" << '\n';
    c_stars.clear();
    auto c = xRange * defaultStarArrangementFactor;

    c_stars.push_back(Star{defaultStarMass, {-c, -c, -c}});
    c_stars.push_back(Star{defaultStarMass, {c, -c, c}});
    c_stars.push_back(Star{defaultStarMass, {-c, c, c}});
    c_stars.push_back(Star{defaultStarMass, {c, c, -c}});

    sig_set_number_of_stars(c_stars.size());
    updateFieldState();
  }