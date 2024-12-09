Flag CouplingIterationInterface::oneIteration(AdaptInfo& adaptInfo, Flag toDo)
  {
    Flag flag = 0;

    for (size_t i = 0; i < problems.size(); ++i)
    {
      if (solveProblem[i])
      {
        problems[i]->beginIteration(adaptInfo);
        flag |= problems[i]->oneIteration(adaptInfo, toDo);
        problems[i]->endIteration(adaptInfo);
      }
    }

    return flag;
  }