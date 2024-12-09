void proxy_aggregator::operator+=(const proxy_aggregator& other) {
  
  // forward call to org.graphlab.Aggregator#add
  JNIEnv *env = core::get_jni_env();
  env->CallVoidMethod (obj(), java_add, other.obj());
  handle_exception(env);

}