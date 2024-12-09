jobject JavaObject::getJavaObject()
{
	if (useGlobalRefs) {
		ASSERT(javaObject_ != NULL);

		// We must always return a valid Java proxy reference.
		// Otherwise we risk crashing in the calling code.
		// If we are "detached" we will re-attach whenever the Java
		// proxy is requested.
		if (isDetached()) {
			attach(NULL);
		}

		return javaObject_;
	} else {
		if (isWeakRef_) {
			UPDATE_STATS(0, -1);
			jobject javaObject = ReferenceTable::clearWeakReference(refTableKey_);
			if (javaObject == NULL) {
				LOGE(TAG, "Java object reference has been invalidated.");
			}
			isWeakRef_ = false;
			handle_.MakeWeak(this, DetachCallback);
			return javaObject;
		}
		return ReferenceTable::getReference(refTableKey_);
	}
}