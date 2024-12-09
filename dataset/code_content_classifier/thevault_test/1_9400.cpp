void SendRequestPromiseComplete(napi_env env, napi_status status, void *data)
{
    SendRequestParam *param = reinterpret_cast<SendRequestParam *>(data);
    napi_value result = nullptr;
    napi_create_int32(env, param->errCode, &result);
    DBINDER_LOGI("sendRequest complete, errCode:%{public}d", param->errCode);
    if (param->errCode == 0) {
        napi_resolve_deferred(env, param->deferred, result);
    } else {
        napi_reject_deferred(env, param->deferred, result);
    }
    napi_delete_async_work(env, param->asyncWork);
    delete param;
}