gcObjectScope::~gcObjectScope() {

    // Free child connections
    delete childreen;

    // Return to previous context
    _gc_scope_info->current_scope = _gc_scope_info->current_scope_stack.back();
    _gc_scope_info->current_scope_stack.pop_back();
}