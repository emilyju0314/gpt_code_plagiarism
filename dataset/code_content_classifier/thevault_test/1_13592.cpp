Block* Parser::ParseVariableDeclarations(bool accept_IN,
                                         Expression** var,
                                         bool* ok) {
  // VariableDeclarations ::
  //   ('var' | 'const') (Identifier ('=' AssignmentExpression)?)+[',']

  Variable::Mode mode = Variable::VAR;
  bool is_const = false;
  if (peek() == Token::VAR) {
    Consume(Token::VAR);
  } else if (peek() == Token::CONST) {
    Consume(Token::CONST);
    mode = Variable::CONST;
    is_const = true;
  } else {
    UNREACHABLE();  // by current callers
  }

  // The scope of a variable/const declared anywhere inside a function
  // is the entire function (ECMA-262, 3rd, 10.1.3, and 12.2). Thus we can
  // transform a source-level variable/const declaration into a (Function)
  // Scope declaration, and rewrite the source-level initialization into an
  // assignment statement. We use a block to collect multiple assignments.
  //
  // We mark the block as initializer block because we don't want the
  // rewriter to add a '.result' assignment to such a block (to get compliant
  // behavior for code such as print(eval('var x = 7')), and for cosmetic
  // reasons when pretty-printing. Also, unless an assignment (initialization)
  // is inside an initializer block, it is ignored.
  //
  // Create new block with one expected declaration.
  Block* block = NEW(Block(NULL, 1, true));
  VariableProxy* last_var = NULL;  // the last variable declared
  int nvars = 0;  // the number of variables declared
  do {
    if (fni_ != NULL) fni_->Enter();

    // Parse variable name.
    if (nvars > 0) Consume(Token::COMMA);
    Handle<String> name = ParseIdentifier(CHECK_OK);
    if (fni_ != NULL) fni_->PushVariableName(name);

    // Declare variable.
    // Note that we *always* must treat the initial value via a separate init
    // assignment for variables and constants because the value must be assigned
    // when the variable is encountered in the source. But the variable/constant
    // is declared (and set to 'undefined') upon entering the function within
    // which the variable or constant is declared. Only function variables have
    // an initial value in the declaration (because they are initialized upon
    // entering the function).
    //
    // If we have a const declaration, in an inner scope, the proxy is always
    // bound to the declared variable (independent of possibly surrounding with
    // statements).
    last_var = Declare(name, mode, NULL,
                       is_const /* always bound for CONST! */,
                       CHECK_OK);
    nvars++;

    // Parse initialization expression if present and/or needed. A
    // declaration of the form:
    //
    //    var v = x;
    //
    // is syntactic sugar for:
    //
    //    var v; v = x;
    //
    // In particular, we need to re-lookup 'v' as it may be a
    // different 'v' than the 'v' in the declaration (if we are inside
    // a 'with' statement that makes a object property with name 'v'
    // visible).
    //
    // However, note that const declarations are different! A const
    // declaration of the form:
    //
    //   const c = x;
    //
    // is *not* syntactic sugar for:
    //
    //   const c; c = x;
    //
    // The "variable" c initialized to x is the same as the declared
    // one - there is no re-lookup (see the last parameter of the
    // Declare() call above).

    Expression* value = NULL;
    int position = -1;
    if (peek() == Token::ASSIGN) {
      Expect(Token::ASSIGN, CHECK_OK);
      position = scanner().location().beg_pos;
      value = ParseAssignmentExpression(accept_IN, CHECK_OK);
      // Don't infer if it is "a = function(){...}();"-like expression.
      if (fni_ != NULL && value->AsCall() == NULL) fni_->Infer();
    }

    // Make sure that 'const c' actually initializes 'c' to undefined
    // even though it seems like a stupid thing to do.
    if (value == NULL && is_const) {
      value = GetLiteralUndefined();
    }

    // Global variable declarations must be compiled in a specific
    // way. When the script containing the global variable declaration
    // is entered, the global variable must be declared, so that if it
    // doesn't exist (not even in a prototype of the global object) it
    // gets created with an initial undefined value. This is handled
    // by the declarations part of the function representing the
    // top-level global code; see Runtime::DeclareGlobalVariable. If
    // it already exists (in the object or in a prototype), it is
    // *not* touched until the variable declaration statement is
    // executed.
    //
    // Executing the variable declaration statement will always
    // guarantee to give the global object a "local" variable; a
    // variable defined in the global object and not in any
    // prototype. This way, global variable declarations can shadow
    // properties in the prototype chain, but only after the variable
    // declaration statement has been executed. This is important in
    // browsers where the global object (window) has lots of
    // properties defined in prototype objects.

    if (!is_pre_parsing_ && top_scope_->is_global_scope()) {
      // Compute the arguments for the runtime call.
      ZoneList<Expression*>* arguments = new ZoneList<Expression*>(2);
      // Be careful not to assign a value to the global variable if
      // we're in a with. The initialization value should not
      // necessarily be stored in the global object in that case,
      // which is why we need to generate a separate assignment node.
      arguments->Add(NEW(Literal(name)));  // we have at least 1 parameter
      if (is_const || (value != NULL && !inside_with())) {
        arguments->Add(value);
        value = NULL;  // zap the value to avoid the unnecessary assignment
      }
      // Construct the call to Runtime::DeclareGlobal{Variable,Const}Locally
      // and add it to the initialization statement block. Note that
      // this function does different things depending on if we have
      // 1 or 2 parameters.
      CallRuntime* initialize;
      if (is_const) {
        initialize =
          NEW(CallRuntime(
            Factory::InitializeConstGlobal_symbol(),
            Runtime::FunctionForId(Runtime::kInitializeConstGlobal),
            arguments));
      } else {
        initialize =
          NEW(CallRuntime(
            Factory::InitializeVarGlobal_symbol(),
            Runtime::FunctionForId(Runtime::kInitializeVarGlobal),
            arguments));
      }
      block->AddStatement(NEW(ExpressionStatement(initialize)));
    }

    // Add an assignment node to the initialization statement block if
    // we still have a pending initialization value. We must distinguish
    // between variables and constants: Variable initializations are simply
    // assignments (with all the consequences if they are inside a 'with'
    // statement - they may change a 'with' object property). Constant
    // initializations always assign to the declared constant which is
    // always at the function scope level. This is only relevant for
    // dynamically looked-up variables and constants (the start context
    // for constant lookups is always the function context, while it is
    // the top context for variables). Sigh...
    if (value != NULL) {
      Token::Value op = (is_const ? Token::INIT_CONST : Token::INIT_VAR);
      Assignment* assignment = NEW(Assignment(op, last_var, value, position));
      if (block) block->AddStatement(NEW(ExpressionStatement(assignment)));
    }

    if (fni_ != NULL) fni_->Leave();
  } while (peek() == Token::COMMA);

  if (!is_const && nvars == 1) {
    // We have a single, non-const variable.
    if (is_pre_parsing_) {
      // If we're preparsing then we need to set the var to something
      // in order for for-in loops to parse correctly.
      *var = ValidLeftHandSideSentinel::instance();
    } else {
      ASSERT(last_var != NULL);
      *var = last_var;
    }
  }

  return block;
}