size_t make_lambda(const std::string& pylambda_str) {
  DASSERT_TRUE(evaluation_functions.init_lambda != NULL);
  
  size_t lambda_id = evaluation_functions.init_lambda(pylambda_str);
  python::check_for_python_exception();
  
  logstream(LOG_DEBUG) << "Created lambda id=" << lambda_id << std::endl;  

  return lambda_id;
}