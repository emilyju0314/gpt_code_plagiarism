gcDisconnectObject::gcDisconnectObject(gcObject*const object){

    parent = object;

    // Continue at root scope at time of object destruction (come out from object scope)
    _gc_scope_info->current_scope_stack.push_back(_gc_scope_info->current_scope);
    _gc_scope_info->current_scope = _gc_scope_info->root_scope;
}