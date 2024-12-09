napi_value NapiOhosRpcMessageOptionGetFlags(napi_env env, napi_callback_info info)
{
    napi_value thisVar = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, &thisVar, nullptr);
    NAPI_ASSERT(env, thisVar != nullptr, "failed to get js message option object");
    MessageOption *option = nullptr;
    napi_status status = napi_unwrap(env, thisVar, (void **)&option);
    NAPI_ASSERT(env, option != nullptr, "failed to get native message option");
    int flags = option->GetFlags();
    napi_value result = nullptr;
    status = napi_create_int32(env, flags, &result);
    NAPI_ASSERT(env, status == napi_ok, "failed to create int32 value");
    return result;
}