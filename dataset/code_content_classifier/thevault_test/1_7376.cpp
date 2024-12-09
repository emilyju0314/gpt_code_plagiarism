void loop() {
  TF_LITE_MICRO_EXECUTION_TIME_BEGIN

  TF_LITE_MICRO_EXECUTION_TIME_SNIPPET_START(error_reporter)
  // Get image from provider.
  if (kTfLiteOk != GetImage(error_reporter, kNumCols, kNumRows, kNumChannels,
                            input->data.int8)) {
    TF_LITE_REPORT_ERROR(error_reporter, "Image capture failed.");
  }
  TF_LITE_MICRO_EXECUTION_TIME_SNIPPET_END(error_reporter, "GetImage")

  TF_LITE_MICRO_EXECUTION_TIME_SNIPPET_START(error_reporter)
  // Run the model on this input and make sure it succeeds.
  if (kTfLiteOk != interpreter->Invoke()) {
    TF_LITE_REPORT_ERROR(error_reporter, "Invoke failed.");
  }
  TF_LITE_MICRO_EXECUTION_TIME_SNIPPET_END(error_reporter, "Invoke")

  TfLiteTensor* output = interpreter->output(0);

  // Process the inference results.
  int8_t person_score = output->data.uint8[kPersonIndex];
  int8_t no_person_score = output->data.uint8[kNotAPersonIndex];
  //Turning on the Pi if person is detected:
  //Pin for turning on the RPi4 using Pin 15 from the Pico
const uint LED_PIN = 15;
gpio_init(LED_PIN);
gpio_set_dir(LED_PIN, GPIO_OUT);

  if (person_score > 75){
    gpio_put(LED_PIN,1);
    sleep_ms(250);
  }else{
    gpio_put(LED_PIN,0);
    }
  RespondToDetection(error_reporter, person_score, no_person_score);
}