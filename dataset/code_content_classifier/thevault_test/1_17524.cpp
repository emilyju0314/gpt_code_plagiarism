float CSLModel::FetchVertOfsFromObjFile () const
{
    // This is a thread main function, set thread's name and try to catch all exceptions
    SET_THREAD_NAME("XPMP2_VertOfs");

    float ret = 0.0f;
    try {
        for (const CSLObj& obj: listObj) {
            const float o = obj.FetchVertOfsFromObjFile();
            if (o > ret)
                ret = o;
        }
    }
    catch(const std::exception& e) {
        LOG_MSG(logERR, "Reading vertical offsets failed: %s", e.what());
    }
    catch (...) {
        LOG_MSG(logERR, "Reading vertical offsets failed with an exception");
    }
    return ret;
}