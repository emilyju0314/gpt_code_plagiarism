static ds_status deserializeScore(ds_device *device, const uint8_t *serializedScore,
                                  unsigned int serializedScoreSize) {
  // check that serializedScoreSize == sizeof(TessDeviceScore);
  device->score = new TessDeviceScore;
  memcpy(device->score, serializedScore, serializedScoreSize);
  return DS_SUCCESS;
}