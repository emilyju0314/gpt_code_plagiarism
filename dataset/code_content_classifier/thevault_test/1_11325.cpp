void proxy_updater::operator+=(const proxy_updater& other) const {

  // forward call to org.graphlab.Updater#add
  JNIEnv *env = core::get_jni_env();
  env->CallVoidMethod (obj(), java_add, other.obj());
  handle_exception(env);

}