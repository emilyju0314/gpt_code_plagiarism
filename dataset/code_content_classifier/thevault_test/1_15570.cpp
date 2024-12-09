bool MyArray::operator!=(MyArray &data) const
{
    //Returns the opposite of the operator== method.
    return !(*this == data);
}