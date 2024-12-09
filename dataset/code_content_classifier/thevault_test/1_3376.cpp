static void AddOptimizationPasses(legacy::PassManagerBase &MPM,
                                      legacy::FunctionPassManager &FPM,
                                      TargetMachine *TM,
                                      unsigned OptLevel, unsigned SizeLevel)
    {
        FPM.add(createVerifierPass()); // Verify that input is correct

        PassManagerBuilder Builder;
        Builder.OptLevel = OptLevel;
        Builder.SizeLevel = SizeLevel;

        if (DisableInline)
        {
            // No inlining pass
        }
        else if (OptLevel > 1)
        {
            Builder.Inliner = createFunctionInliningPass(OptLevel, SizeLevel, false);
        }
        else
        {
            Builder.Inliner = createAlwaysInlinerLegacyPass();
        }
        Builder.DisableUnitAtATime = !UnitAtATime;
        Builder.DisableUnrollLoops = OptLevel == 0;

        // This is final, unless there is a #pragma vectorize enable
        if (DisableLoopVectorization)
            Builder.LoopVectorize = false;
        // If option wasn't forced via cmd line (-vectorize-loops, -loop-vectorize)
        else if (!Builder.LoopVectorize)
            Builder.LoopVectorize = OptLevel > 1 && SizeLevel < 2;

        // When #pragma vectorize is on for SLP, do the same as above
        Builder.SLPVectorize =
            DisableSLPVectorization ? false : OptLevel > 1 && SizeLevel < 2;

        if (TM)
            TM->adjustPassManager(Builder);

        Builder.populateFunctionPassManager(FPM);
        Builder.populateModulePassManager(MPM);

    }