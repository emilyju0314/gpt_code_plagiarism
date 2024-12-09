void Solve(const std::vector<std::vector<Task>>& tasks_per_job, int horizon) {
  int num_machines = 0;
  for (const std::vector<Task>& tasks : tasks_per_job) {
    for (const Task& task : tasks) {
      for (const int machine : task.machines) {
        num_machines = std::max(num_machines, machine + 1);
      }
    }
  }

  Model model;
  model.Add(NewSatParameters(FLAGS_params));

  // This is only used with --nouse_boolean_precedences.
  std::vector<IntegerVariable> decision_variables;

  const IntegerVariable makespan = model.Add(NewIntegerVariable(0, horizon));
  std::vector<std::vector<IntervalVariable>> machine_to_intervals(num_machines);
  for (const std::vector<Task>& tasks : tasks_per_job) {
    IntervalVariable previous_interval = kNoIntervalVariable;
    for (const Task& task : tasks) {
      const int num_alternatives = task.machines.size();
      CHECK_EQ(num_alternatives, task.durations.size());

      // Add the "main" task interval. It will englobe all the alternative ones
      // if there is many, or be a normal task otherwise.
      int min_duration = task.durations[0];
      int max_duration = task.durations[0];
      for (int i = 0; i < num_alternatives; ++i) {
        min_duration = std::min(min_duration, task.durations[i]);
        max_duration = std::max(max_duration, task.durations[i]);
      }
      const IntervalVariable interval = model.Add(
          NewIntervalWithVariableSize(0, horizon, min_duration, max_duration));
      decision_variables.push_back(model.Get(StartVar(interval)));

      // Chain the task belonging to the same job.
      if (previous_interval != kNoIntervalVariable) {
        model.Add(LowerOrEqual(model.Get(EndVar(previous_interval)),
                               model.Get(StartVar(interval))));
      }
      previous_interval = interval;

      if (num_alternatives == 1) {
        machine_to_intervals[task.machines[0]].push_back(interval);
      } else {
        std::vector<IntervalVariable> alternatives;
        for (int i = 0; i < num_alternatives; ++i) {
          const Literal is_present(model.Add(NewBooleanVariable()), true);
          const IntervalVariable alternative = model.Add(
              NewOptionalInterval(0, horizon, task.durations[i], is_present));
          alternatives.push_back(alternative);
          machine_to_intervals[task.machines[i]].push_back(alternative);
        }
        model.Add(IntervalWithAlternatives(interval, alternatives));
      }
    }

    // The makespan will be greater than the end of each job.
    model.Add(LowerOrEqual(model.Get(EndVar(previous_interval)), makespan));
  }

  // Add all the potential precedences between tasks on the same machine.
  for (int m = 0; m < num_machines; ++m) {
    if (FLAGS_use_boolean_precedences) {
      model.Add(DisjunctiveWithBooleanPrecedences(machine_to_intervals[m]));
    } else {
      model.Add(Disjunctive(machine_to_intervals[m]));
    }
  }

  LOG(INFO) << "#machines:" << num_machines;
  LOG(INFO) << "#jobs:" << tasks_per_job.size();
  LOG(INFO) << "#tasks:" << model.Get<IntervalsRepository>()->NumIntervals();

  if (FLAGS_use_boolean_precedences) {
    // We disable the lazy encoding in this case.
    decision_variables.clear();
  }
  MinimizeIntegerVariableWithLinearScanAndLazyEncoding(
      /*log_info=*/true, makespan,
      FirstUnassignedVarAtItsMinHeuristic(decision_variables, &model),
      /*feasible_solution_observer=*/
      [makespan](const Model& model) {
        LOG(INFO) << "Makespan " << model.Get(LowerBound(makespan));
      },
      &model);
}