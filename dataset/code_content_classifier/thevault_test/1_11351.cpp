void proxy_aggregator::operator()(icontext_type& context){
  
  // forward call to org.graphlab.Aggregator#exec
  JNIEnv *env = core::get_jni_env();
  env->CallVoidMethod (obj(), java_exec,
                       &context,
                       context.vertex_data().obj());
  handle_exception(env);

}