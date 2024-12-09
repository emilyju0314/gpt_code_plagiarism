std::string CouplingIterationInterface::getName(int number) const
  {
    TEST_EXIT(getNumIterationInterfaces() > number)("Problem number out of range.");

    return problems[number]->getName();
  }