Newton(const std::string& name, LinearSolverInterface* linSolver)
      : NonLinSolver(name, linSolver),
        b(NULL),
        buildCycle(1)
    {

      Parameters::get(name + "->build cycle", buildCycle);
    }