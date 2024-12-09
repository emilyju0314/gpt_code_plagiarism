void proxy_aggregator::finalize(iglobal_context& context){

  // forward call to org.graphlab.Aggregator#finalize
  JNIEnv *env = core::get_jni_env();
  env->CallVoidMethod (obj(), java_finalize, &context);
  handle_exception(env);

}