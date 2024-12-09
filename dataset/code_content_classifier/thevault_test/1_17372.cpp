static void DetachCallback(v8::Persistent<v8::Value> value, void *data)
{
	JavaObject *javaObject = static_cast<JavaObject*>(data);
	javaObject->detach();
}