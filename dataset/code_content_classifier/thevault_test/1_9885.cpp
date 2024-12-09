static int
recursive_exception_lookup(const char *name, int start, int end)
{
    int retval = start;

    int delta = (end - start) >> 1;
    int pivot = start + delta;
    int comp = strcmp(name, exception_tree[pivot].name);

    if(delta == 0)
        retval = (comp == 0) ? pivot : -1;
    else if(comp < 0)
        retval = recursive_exception_lookup(name, start, pivot);
    else if(comp == 0)
        retval = (comp == 0) ? pivot : -1;
    else
        retval = recursive_exception_lookup(name, pivot, end);

    return retval;
}