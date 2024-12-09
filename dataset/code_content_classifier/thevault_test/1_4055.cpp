static void initMLUGenVector() {
  num_mlus = device_count();
  mlu_gens_init_flag.resize(num_mlus);
  default_gens_mlu.resize(num_mlus);
  is_floating_device = Global::instance().isUsingFloatingDevice();
}