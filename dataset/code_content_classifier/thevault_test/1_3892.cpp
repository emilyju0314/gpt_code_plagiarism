static void parse_logging(JSON_Object *root_object)
{
    if (json_object_dotget_value(root_object, "desired.Logging") != nullptr)
    {
        util::set_logging(json_object_dotget_boolean(root_object, "desired.Logging"));
    }
    if (json_object_get_value(root_object, "Logging") != nullptr)
    {
        util::set_logging(json_object_get_boolean(root_object, "Logging"));
    }
}