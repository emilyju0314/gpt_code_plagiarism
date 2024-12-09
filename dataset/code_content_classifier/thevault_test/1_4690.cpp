inline void error_check_common_conditions(ULONG status, const EVENT_RECORD &record)
    {
        if (status == ERROR_SUCCESS) {
            return;
        }

        auto context = get_status_and_record_context(status, record);

        switch (status) {
        case ERROR_ALREADY_EXISTS:
            throw krabs::trace_already_registered();
        case ERROR_INVALID_PARAMETER:
            throw krabs::invalid_parameter();
        case ERROR_ACCESS_DENIED:
            throw krabs::need_to_be_admin_failure();
        case ERROR_NOT_FOUND:
            throw krabs::could_not_find_schema(context);
        case ERROR_NO_SYSTEM_RESOURCES:
            throw krabs::no_trace_sessions_remaining();
        case ERROR_NOT_SUPPORTED:
            throw krabs::function_not_supported();
        default:
            throw krabs::unexpected_error(context);
        }
    }