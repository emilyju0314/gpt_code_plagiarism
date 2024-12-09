void SymVariables::init(const vector<int> &v_order, bool aux_variables) {
  if (!aux_variables) {
    cout << "Initializing Symbolic Variables" << endl;
  } else {
    cout << "Initializing Symbolic Variables (incl. auxillary Variables)"
         << endl;
  }
  var_order = vector<int>(v_order);
  int num_fd_vars = var_order.size();

  // Initialize binary representation of variables.
  numBDDVars = 0;
  bdd_index_pre = vector<vector<int>>(v_order.size());
  bdd_index_eff = vector<vector<int>>(v_order.size());

  if (aux_variables) {
    bdd_index_aux = vector<vector<int>>(v_order.size());
  }
  int _numBDDVars = 0; // numBDDVars;
  for (int var : var_order) {
    int var_len = ceil(log2(getDomainSize(var)));
    numBDDVars += var_len;
    for (int j = 0; j < var_len; j++) {
      bdd_index_pre[var].push_back(_numBDDVars);
      bdd_index_eff[var].push_back(_numBDDVars + 1);

      if (aux_variables) {
        bdd_index_aux[var].push_back(_numBDDVars + 2);
        _numBDDVars += 3;

      } else {
        _numBDDVars += 2;
      }
    }
  }
  cout << "Num variables: " << var_order.size() << " => " << numBDDVars << " ["
       << _numBDDVars << "]" << endl;

  // Initialize manager
  cout << "Initialize Symbolic Manager(" << _numBDDVars << ", "
       << cudd_init_nodes / _numBDDVars << ", " << cudd_init_cache_size << ", "
       << cudd_init_available_memory << ")" << endl;
  manager = unique_ptr<Cudd>(
      new Cudd(_numBDDVars, 0, cudd_init_nodes / _numBDDVars,
               cudd_init_cache_size, cudd_init_available_memory));

  manager->setHandler(exceptionError);
  manager->setTimeoutHandler(exceptionError);
  manager->setNodesExceededHandler(exceptionError);

  cout << "Generating binary variables" << endl;
  // Generate binary_variables
  for (int i = 0; i < _numBDDVars; i++) {
    variables.push_back(manager->bddVar(i));
  }

  preconditionBDDs.resize(num_fd_vars);
  effectBDDs.resize(num_fd_vars);
  if (aux_variables) {
    auxBDDs.resize(num_fd_vars);
  }
  biimpBDDs.resize(num_fd_vars);
  validValues.resize(num_fd_vars);
  validBDD = oneBDD();
  // Generate predicate (precondition (s) and effect (s')) BDDs
  for (int var : var_order) {
    for (int j = 0; j < getDomainSize(var); j++) {
      preconditionBDDs[var].push_back(createPreconditionBDD(var, j));
      effectBDDs[var].push_back(createEffectBDD(var, j));
      if (aux_variables) {
        auxBDDs[var].push_back(createAuxBDD(var, j));
      }
    }
    validValues[var] = zeroBDD();
    for (int j = 0; j < getDomainSize(var); j++) {
      validValues[var] += preconditionBDDs[var][j];
    }
    validBDD *= validValues[var];
    biimpBDDs[var] =
        createBiimplicationBDD(bdd_index_pre[var], bdd_index_eff[var]);

    if (aux_variables) {
      auxBiimpBDDs.resize(num_fd_vars);
      auxBiimpBDDs[var] =
          createBiimplicationBDD(bdd_index_pre[var], bdd_index_aux[var]);
    }
  }

  for (int var : var_order) {
    for (int bdd_var : vars_index_pre(var)) {
      swapVarsPre.push_back(bddVar(bdd_var));
    }
    for (int bdd_var : vars_index_eff(var)) {
      swapVarsEff.push_back(bddVar(bdd_var));
    }
    for (int bdd_var : vars_index_aux(var)) {
      swapVarsAux.push_back(bddVar(bdd_var));
    }
  }

  existsVarsPre = oneBDD();
  existsVarsEff = oneBDD();
  existsVarsAux = oneBDD();

  for (size_t i = 0; i < swapVarsPre.size(); ++i) {
    existsVarsPre *= swapVarsPre[i];
    existsVarsEff *= swapVarsEff[i];
    existsVarsAux *= swapVarsAux[i];
  }

  cout << "Symbolic Variables... Done." << endl;
}