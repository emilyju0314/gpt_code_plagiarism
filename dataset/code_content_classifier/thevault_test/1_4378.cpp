apf::Field* eval_cauchy(RCP<State> state, int step) {

  // an assumption about the pressure index
  int const pressure_idx = 1;

  // gather discretization information
  RCP<Disc> disc = state->disc;
  apf::Mesh* mesh = disc->apf_mesh();
  int const ndims = mesh->getDimension();
  int const q_order = disc->lv_shape()->getOrder();

  // gather information from the state object
  RCP<LocalResidual<double>> local = state->residuals->local;
  RCP<GlobalResidual<double>> global = state->residuals->global;
  Array1D<apf::Field*> x = disc->primal(step).global;
  Array1D<apf::Field*> xi = disc->primal(step).local;
  Array1D<apf::Field*> x_prev = disc->primal(step - 1).global;
  Array1D<apf::Field*> xi_prev = disc->primal(step - 1).local;

  // create the field to fill in
  apf::FieldShape* shape = state->disc->lv_shape();
  apf::Field* field = apf::createField(mesh, "sigma", apf::MATRIX, shape);
  apf::zeroField(field);
  if (step == 0) return field;

  // perform initializations of the residual objects
  global->before_elems(disc);

  // loop over all element sets in the discretization
  for (int es = 0; es < disc->num_elem_sets(); ++es) {

    local->before_elems(es, disc);

    // gather the elements in the current element set
    std::string const& es_name = disc->elem_set_name(es);
    ElemSet const& elems = disc->elems(es_name);

    // loop over all elements in the element set
    for (size_t elem = 0; elem < elems.size(); ++elem) {

      // get the current mesh element
      apf::MeshEntity* e = elems[elem];
      apf::MeshElement* me = apf::createMeshElement(mesh, e);

      // peform operations on element input
      global->set_elem(me);
      local->set_elem(me);
      global->gather(x, x_prev);

      // loop over all integration points in the current element
      int const npts = apf::countIntPoints(me, q_order);
      for (int pt = 0; pt < npts; ++pt) {

        // get integration point specific information
        apf::Vector3 iota;
        apf::getIntPoint(me, q_order, pt, iota);

        // evaluate the cauchy stress tensor at the point
        global->interpolate(iota);
        local->gather(pt, xi, xi_prev);
        double const p = global->scalar_x(pressure_idx);
        Tensor<double> const sigma = local->cauchy(global, p);

        // set the cauchy stress tensor to a field
        apf::Matrix3x3 apf_sigma(0, 0, 0, 0, 0, 0, 0, 0, 0);
        for (int i = 0; i < ndims; ++i) {
          for (int j = 0; j < ndims; ++j) {
            apf_sigma[i][j] = sigma(i, j);
          }
        }
        apf::setMatrix(field, e, pt, apf_sigma);

      }

      // perform operations on element output
      apf::destroyMeshElement(me);
      global->unset_elem();
      local->unset_elem();

    }
  }

  // perform clean-ups of the residual objects
  local->after_elems();
  global->after_elems();

  return field;

}