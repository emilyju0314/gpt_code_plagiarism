void
binarySearchSet(unsigned &count,
                vector<Array<unsigned>* > *lists,
                unsigned data)
{
    vector<Array<unsigned>*>::iterator ite =
        lists->begin();

    while (ite != lists->end()) {
        Array<unsigned> *v = *ite;
        if (binarySearch(v, data, 0, v->size()))
            count++;
        ite++;
    }//end while

}