void actions::copy_macros_for_write()
    {
        if(macro_change_depth != state_stack.size())
        {
            macro_stack.push(macro);
            macro_change_depth = state_stack.size();
        }
    }