void StarFieldGUI::sl_make_octahedron() {
    cout << "octa" << '\n';
    c_stars.clear();
    auto c = xRange * defaultStarArrangementFactor;

    c_stars.push_back(Star{defaultStarMass, {0, -c, 0}});
    c_stars.push_back(Star{defaultStarMass, {0, c, 0}});

    c_stars.push_back(Star{defaultStarMass, {-c, 0, 0}});
    c_stars.push_back(Star{defaultStarMass, {c, 0, 0}});

    c_stars.push_back(Star{defaultStarMass, {0, 0, -c}});
    c_stars.push_back(Star{defaultStarMass, {0, 0, c}});

    sig_set_number_of_stars(c_stars.size());
    updateFieldState();
  }