void TheDebugStack::destroyInstance() {
      static TheDebugStack* debugStack = &getInstance();
      if (debugStack != nullptr) {
         delete debugStack;
      }
   }