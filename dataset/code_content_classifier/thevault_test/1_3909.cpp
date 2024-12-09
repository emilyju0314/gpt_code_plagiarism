const char* unique_string(const char* string_name)
{
    static const char* empty_string_s = "";

    if (!string_name || !*string_name) return empty_string_s;
    
    ADOBE_GLOBAL_MUTEX_INSTANCE(name_t);

    static adobe::unique_string_pool_t unique_string_s;

    return unique_string_s.add(string_name);
}