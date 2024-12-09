std::string GetIntentExtra(struct android_app* app, const char* key)
{
    std::string value;
    JavaVM*     jni_vm       = nullptr;
    jobject     jni_activity = nullptr;
    JNIEnv*     env          = nullptr;

    if ((app != nullptr) && (app->activity != nullptr))
    {
        jni_vm       = app->activity->vm;
        jni_activity = app->activity->clazz;
    }

    if ((jni_vm != nullptr) && (jni_activity != 0) && (jni_vm->AttachCurrentThread(&env, nullptr) == JNI_OK))
    {
        jclass    activity_class = env->GetObjectClass(jni_activity);
        jmethodID get_intent     = env->GetMethodID(activity_class, "getIntent", "()Landroid/content/Intent;");
        jobject   intent         = env->CallObjectMethod(jni_activity, get_intent);

        if (intent)
        {
            jclass    intent_class = env->GetObjectClass(intent);
            jmethodID get_string_extra =
                env->GetMethodID(intent_class, "getStringExtra", "(Ljava/lang/String;)Ljava/lang/String;");

            jvalue extra_key;
            extra_key.l = env->NewStringUTF(key);

            jstring extra = static_cast<jstring>(env->CallObjectMethodA(intent, get_string_extra, &extra_key));

            if (extra)
            {
                const char* utf_chars = env->GetStringUTFChars(extra, nullptr);

                value = utf_chars;

                env->ReleaseStringUTFChars(extra, utf_chars);
                env->DeleteLocalRef(extra);
            }

            env->DeleteLocalRef(extra_key.l);
            env->DeleteLocalRef(intent);
        }

        jni_vm->DetachCurrentThread();
    }

    return value;
}