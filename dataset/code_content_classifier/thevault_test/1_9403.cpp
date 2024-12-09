napi_value NapiOhosRpcMessageOptionSetWaittime(napi_env env, napi_callback_info info)
{
    napi_value thisVar = nullptr;
    size_t argc = 1;
    napi_value argv[1] = { 0 };
    napi_get_cb_info(env, info, &argc, argv, &thisVar, nullptr);
    NAPI_ASSERT(env, thisVar != nullptr && argv[0] != nullptr, "failed to get js message option object");
    napi_valuetype valueType = napi_null;
    napi_typeof(env, argv[0], &valueType);
    NAPI_ASSERT(env, valueType == napi_number, "type mismatch for parameter 1");
    int32_t waittime = 0;
    napi_status status = napi_get_value_int32(env, argv[0], &waittime);
    NAPI_ASSERT(env, status == napi_ok, "failed to get int32 value");
    MessageOption *option = nullptr;
    status = napi_unwrap(env, thisVar, (void **)&option);
    NAPI_ASSERT(env, option != nullptr, "failed to get native message option");
    option->SetWaitTime(waittime);
    napi_value result = nullptr;
    napi_get_undefined(env, &result);
    return result;
}