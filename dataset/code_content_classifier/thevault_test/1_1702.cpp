void model_profiler_process_action(void)
{
  // Set input tensor to zero.
  TfLiteTensor* input_tensor = interpreter->input(0);
  memset(input_tensor->data.int8, 0, input_tensor->bytes);

  // Run the model and make sure it succeeds.
  if (interpreter->Invoke() != kTfLiteOk) {
    printf("Model invokation failed !");
    return;
  }

  printf("--------------------------------------------\n");
  printf("--------------------------------------------\n");
  printf("Profiling summary:\n");
  sli_print_time("Total execution time:   ", profiler.total_cpu_cycles());
  sli_print_ui32("Total CPU cycle count:  ", profiler.total_cpu_cycles(), "\n");
#if defined(SL_CATALOG_MVP_PRESENT)
  auto total_mvp_instructions = profiler.total_mvp_instructions();
  if (total_mvp_instructions > 0) {
    sli_print_ui32("Total MVP instructions: ", total_mvp_instructions, "\n");
    sli_print_ui32("Total MVP stall cycles: ", profiler.total_mvp_stall_cycles(), "\n");
  }
#endif
  printf("--------------------------------------------\n");
  printf("--------------------------------------------\n");

  printf("Model profiling done.\n");
#if defined(SL_CATALOG_MVP_PRESENT)
  sli_mvp_deinit();
#endif
}