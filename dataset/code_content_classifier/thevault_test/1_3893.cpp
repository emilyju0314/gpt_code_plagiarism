static void parse_retraining(JSON_Object *root_object)
{
    bool got_something = false;
    bool enable = false;
    int interval = 0;

    if (json_object_dotget_value(root_object, "desired.RetrainingDataCollectionEnabled") != nullptr)
    {
        enable = json_object_dotget_boolean(root_object, "desired.RetrainingDataCollectionEnabled");
        got_something = true;
    }
    if (json_object_get_value(root_object, "RetrainingDataCollectionEnabled") != nullptr)
    {
        enable = json_object_get_boolean(root_object, "RetrainingDataCollectionEnabled");
        got_something = true;
    }

    if (json_object_dotget_value(root_object, "desired.RetrainingDataCollectionInterval") != nullptr)
    {
        interval = json_object_dotget_number(root_object, "desired.RetrainingDataCollectionInterval");
        got_something = true;
    }
    if (json_object_get_value(root_object, "RetrainingDataCollectionInterval") != nullptr)
    {
        interval = json_object_get_number(root_object, "RetrainingDataCollectionInterval");
        got_something = true;
    }

    // Deal with signedness (the JSON value is an int, but we want a uint)
    const unsigned long int default_interval_seconds = 60;
    unsigned long int uinterval;
    if (interval < 0)
    {
        util::log_error("RetrainingDataCollectionInterval is negative, which does not make sense. Setting to a default value of " + std::to_string(default_interval_seconds));
        uinterval = default_interval_seconds;
    }
    else
    {
        uinterval = (unsigned long int)interval;
    }

    // Only update the retraining data collection parameters if we got something from the JSON.
    // Otherwise we let it keep going with whatever values it already had.
    if (got_something)
    {
        update_retraining_data_collection_parameters(enable, uinterval);
    }
}