static void update_model(const secure::SecureAIParams &params)
{
    if (update_cb == nullptr)
    {
        util::log_info("Attempting to update the model with the secure AI functions before a callback function is set.");
        return;
    }

    // Update the model
    (*update_cb)(params.to_string(), true);
}