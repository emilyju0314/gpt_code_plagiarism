inline const char* statusToName(const AsynchTasks::ETaskStatus& pStatus) {
    switch (pStatus) {
    case AsynchTasks::ETaskStatus::Error: return "ERROR";
    case AsynchTasks::ETaskStatus::Setup: return "SETUP";
    case AsynchTasks::ETaskStatus::Pending: return "PENDING";
    case AsynchTasks::ETaskStatus::In_Progress: return "IN_PROGRESS";
    case AsynchTasks::ETaskStatus::Callback_On_Update: return "CALLBACK_ON_UPDATE";
    case AsynchTasks::ETaskStatus::Completed: return "COMPLETE";
    default: return "Unknown Status";
    }
}