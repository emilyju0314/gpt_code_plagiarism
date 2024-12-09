std::shared_ptr<TriggerResultInserter>
    makeInserter(ParameterSet& proc_pset,
                 PreallocationConfiguration const& iPrealloc,
                 ProductRegistry& preg,
                 ExceptionToActionTable const& actions,
                 std::shared_ptr<ActivityRegistry> areg,
                 std::shared_ptr<ProcessConfiguration> processConfiguration) {

      ParameterSet* trig_pset = proc_pset.getPSetForUpdate("@trigger_paths");
      trig_pset->registerIt();

      WorkerParams work_args(trig_pset, preg, &iPrealloc, processConfiguration, actions);
      ModuleDescription md(trig_pset->id(),
                           "TriggerResultInserter",
                           "TriggerResults",
                           processConfiguration.get(),
                           ModuleDescription::getUniqueID());

      areg->preModuleConstructionSignal_(md);
      bool postCalled = false;
      std::shared_ptr<TriggerResultInserter> returnValue;
      try {
        maker::ModuleHolderT<TriggerResultInserter> holder(make_shared_noexcept_false<TriggerResultInserter>(*trig_pset, iPrealloc.numberOfStreams()),static_cast<Maker const*>(nullptr));
        holder.setModuleDescription(md);
        holder.registerProductsAndCallbacks(&preg);
        returnValue =holder.module();
        postCalled = true;
        // if exception then post will be called in the catch block
        areg->postModuleConstructionSignal_(md);
      }
      catch (...) {
        if(!postCalled) {
          try {
            areg->postModuleConstructionSignal_(md);
          }
          catch (...) {
            // If post throws an exception ignore it because we are already handling another exception
          }
        }
        throw;
      }
      return returnValue;
    }