MyArray::~MyArray()
{
    // call the function empty instead, so we only need to modify in 
    // one place if anything changes
    empty();
}