static JSValueRef GetArrayPrototype(JSContextRef jsContext, JSValueRef* exception) 
	{
		JSObjectRef globalObject = JSContextGetGlobalObject(jsContext);
		JSStringRef fnPropName = JSStringCreateWithUTF8CString("Array");
		JSValueRef fnCtorValue = JSObjectGetProperty(jsContext, globalObject,
			fnPropName, exception);
		JSStringRelease(fnPropName);
		if (!fnCtorValue) 
		{
			return JSValueMakeUndefined(jsContext);
		}

		JSObjectRef fnCtorObject = JSValueToObject(jsContext, fnCtorValue, exception);
		if (!fnCtorObject)
		{
			return JSValueMakeUndefined(jsContext);
		}

		JSStringRef protoPropName = JSStringCreateWithUTF8CString("prototype");
		JSValueRef fnPrototype = JSObjectGetProperty(jsContext, fnCtorObject,
			protoPropName, exception);
		JSStringRelease(protoPropName);
		if (!fnPrototype) 
		{
			return JSValueMakeUndefined(jsContext);
		}

		return fnPrototype;
	}