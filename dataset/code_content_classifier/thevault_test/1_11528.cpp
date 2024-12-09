void UTCTask::generateException(const std::exception_ptr &e)
{
    if (e)
    {
        std::rethrow_exception(e);
    }
}