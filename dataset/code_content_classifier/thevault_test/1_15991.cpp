bool AnnoyIndexWrapper::getFloatArrayParam(
  const Nan::FunctionCallbackInfo<v8::Value>& info, int paramIndex, float *vec) {

  bool succeeded = false;

  Local<Value> val;
  if (info[paramIndex]->IsArray()) {
    // TODO: Make sure it really is OK to use Local instead of Handle here.
    Local<Array> jsArray = Local<Array>::Cast(info[paramIndex]);
    Local<Value> val;
    for (unsigned int i = 0; i < jsArray->Length(); i++) {
      val = Nan::Get(jsArray, i).ToLocalChecked();
      // printf("Adding item to array: %f\n", (float)val->NumberValue(Nan::GetCurrentContext()).FromJust());
      vec[i] = (float)val->NumberValue(Nan::GetCurrentContext()).FromJust();
    }
    succeeded = true;
  }

  return succeeded;
}