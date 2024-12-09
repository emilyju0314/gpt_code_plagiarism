ArrayBO cat_array(const ArrayBO &a, const ArrayBO &b)
{
    ArrayBO output;
    output.resize(a.size() + b.size());
    output.head(a.size()) = a;
    output.tail(b.size()) = b;
    return output;
}