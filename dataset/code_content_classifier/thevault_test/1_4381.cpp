int
info()
{
    if (g_dev == nullptr) {
        PX4_ERR("driver not running");
        return ERROR;
    }

    PX4_DEBUG("state @ %p", g_dev);

    return OK;
}