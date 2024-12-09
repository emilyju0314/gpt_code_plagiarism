std::map<const AstArgument*, TypeSet> TypeAnalysis::analyseTypes(
        const TypeEnvironment& env, const AstClause& clause, const AstProgram* program, std::ostream* logs) {
    struct Analysis : public AstConstraintAnalysis<TypeVar> {
        const TypeEnvironment& env;
        const AstProgram* program;
        std::set<const AstAtom*> negated;

        Analysis(const TypeEnvironment& env, const AstProgram* program) : env(env), program(program) {}

        // predicate
        void visitAtom(const AstAtom& atom) override {
            // get relation
            auto rel = getAtomRelation(&atom, program);
            if (!rel) {
                return;  // error in input program
            }

            auto atts = rel->getAttributes();
            auto args = atom.getArguments();
            if (atts.size() != args.size()) {
                return;  // error in input program
            }

            // set upper boundary of argument types
            for (unsigned i = 0; i < atts.size(); i++) {
                const auto& typeName = atts[i]->getTypeName();
                if (env.isType(typeName)) {
                    // check whether atom is not negated
                    if (negated.find(&atom) == negated.end()) {
                        addConstraint(isSubtypeOf(getVar(args[i]), env.getType(typeName)));
                    } else {
                        addConstraint(isSupertypeOf(getVar(args[i]), env.getType(typeName)));
                    }
                }
            }
        }

        // negations need to be skipped
        void visitNegation(const AstNegation& cur) override {
            // add nested atom to black-list
            negated.insert(cur.getAtom());
        }

        // symbol
        void visitStringConstant(const AstStringConstant& cnst) override {
            // this type has to be a sub-type of symbol
            addConstraint(isSubtypeOf(getVar(cnst), env.getSymbolType()));
        }

        // number
        void visitNumberConstant(const AstNumberConstant& cnst) override {
            // this type has to be a sub-type of number
            addConstraint(isSubtypeOf(getVar(cnst), env.getNumberType()));
        }

        // binary constraint
        void visitBinaryConstraint(const AstBinaryConstraint& rel) override {
            auto lhs = getVar(rel.getLHS());
            auto rhs = getVar(rel.getRHS());
            addConstraint(isSubtypeOf(lhs, rhs));
            addConstraint(isSubtypeOf(rhs, lhs));
        }

        // intrinsic functor
        void visitIntrinsicFunctor(const AstIntrinsicFunctor& fun) override {
            auto cur = getVar(fun);

            // add a constraint for the return type of the functor
            if (fun.isNumerical()) {
                addConstraint(isSubtypeOf(cur, env.getNumberType()));
            }
            if (fun.isSymbolic()) {
                addConstraint(isSubtypeOf(cur, env.getSymbolType()));
            }

            // add a constraint for each argument of the functor
            if (fun.getFunction() == FunctorOp::ORD) {
                return;
            }

            for (size_t i = 0; i < fun.getArity(); i++) {
                auto arg = getVar(fun.getArg(i));
                if (fun.acceptsNumbers(i)) {
                    addConstraint(isSubtypeOf(arg, env.getNumberType()));
                }
                if (fun.acceptsSymbols(i)) {
                    addConstraint(isSubtypeOf(arg, env.getSymbolType()));
                }
            }
        }

        // user-defined functors
        void visitUserDefinedFunctor(const AstUserDefinedFunctor& fun) override {
            auto cur = getVar(fun);

            // get functor declaration
            const AstFunctorDeclaration* funDecl = program->getFunctorDeclaration(fun.getName());
            // check whether functor declaration exists
            if (funDecl != nullptr) {
                // add a constraint for the return type
                if (funDecl->isNumerical()) {
                    addConstraint(isSubtypeOf(cur, env.getNumberType()));
                }
                if (funDecl->isSymbolic()) {
                    addConstraint(isSubtypeOf(cur, env.getSymbolType()));
                }

                // add constraints for arguments
                for (size_t i = 0; i < fun.getArgCount(); i++) {
                    auto arg = getVar(fun.getArg(i));

                    // check that usage does not exceed
                    // number of arguments in declaration
                    if (i < funDecl->getArgCount()) {
                        // add constraints for the i-th argument
                        if (funDecl->acceptsNumbers(i)) {
                            addConstraint(isSubtypeOf(arg, env.getNumberType()));
                        }
                        if (funDecl->acceptsSymbols(i)) {
                            addConstraint(isSubtypeOf(arg, env.getSymbolType()));
                        }
                    }
                }
            }
        }

        // counter
        void visitCounter(const AstCounter& counter) override {
            // this value must be a number value
            addConstraint(isSubtypeOf(getVar(counter), env.getNumberType()));
        }

        // components of records
        void visitRecordInit(const AstRecordInit& init) override {
            // link element types with sub-values
            auto rec = getVar(init);
            int i = 0;

            for (const AstArgument* value : init.getArguments()) {
                addConstraint(isSubtypeOfComponent(getVar(value), rec, i++));
            }
        }

        // visit aggregates
        void visitAggregator(const AstAggregator& agg) override {
            // this value must be a number value
            addConstraint(isSubtypeOf(getVar(agg), env.getNumberType()));

            // also, the target expression needs to be a number
            if (auto expr = agg.getTargetExpression()) {
                addConstraint(isSubtypeOf(getVar(expr), env.getNumberType()));
            }
        }
    };

    // run analysis
    return Analysis(env, program).analyse(clause, logs);
}