gcObjectScope::gcObjectScope() {

    // Create childreen list (without any scope management)
    childreen = new gcScopeContainer;

    // Push current context and set this one
    _gc_scope_info->current_scope_stack.push_back(_gc_scope_info->current_scope);
    _gc_scope_info->current_scope = childreen;
}