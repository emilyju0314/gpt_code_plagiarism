void NodeMap::Cancel(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    auto nodeMap = Nan::ObjectWrap::Unwrap<NodeMap>(info.Holder());

    if (!nodeMap->map) return Nan::ThrowError(releasedMessage());
    if (!nodeMap->req) return Nan::ThrowError("No render in progress");

    try {
        nodeMap->cancel();
    } catch (const std::exception &ex) {
        return Nan::ThrowError(ex.what());
    }

    info.GetReturnValue().SetUndefined();
}