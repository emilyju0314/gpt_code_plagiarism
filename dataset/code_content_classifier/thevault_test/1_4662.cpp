int
VirtualMachine::InstanceCountsHandler::Execute(JNIEnv *jni) 
{
    jint refTypesCount = m_cmdParser->command.ReadInt();
    // Illegal argument
    if(refTypesCount < 0) {
        AgentException e(JDWP_ERROR_ILLEGAL_ARGUMENT);
		JDWP_SET_EXCEPTION(e);
        return JDWP_ERROR_ILLEGAL_ARGUMENT;
    }

    m_cmdParser->reply.WriteInt(refTypesCount);
    JDWP_TRACE(LOG_RELEASE, (LOG_DATA_FL, "InstanceCounts: return the number of counts that follow:%d", refTypesCount));

    // Number of reference types equals zero
    if(0 == refTypesCount) {
        return JDWP_ERROR_NONE;
    }

    jclass jvmClass;
    jvmtiError err;
    // Tag is used to mark object which is reported in FollowReferences
    jlong tag_value = 0xffff;
    jlong tags[1] = {tag_value};
    jint reachableInstancesNum = 0;

    // Initial callbacks for FollowReferences
    // These callbacks will tag the expected objects which are reported in FollowReferences
    jvmtiHeapCallbacks hcbs;
    memset(&hcbs, 0, sizeof(hcbs));
    hcbs.heap_iteration_callback = NULL;
    hcbs.heap_reference_callback = &HeapReferenceCallback;
    hcbs.primitive_field_callback = NULL;
    hcbs.array_primitive_value_callback = NULL;
    hcbs.string_primitive_value_callback = NULL;

    for(int i = 0; i < refTypesCount;i++) {
         jvmClass = m_cmdParser->command.ReadReferenceTypeID(jni);
        // Can be: InternalErrorException, OutOfMemoryException,
        // JDWP_ERROR_INVALID_CLASS, JDWP_ERROR_INVALID_OBJECT
#ifndef NDEBUG
        if (JDWP_TRACE_ENABLED(LOG_KIND_DATA)) {
            char* signature = 0;
            JVMTI_TRACE(LOG_DEBUG, err, GetJvmtiEnv()->GetClassSignature(jvmClass, &signature, 0));
            JvmtiAutoFree afcs(signature);
            JDWP_TRACE(LOG_RELEASE, (LOG_DATA_FL, "InstanceCounts: received: refTypeID=%p, classSignature=%s", jvmClass, JDWP_CHECK_NULL(signature)));
        }
#endif
        
        //It initiates a traversal over the objects that are directly and indirectly reachable from the heap roots.
        JVMTI_TRACE(LOG_DEBUG, err, GetJvmtiEnv()->FollowReferences(0, jvmClass,  NULL,
             &hcbs, &tag_value));
        if (err != JVMTI_ERROR_NONE) {
            // Can be: JVMTI_ERROR_MUST_POSSESS_CAPABILITY, JVMTI_ERROR_INVALID_CLASS
            // JVMTI_ERROR_INVALID_OBJECT, JVMTI_ERROR_NULL_POINTER 
            AgentException e(err);
		    JDWP_SET_EXCEPTION(e);
            return err;
        }

        jobject *pResultObjects = 0;

        // Return the instances that have been marked expected tag_value tag.
        JVMTI_TRACE(LOG_DEBUG, err, GetJvmtiEnv()->GetObjectsWithTags(1, tags, &reachableInstancesNum,
            &pResultObjects, NULL));
		JvmtiAutoFree afResultObjects(pResultObjects);
  
        if (err != JVMTI_ERROR_NONE) {
            // Can be: JVMTI_ERROR_MUST_POSSESS_CAPABILITY, JVMTI_ERROR_ILLEGAL_ARGUMENT 
            // JVMTI_ERROR_ILLEGAL_ARGUMENT, JVMTI_ERROR_NULL_POINTER  
            AgentException e(err);
		    JDWP_SET_EXCEPTION(e);
            return err;
        }

        m_cmdParser->reply.WriteLong(reachableInstancesNum);
        JDWP_TRACE(LOG_RELEASE, (LOG_DATA_FL, "InstanceCounts: return the number of instances for the corresponding  reference type:%d",
                        reachableInstancesNum));
	   //Set objects tags back to 0 
       for(int i = 0; i < reachableInstancesNum; i++) {
          JVMTI_TRACE(LOG_DEBUG, err, GetJvmtiEnv()->SetTag(pResultObjects[i], 0));
          jni->DeleteLocalRef(pResultObjects[i]);
          if (err != JVMTI_ERROR_NONE) {
              AgentException e(err);
	          JDWP_SET_EXCEPTION(e);
              return err;
          }
        }
        // tag_value is changed to indicate instances of other types 
        tags[0] = ++tag_value;
    }

    return JDWP_ERROR_NONE;
}