void
  Binder::visit(const ast::LocalDeclaration* input)
  {
    super_type::visit(input);
    ast::rLocalDeclaration dec = result_.unsafe_cast<ast::LocalDeclaration>();
    if (dec->is_import_get() && !routine_stack_.empty())
      routine_stack_.back()->has_imports_set(true);
    if (!dec->is_star_get())
      bind(dec);
  }