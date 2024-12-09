void TaskDelCommand::delTask(const std::string& name)
{
    db::DB db(getFactory());
    db.connect();

    db::Parameters params;

    // IN task_name VARCHAR(255),
    // OUT return_value INT
    params.add("@name", name);
    params.add("@return_value");

    db::Result res = db.callSimple("klk_app_transcode_task_del_cli", params);
    if (res["@return_value"].toInt() != 0)
    {
        throw Exception(__FILE__, __LINE__, "Failed to delete the task");
    }
}