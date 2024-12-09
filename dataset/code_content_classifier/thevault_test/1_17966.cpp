Patient* List::search(const Patient& target){
    colindex=getIndex(target);

    for( int i = 0; i < 10; i++)
    {
        if( (elements[colindex][i]) == target)
        {
            return &(elements[colindex][i]);
            break;
        }
    }
    return NULL;
}