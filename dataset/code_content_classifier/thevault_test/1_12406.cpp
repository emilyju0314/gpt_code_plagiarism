ReturnCode Main(int argc, char** argv)
        {
            try
            {
                CommandLineOptions options(argc, argv);
                AZStd::optional<ChangeList> changeList;

                // If we have a change list, check to see whether or not the client has requested the printing of said change list
                if (options.HasChangeListFilePath())
                {
                    changeList = DeserializeChangeList(ReadFileContents<CommandLineOptionsException>(*options.GetChangeListFilePath()));
                }

                // As of now, there are no non-test operations but leave this door open for the future
                if (options.GetTestSequenceType() == TestSequenceType::None)
                {
                    return ReturnCode::Success;
                }

                std::cout << "Constructing in-memory model of source tree and test coverage for test suite ";
                std::cout << SuiteTypeAsString(options.GetSuiteFilter()).c_str() << ", this may take a moment...\n";
                Runtime runtime(
                    RuntimeConfigurationFactory(ReadFileContents<CommandLineOptionsException>(options.GetConfigurationFilePath())),
                    options.GetDataFilePath(),
                    options.GetSuiteFilter(),
                    options.GetExecutionFailurePolicy(),
                    options.GetFailedTestCoveragePolicy(),
                    options.GetTestFailurePolicy(),
                    options.GetIntegrityFailurePolicy(),
                    options.GetTestShardingPolicy(),
                    options.GetTargetOutputCapture(),
                    options.GetMaxConcurrency());

                if (runtime.HasImpactAnalysisData())
                {
                    std::cout << "Test impact analysis data for this repository was found.\n";
                }
                else
                {
                    std::cout << "Test impact analysis data for this repository was not found, seed or regular sequence fallbacks will be used.\n";
                }

                switch (const auto type = options.GetTestSequenceType())
                {
                case TestSequenceType::Regular:
                {
                    return ConsumeSequenceReportAndGetReturnCode(
                        runtime.RegularTestSequence(
                            options.GetTestTargetTimeout(),
                            options.GetGlobalTimeout(),
                            TestSequenceStartCallback,
                            RegularTestSequenceCompleteCallback,
                            TestRunCompleteCallback),
                        options);
                }
                case TestSequenceType::Seed:
                {
                    return ConsumeSequenceReportAndGetReturnCode(
                        runtime.SeededTestSequence(
                            options.GetTestTargetTimeout(),
                            options.GetGlobalTimeout(),
                            TestSequenceStartCallback,
                            SeedTestSequenceCompleteCallback,
                            TestRunCompleteCallback),
                        options);
                }
                case TestSequenceType::ImpactAnalysisNoWrite:
                case TestSequenceType::ImpactAnalysis:
                {
                    return WrappedImpactAnalysisTestSequence(options, runtime, changeList);
                }
                case TestSequenceType::ImpactAnalysisOrSeed:
                {
                    if (runtime.HasImpactAnalysisData())
                    {
                        return WrappedImpactAnalysisTestSequence(options, runtime, changeList);
                    }
                    else
                    {
                        return ConsumeSequenceReportAndGetReturnCode(
                            runtime.SeededTestSequence(
                                options.GetTestTargetTimeout(),
                                options.GetGlobalTimeout(),
                                TestSequenceStartCallback,
                                SeedTestSequenceCompleteCallback,
                                TestRunCompleteCallback),
                            options);
                    }
                }
                default:
                    std::cout << "Unexpected TestSequenceType value: " << static_cast<size_t>(type) << std::endl;
                    return ReturnCode::UnknownError;
                }
            }
            catch (const CommandLineOptionsException& e)
            {
                std::cout << e.what() << std::endl;
                std::cout << CommandLineOptions::GetCommandLineUsageString().c_str() << std::endl;
                return ReturnCode::InvalidArgs;
            }
            catch (const ChangeListException& e)
            {
                std::cout << e.what() << std::endl;
                return ReturnCode::InvalidUnifiedDiff;
            }
            catch (const ConfigurationException& e)
            {
                std::cout << e.what() << std::endl;
                return ReturnCode::InvalidConfiguration;
            }
            catch (const RuntimeException& e)
            {
                std::cout << e.what() << std::endl;
                return ReturnCode::RuntimeError;
            }
            catch (const Exception& e)
            {
                std::cout << e.what() << std::endl;
                return ReturnCode::UnhandledError;
            }
            catch (const std::exception& e)
            {
                std::cout << e.what() << std::endl;
                return ReturnCode::UnknownError;
            }
            catch (...)
            {
                std::cout << "An unknown error occurred" << std::endl;
                return ReturnCode::UnknownError;
            }
        }