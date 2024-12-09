void JavaObject::attach(jobject javaObject)
{
	ASSERT((javaObject && javaObject_ == NULL) || javaObject == NULL);
	UPDATE_STATS(0, -1);

	handle_.MakeWeak(this, DetachCallback);
	handle_.MarkIndependent();

	if (javaObject) {
		javaObject_ = javaObject;
	}
	newGlobalRef();
}