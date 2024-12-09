static void update_model(const std::string &data)
{
    if (update_cb == nullptr)
    {
        util::log_info("Attempting to update model before the model callback function is set.");
        return;
    }

    // Update the model
    (*update_cb)(data, false);
}