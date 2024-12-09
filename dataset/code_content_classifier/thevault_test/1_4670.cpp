int
ReferenceType::NestedTypesHandler::Execute(JNIEnv *jni)
{
    jclass jvmClass = m_cmdParser->command.ReadReferenceTypeID(jni);
    // Can be: InternalErrorException, OutOfMemoryException,
    // JDWP_ERROR_INVALID_CLASS, JDWP_ERROR_INVALID_OBJECT
    JDWP_CHECK_NOT_NULL(jvmClass);

#ifndef NDEBUG
    if (JDWP_TRACE_ENABLED(LOG_KIND_DATA)) {
        jvmtiError err;
        char* signature = 0;
        JVMTI_TRACE(LOG_DEBUG, err, GetJvmtiEnv()->GetClassSignature(jvmClass, &signature, 0));
        JvmtiAutoFree afcs(signature);
        JDWP_TRACE(LOG_RELEASE, (LOG_DATA_FL, "NestedTypes: received: refTypeID=%p, classSignature=%s", jvmClass, JDWP_CHECK_NULL(signature)));
    }
#endif
    char* jvmClassSignature = 0;

    jvmtiEnv* jvmti = AgentBase::GetJvmtiEnv();

    jvmtiError err;
    JVMTI_TRACE(LOG_DEBUG, err, jvmti->GetClassSignature(jvmClass, &jvmClassSignature, 0));

    if (err != JVMTI_ERROR_NONE) {
        // Can be: JVMTI_ERROR_INVALID_CLASS
        AgentException e(err);
		JDWP_SET_EXCEPTION(e);
        return err;
    }
    JvmtiAutoFree autoFreeSignature(jvmClassSignature);
    size_t jvmClassSignatureLength = strlen(jvmClassSignature);

    jint allClassesCount = 0;
    jclass* allClasses = 0;

    AgentBase::GetJniEnv()->PushLocalFrame(100);

    JVMTI_TRACE(LOG_DEBUG, err, jvmti->GetLoadedClasses(&allClassesCount, &allClasses));

    if (err != JVMTI_ERROR_NONE) {
        // Can be: JVMTI_ERROR_NULL_POINTER
        AgentException e(err);
        JDWP_SET_EXCEPTION(e);
        return err;
    }
    JvmtiAutoFree autoFreeAllClasses(allClasses);

    /* Since JVMTI doesn't support getting nested classes so here 
     * following algorithm is used:
     * searching among allClasses for classes nested directly in given jvmClass.
     * The criterion is:
     * <nested_class_signature> = 
     * <jvmClassSignature> + '$' + <nested_class_name>
     * but not
     * <jvmClassSignature> + '$' + <nested_class_name> + '$' + ...
     * since according to JDWP specificstion 
     * "Types further nested within those types are not included",
     * and not
     * <jvmClassSignature> + '$' + <digit>
     * since it is anonymous class and reference JDWP implementation
     * doesn't return anonymous classes.
     * But there is one nuance: given algorithm does not take into 
     * account that class name of not-nested class can contain '$' symbol,
     * that is not forbidden by the Java Language Specification.
     * In this case such class with name containing '$' symbol may be returned 
     * by ReferenceType.NestedTypes command too, although this class is not
     * nested class.
    */
    const char nestedClassSign = '$';
    jint nestedTypesCount = 0;
    for (int allClassesIndex = 0; allClassesIndex < allClassesCount; allClassesIndex++) {
        jclass klass = allClasses[allClassesIndex];
        char* klassSignature = 0;

        JVMTI_TRACE(LOG_DEBUG, err, jvmti->GetClassSignature(klass, &klassSignature, 0));

        if (err != JVMTI_ERROR_NONE) {
            // Can be: JVMTI_ERROR_INVALID_CLASS
            AgentException e(err);
    	    JDWP_SET_EXCEPTION(e);
            return err;
        }
        JvmtiAutoFree autoFreeKlassSignature(klassSignature);

        size_t klassSignatureLength = strlen(klassSignature);
        if ( jvmClassSignatureLength+2 > klassSignatureLength ) {
            // <nested_class_signature> = 
            // <jvmClassSignature> + '$' + <at_least_1_symbol> 
            continue;
        }

        if ( strncmp(klassSignature, jvmClassSignature, jvmClassSignatureLength-1)
                != 0 ) {
            continue;
        }
	// note:
        char* firstCharPtr = strchr((klassSignature + jvmClassSignatureLength - 1), nestedClassSign);
        if ( firstCharPtr == NULL ) {
            // klass is not nested in jvmClass
            continue;
        }
        char* lastCharPtr = strrchr(klassSignature, nestedClassSign);
        if ( firstCharPtr != lastCharPtr ) {
            // klass is nested in jvmClass but NOT directly
            continue;
        }
        firstCharPtr++;
        if ( isdigit(*firstCharPtr) ) {
            // it is anonymous class  - ignore it
            continue;
        }
        // klass is directly nested in jvmClass - it is desired nested class
        allClasses[nestedTypesCount] = klass;
        nestedTypesCount++;
    }

    // form reply data for all found out classes nested directly in given jvmClass
    m_cmdParser->reply.WriteInt(nestedTypesCount);
    JDWP_TRACE(LOG_RELEASE, (LOG_DATA_FL, "NestedTypes: nestedTypes=%d", nestedTypesCount));
    for (int nestedClassesIndex = 0; nestedClassesIndex < nestedTypesCount; nestedClassesIndex++) {
        jclass nestedClass = allClasses[nestedClassesIndex];

        jdwpTypeTag refTypeTag = JDWP_TYPE_TAG_CLASS;
        if (GetClassManager().IsInterfaceType(nestedClass) == JNI_TRUE ) {
            // Can be: JVMTI_ERROR_INVALID_CLASS, JVMTI_ERROR_NULL_POINTER
            refTypeTag = JDWP_TYPE_TAG_INTERFACE;
        }
        m_cmdParser->reply.WriteByte((jbyte)refTypeTag);
        m_cmdParser->reply.WriteReferenceTypeID(jni, nestedClass);
        // can be: OutOfMemoryException, InternalErrorException,
#ifndef NDEBUG
        if (JDWP_TRACE_ENABLED(LOG_KIND_DATA)) {
            jvmtiError err;
            char* signature = 0;
            JVMTI_TRACE(LOG_DEBUG, err, jvmti->GetClassSignature(nestedClass, &signature, 0));
            JvmtiAutoFree afcs(signature);
            JDWP_TRACE(LOG_RELEASE, (LOG_DATA_FL, "NestedTypes: send: nestedClass#%d, typeTag=%d, nestedClassID=%p, signature=%s",
                            nestedClassesIndex, refTypeTag, nestedClass, JDWP_CHECK_NULL(signature)));
        }
#endif
    }

    AgentBase::GetJniEnv()->PopLocalFrame(NULL);

    return JDWP_ERROR_NONE;
}