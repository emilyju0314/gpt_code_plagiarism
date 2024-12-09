void proxy_updater::operator()(icontext_type& context){
  
  jobject vertex = context.const_vertex_data().obj();
  if (NULL == vertex) return; // BUG?
  
  // forward call to org.graphlab.Updater#update
  JNIEnv *env = core::get_jni_env();
  env->CallVoidMethod (obj(), java_update,
                       &context,
                       vertex);
  handle_exception(env);

}