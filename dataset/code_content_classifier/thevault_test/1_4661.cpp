int
ObjectReference::ReferringObjectsHandler::Execute(JNIEnv *jni) 
{
    // Get objectID
    jobject jvmObject = m_cmdParser->command.ReadObjectID(jni);
    // Can be: InternalErrorException, OutOfMemoryException, JDWP_ERROR_INVALID_OBJECT
    JDWP_CHECK_NOT_NULL(jvmObject);

    // Get maximum number of referring objects to return.
    int maxReferrers = m_cmdParser->command.ReadInt();
    if(maxReferrers < 0) {
        AgentException e(JDWP_ERROR_ILLEGAL_ARGUMENT);
		JDWP_SET_EXCEPTION(e);
        return JDWP_ERROR_ILLEGAL_ARGUMENT;
    }

    // Define tag for referree object
    jlong targetObjTag = 0xefff;
    // Set tag for target object
     jvmtiError err;
    JVMTI_TRACE(LOG_DEBUG, err, GetJvmtiEnv()->SetTag(jvmObject, targetObjTag));
    if (err != JVMTI_ERROR_NONE) {
        // Can be: JVMTI_ERROR_MUST_POSSESS_CAPABILITY,  JVMTI_ERROR_INVALID_OBJECT
        AgentException e(err);
		JDWP_SET_EXCEPTION(e);
        return err;
    }
    
    // Define tag for referrer object
    jlong referrerObjTag = 0xdfff;
    jlong tags[2] = {targetObjTag, referrerObjTag};

    // Initial callbacks for jvmtiHeapCallbacks
    jvmtiHeapCallbacks hcbs;
    memset(&hcbs, 0, sizeof(hcbs));
    hcbs.heap_iteration_callback = NULL;
    hcbs.heap_reference_callback = &HeapReferenceCallback_ReferringObject;
    hcbs.primitive_field_callback = NULL;
    hcbs.array_primitive_value_callback = NULL;
    hcbs.string_primitive_value_callback = NULL;

    //It initiates a traversal over the objects that are directly and indirectly reachable from the heap roots.
    JVMTI_TRACE(LOG_DEBUG, err, GetJvmtiEnv()->FollowReferences(0, NULL,  NULL,
         &hcbs, tags));
    if (err != JVMTI_ERROR_NONE) {
        // Can be: JVMTI_ERROR_MUST_POSSESS_CAPABILITY, JVMTI_ERROR_INVALID_CLASS
        // JVMTI_ERROR_INVALID_OBJECT, JVMTI_ERROR_NULL_POINTER 
        AgentException e(err);
		JDWP_SET_EXCEPTION(e);
        return err;
    }

    const jlong referrerTags[1] = {referrerObjTag};
    jint referringObjectsNum = 0;
    jobject * pResultObjects = 0;
    // Return the instances that have been marked expectd tag.
    JVMTI_TRACE(LOG_DEBUG, err, GetJvmtiEnv()->GetObjectsWithTags(1, referrerTags, &referringObjectsNum,
           &pResultObjects, NULL));
    JvmtiAutoFree afResultObjects(pResultObjects);

    if (err != JVMTI_ERROR_NONE) {
        // Can be: JVMTI_ERROR_MUST_POSSESS_CAPABILITY, JVMTI_ERROR_ILLEGAL_ARGUMENT 
        // JVMTI_ERROR_ILLEGAL_ARGUMENT, JVMTI_ERROR_NULL_POINTER  
        AgentException e(err);
		JDWP_SET_EXCEPTION(e);
        return err;
    }

    jint returnReferringObjectsNum;
    //If maxReferrers is zero, all instances are returned.
    if(0 == maxReferrers) {
        returnReferringObjectsNum = referringObjectsNum;
    }
    else if(maxReferrers < referringObjectsNum) {
        returnReferringObjectsNum = maxReferrers;
    }
    else {
        returnReferringObjectsNum = referringObjectsNum;
    }

    // Compose reply package
    m_cmdParser->reply.WriteInt(returnReferringObjectsNum);
    JDWP_TRACE(LOG_RELEASE, (LOG_DATA_FL, "ReferringObject: return objects number: %d", returnReferringObjectsNum));

    for(int i = 0; i < returnReferringObjectsNum; i++) {
        m_cmdParser->reply.WriteTaggedObjectID(jni, pResultObjects[i]);
        JVMTI_TRACE(LOG_DEBUG, err, GetJvmtiEnv()->SetTag(pResultObjects[i], 0));
        jni->DeleteLocalRef(pResultObjects[i]);
        if (err != JVMTI_ERROR_NONE) {
            AgentException e(err);
            JDWP_SET_EXCEPTION(e);
            return err;
        }
    }
    JVMTI_TRACE(LOG_DEBUG, err, GetJvmtiEnv()->SetTag(jvmObject, 0));
    if (err != JVMTI_ERROR_NONE) {
      AgentException e(err);
      JDWP_SET_EXCEPTION(e);
      return err;
    }
    JDWP_TRACE(LOG_RELEASE, (LOG_DATA_FL, "ReferringObject: tagged-objectID returned."));

    return JDWP_ERROR_NONE;
}