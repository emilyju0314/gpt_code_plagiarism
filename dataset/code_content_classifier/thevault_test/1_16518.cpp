static v8::Handle<v8::Value> npObjectInvokeImpl(const v8::Arguments& args, InvokeFunctionType functionId)
{
    NPObject* npObject;

    // These three types are subtypes of HTMLPlugInElement.
    if (V8HTMLAppletElement::HasInstance(args.Holder()) || V8HTMLEmbedElement::HasInstance(args.Holder())
        || V8HTMLObjectElement::HasInstance(args.Holder())) {
        // The holder object is a subtype of HTMLPlugInElement.
        HTMLPlugInElement* element;
        if (V8HTMLAppletElement::HasInstance(args.Holder()))
            element = V8HTMLAppletElement::toNative(args.Holder());
        else if (V8HTMLEmbedElement::HasInstance(args.Holder()))
            element = V8HTMLEmbedElement::toNative(args.Holder());
        else
            element = V8HTMLObjectElement::toNative(args.Holder());
        ScriptInstance scriptInstance = element->getInstance();
        if (scriptInstance)
            npObject = v8ObjectToNPObject(scriptInstance->instance());
        else
            npObject = 0;
    } else {
        // The holder object is not a subtype of HTMLPlugInElement, it must be an NPObject which has three
        // internal fields.
        if (args.Holder()->InternalFieldCount() != npObjectInternalFieldCount)
          return throwError("NPMethod called on non-NPObject", V8Proxy::ReferenceError);

        npObject = v8ObjectToNPObject(args.Holder());
    }

    // Verify that our wrapper wasn't using a NPObject which has already been deleted.
    if (!npObject || !_NPN_IsAlive(npObject))
        return throwError("NPObject deleted", V8Proxy::ReferenceError);

    // Wrap up parameters.
    int numArgs = args.Length();
    OwnArrayPtr<NPVariant> npArgs = adoptArrayPtr(new NPVariant[numArgs]);

    for (int i = 0; i < numArgs; i++)
        convertV8ObjectToNPVariant(args[i], npObject, &npArgs[i]);

    NPVariant result;
    VOID_TO_NPVARIANT(result);

    bool retval = true;
    switch (functionId) {
    case InvokeMethod:
        if (npObject->_class->invoke) {
            v8::Handle<v8::String> functionName(v8::String::Cast(*args.Data()));
            NPIdentifier identifier = getStringIdentifier(functionName);
            retval = npObject->_class->invoke(npObject, identifier, npArgs.get(), numArgs, &result);
        }
        break;
    case InvokeConstruct:
        if (npObject->_class->construct)
            retval = npObject->_class->construct(npObject, npArgs.get(), numArgs, &result);
        break;
    case InvokeDefault:
        if (npObject->_class->invokeDefault)
            retval = npObject->_class->invokeDefault(npObject, npArgs.get(), numArgs, &result);
        break;
    default:
        break;
    }

    if (!retval)
        throwError("Error calling method on NPObject.", V8Proxy::GeneralError);

    for (int i = 0; i < numArgs; i++)
        _NPN_ReleaseVariantValue(&npArgs[i]);

    // Unwrap return values.
    v8::Handle<v8::Value> returnValue = convertNPVariantToV8Object(&result, npObject);
    _NPN_ReleaseVariantValue(&result);

    return returnValue;
}