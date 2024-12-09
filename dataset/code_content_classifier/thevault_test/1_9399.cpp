void ExecuteSendRequest(napi_env env, void *data)
{
    SendRequestParam *param = reinterpret_cast<SendRequestParam *>(data);
    param->errCode = param->target->SendRequest(param->code,
        *(param->data.get()), *(param->reply.get()), param->option);
    DBINDER_LOGI("sendRequest done, errCode:%{public}d", param->errCode);
}