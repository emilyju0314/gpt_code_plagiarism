int  List::getElementCount() const{
    int allElements=0;
    for(int i=0; i<10 ;i++)
    {
        allElements=elementCount[i]+allElements;
    }
    return allElements;
}