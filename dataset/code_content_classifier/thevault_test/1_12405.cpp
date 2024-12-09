ReturnCode WrappedImpactAnalysisTestSequence(
            const CommandLineOptions& options,
            Runtime& runtime,
            const AZStd::optional<ChangeList>& changeList)
        {
            // Even though it is possible for a regular run to be selected (see below) which does not actually require a change list,
            // consider any impact analysis sequence type without a change list to be an error
            AZ_TestImpact_Eval(
                changeList.has_value(),
                CommandLineOptionsException,
                "Expected a change list for impact analysis but none was provided");

            if (options.HasSafeMode())
            {
                if (options.GetTestSequenceType() == TestSequenceType::ImpactAnalysis)
                {
                    return ConsumeSequenceReportAndGetReturnCode(
                        runtime.SafeImpactAnalysisTestSequence(
                            changeList.value(),
                            options.GetTestPrioritizationPolicy(),
                            options.GetTestTargetTimeout(),
                            options.GetGlobalTimeout(),
                            SafeImpactAnalysisTestSequenceStartCallback,
                            SafeImpactAnalysisTestSequenceCompleteCallback,
                            TestRunCompleteCallback),
                        options);
                }
                else if (options.GetTestSequenceType() == TestSequenceType::ImpactAnalysisNoWrite)
                {
                    // A no-write impact analysis sequence with safe mode enabled is functionally identical to a regular sequence type
                    // due to a) the selected tests being run without instrumentation and b) the discarded tests also being run without
                    // instrumentation
                    return ConsumeSequenceReportAndGetReturnCode(
                        runtime.RegularTestSequence(
                            options.GetTestTargetTimeout(),
                            options.GetGlobalTimeout(),
                            TestSequenceStartCallback,
                            RegularTestSequenceCompleteCallback,
                            TestRunCompleteCallback),
                        options);
                }
                else
                {
                    throw(Exception("Unexpected sequence type"));
                }
            }
            else
            {
                Policy::DynamicDependencyMap dynamicDependencyMapPolicy;
                if (options.GetTestSequenceType() == TestSequenceType::ImpactAnalysis)
                {
                    dynamicDependencyMapPolicy = Policy::DynamicDependencyMap::Update;
                }
                else if (options.GetTestSequenceType() == TestSequenceType::ImpactAnalysisNoWrite)
                {
                    dynamicDependencyMapPolicy = Policy::DynamicDependencyMap::Discard;
                }
                else
                {
                    throw(Exception("Unexpected sequence type"));
                }
        
                return ConsumeSequenceReportAndGetReturnCode(
                    runtime.ImpactAnalysisTestSequence(
                        changeList.value(),
                        options.GetTestPrioritizationPolicy(),
                        dynamicDependencyMapPolicy,
                        options.GetTestTargetTimeout(),
                        options.GetGlobalTimeout(),
                        ImpactAnalysisTestSequenceStartCallback,
                        ImpactAnalysisTestSequenceCompleteCallback,
                        TestRunCompleteCallback),
                    options);
            }
        }