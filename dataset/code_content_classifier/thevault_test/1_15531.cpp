bool List::operator!=(const List &data)
{
    return !(*this == data); // call the operator== on the object,
                             // not on the pointer
}