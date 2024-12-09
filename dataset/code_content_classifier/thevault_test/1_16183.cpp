ReplierListener(
            const std::function<T2(const T &)> &on_request)
            : on_request_(on_request)
    {
    }