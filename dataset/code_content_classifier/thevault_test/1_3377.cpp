static TargetMachine* GetTargetMachine(Triple TheTriple, StringRef CPUStr,
                                           StringRef FeaturesStr,
                                           const TargetOptions &Options,
                                           int OptLevel
                                          )
    {
        std::string Error;
        const Target *TheTarget = TargetRegistry::lookupTarget(MArch, TheTriple,
                                  Error);
        // Some modules don't specify a triple, and this is okay.
        if (!TheTarget)
        {
            return nullptr;
        }

        return TheTarget->createTargetMachine(TheTriple.getTriple(),
                                              CPUStr, FeaturesStr, Options,
                                              getRelocModel(),  getCodeModel(),
                                              GetCodeGenOptLevel(OptLevel));
    }