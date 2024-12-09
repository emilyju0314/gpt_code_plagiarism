gcObjectScope::gcObjectScope() {

    // Push current context and set this one
    _gc_scope_info->current_scope_stack.push_back(_gc_scope_info->current_scope);
    _gc_scope_info->current_scope = &childreen;
}