AttributeGroup::AttributeGroup(const char *formatString) : typeMap()
{
    guido = -1;
    CreateTypeMap(formatString);
}