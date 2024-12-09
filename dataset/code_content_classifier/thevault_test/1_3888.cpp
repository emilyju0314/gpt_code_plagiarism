static void update_retraining_data_collection_parameters(bool enable, unsigned long int interval_seconds)
{
    if (update_collection_params_cb == nullptr)
    {
        util::log_info("Attempting to update the data collection parameters before a callback function is set.");
        return;
    }

    // Update the data collection parameters
    (*update_collection_params_cb)(enable, interval_seconds);
}