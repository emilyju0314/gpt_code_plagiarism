bool
exception_compatible(const char *name)
{
    bool compatible = false;
    bool noErrors = true;

    // If the jump_retval variable is zero then we do not have an exception.
    if(jump_retval != 0)
    {
        int index = jump_retval - 100;
        const char *exeception_name = exception_tree[index].name;

        if(strcmp(exeception_name, name) == 0)
            compatible = true;
        else
        {
            // We have to traverse up the inheritance hierarchy to find a
            // compatible exception type.
            do
            {
                const char *eptr = exception_tree[index].parent_name;

                if(eptr == NULL)
                {
                    // There is no parent for this exception, say that
                    // it is compatible to get out of the loop, but set the
                    // error flag.
                    compatible = true;
                    noErrors = false;
                }
                else
                { 
                    compatible = (strcmp(eptr, name) == 0);
                    if(!compatible)
                        index = exception_lookup(eptr) - 100;
                }
            } while(!compatible);
        }
    }

    return (compatible && noErrors);
}