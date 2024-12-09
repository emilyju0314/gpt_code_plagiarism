Factory * Factory::instance()
{
    static Factory obj;
    return &obj;
}