unsigned executeFile(const std::string& pathToInputFile, CMakeStrategySolver* solver, const smtrat::RuntimeSettingsManager& settingsManager) {
#ifdef __WIN
//TODO: do not use magical number
#pragma comment(linker, "/STACK:10000000")
#else
	// Increase stack size to the maximum.
	rlimit rl;
	getrlimit(RLIMIT_STACK, &rl);
	rl.rlim_cur = rl.rlim_max;
	setrlimit(RLIMIT_STACK, &rl);
#endif

	std::ifstream infile(pathToInputFile);
	if (!infile.good()) {
            std::cerr << "Could not open file: " << pathToInputFile << std::endl;
            exit(SMTRAT_EXIT_NOSUCHFILE);
	}
	Executor* e = new Executor(solver);
	if (settingsManager.exportDIMACS()) e->exportDIMACS = true;
	{
		if (!smtrat::parseSMT2File(e, true, infile)) {
            std::cerr << "Parse error" << std::endl;
            delete e;
            exit(SMTRAT_EXIT_PARSERFAILURE);
        }
	}
	if (e->hasInstructions()) e->runInstructions();
	unsigned exitCode = e->getExitCode();
	if (e->lastAnswer == smtrat::Answer::SAT) {
		if (settingsManager.printModel()) solver->printAssignment();
		else if (settingsManager.printAllModels()) solver->printAllAssignments(std::cout);
	}
        else if(e->lastAnswer == smtrat::Answer::UNKNOWN) {
            if (settingsManager.printInputSimplified())
            {
                std::stringstream sstream;
                if (solver->logic() != smtrat::Logic::UNDEFINED)
                    sstream << "(set-logic " << solver->logic() << ")" << std::endl;
                smtrat::FormulaT formula = solver->getInputSimplified().second;

                smtrat::Model model = solver->model();
                for (const auto& obj: solver->objectives()) {
                    smtrat::ModelPolynomialSubstitution mps(obj.first);
                    smtrat::ModelValue mv = mps.evaluate(model);
                    formula = smtrat::FormulaT(carl::FormulaType::AND, formula, smtrat::FormulaT(obj.first - mv.asRational(), carl::Relation::EQ));
                }
                sstream << formula.toString( false, 1, "", false, false, true, true ) << std::endl;
                for (const auto& obj: solver->objectives()) {
                    if (obj.second.second) {
                        sstream << "(minimize " << obj.first << ")" << std::endl;
                    } else {
                        sstream << "(maximize " << obj.first << ")" << std::endl;
                    }
                }
                sstream << "(check-sat)" << std::endl;
                if( settingsManager.simplifiedInputFileName() == "" )
                    e->regular() << sstream.str();
                else
                {
                    std::ofstream file;
                    file.open(settingsManager.simplifiedInputFileName());
                    file << sstream.str();
                    file.close();
                }
            }
        }
	delete e;
	return exitCode;
}