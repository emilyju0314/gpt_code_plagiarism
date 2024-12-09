HMMModel::EmissionArray *NewEmission(
    const char *yname,
    const HMMModel *model,
    Status *status) {
  char error_message[1024];

  // Finds the yid for `yname`
  int yid;
  for (yid = 0; yid < model->ysize(); ++yid) {
    if (strcmp(yname, model->yname(yid)) == 0) break;
  }
  if (yid == model->ysize()) {
    sprintf(error_message, "Unable to file label '%s' from HMM model", yname);
    *status = Status::Corruption(error_message);
  } 

  HMMModel::EmissionArray *emission = NULL;
  if (status->ok()) {
    emission = new HMMModel::EmissionArray(1, 0);
    emission->set_yid_at(0, yid);
    emission->set_cost_at(0, 0.0f);
  }

  return emission;
}