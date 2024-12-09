int DefaultLogger::get_uncaught_exceptions(bool cons = false) {
#if __cplusplus > 201402L
    // we can only do this fully correctly in C++17
    (void)cons;
    return std::uncaught_exceptions();
#else
    if(cons) {
        return 0;
    }
    return static_cast<int>(std::uncaught_exception());
#endif
}