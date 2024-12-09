static ds_status serializeScore(ds_device *device, uint8_t **serializedScore,
                                unsigned int *serializedScoreSize) {
  *serializedScoreSize = sizeof(TessDeviceScore);
  *serializedScore = new uint8_t[*serializedScoreSize];
  memcpy(*serializedScore, device->score, *serializedScoreSize);
  return DS_SUCCESS;
}