bool camera_reconfigure()
{
  int res;
  sensor_t *s = esp_camera_sensor_get();

  res = s->set_framesize(s, cfg.getFrameSize());
  if (res != 0) {
    Serial.printf("Unable to set 'frame size': return code %d\n", res);
    return false;
  }

  res = s->set_quality(s, cfg.getQuality());
  if (res != 0) {
    Serial.printf("Unable to set 'quality': return code %d\n", res);
    return false;
  }

  res = s->set_contrast(s, cfg.getContrast());
  if (res != 0) {
    Serial.printf("Unable to set 'contrast': return code %d\n", res);
    return false;
  }

  res = s->set_brightness(s, cfg.getBrightness());
  if (res != 0) {
    Serial.printf("Unable to set 'brightness': return code %d\n", res);
    return false;
  }

  res = s->set_saturation(s, cfg.getSaturation());
  if (res != 0) {
    Serial.printf("Unable to set 'saturation': return code %d\n", res);
    return false;
  }

  res = s->set_colorbar(s, cfg.getColorBar());
  if (res != 0) {
    Serial.printf("Unable to set 'colorbar': return code %d\n", res);
    return false;
  }

  res = s->set_hmirror(s, cfg.getHMirror());
  if (res != 0) {
    Serial.printf("Unable to set 'hmirror': return code %d\n", res);
    return false;
  }

  res = s->set_vflip(s, cfg.getVFlip());
  if (res != 0) {
    Serial.printf("Unable to set 'vflip': return code %d\n", res);
    return false;
  }

  res = s->set_whitebal(s, cfg.getAwb());
  if (res != 0) {
    Serial.printf("Unable to set 'whitebal': return code %d\n", res);
    return false;
  }

  res = s->set_awb_gain(s, cfg.getAwbGain());
  if (res != 0) {
    Serial.printf("Unable to set 'awb_gain': return code %d\n", res);
    return false;
  }

  res = s->set_wb_mode(s, cfg.getWhiteBalanceMode());
  if (res != 0) {
    Serial.printf("Unable to set 'wb_mode': return code %d\n", res);
    return false;
  }

  res = s->set_gain_ctrl(s, cfg.getAgc());
  if (res != 0) {
    Serial.printf("Unable to set 'gain_ctrl': return code %d\n", res);
    return false;
  }

  res = s->set_agc_gain(s, cfg.getAgcGain());
  if (res != 0) {
    Serial.printf("Unable to set 'agc_gain': return code %d\n", res);
    return false;
  }

  res = s->set_gainceiling(s, cfg.getGainCeiling());
  if (res != 0) {
    Serial.printf("Unable to set 'gainceiling': return code %d\n", res);
    return false;
  }

  res = s->set_exposure_ctrl(s, cfg.getAec());
  if (res != 0) {
    Serial.printf("Unable to set 'exposure_ctrl': return code %d\n", res);
    return false;
  }

  res = s->set_aec_value(s, cfg.getExposureValue());
  if (res != 0) {
    Serial.printf("Unable to set 'aec_value': return code %d\n", res);
    return false;
  }

  res = s->set_aec2(s, cfg.getAec2());
  if (res != 0) {
    Serial.printf("Unable to set 'aec2': return code %d\n", res);
    return false;
  }

  res = s->set_ae_level(s, cfg.getAeLevel());
  if (res != 0) {
    Serial.printf("Unable to set 'ae_level': return code %d\n", res);
    return false;
  }

  res = s->set_dcw(s, cfg.getDcw());
  if (res != 0) {
    Serial.printf("Unable to set 'dcw': return code %d\n", res);
    return false;
  }

  res = s->set_bpc(s, cfg.getBlackPixelCancellation());
  if (res != 0) {
    Serial.printf("Unable to set 'bpc': return code %d\n", res);
    return false;
  }

  res = s->set_wpc(s, cfg.getWhitePixelCancellation());
  if (res != 0) {
    Serial.printf("Unable to set 'wpc': return code %d\n", res);
    return false;
  }

  res = s->set_raw_gma(s, cfg.getRawGamma());
  if (res != 0) {
    Serial.printf("Unable to set 'raw_gma': return code %d\n", res);
    return false;
  }

  res = s->set_lenc(s, cfg.getLensCorrection());
  if (res != 0) {
    Serial.printf("Unable to set 'lenc': return code %d\n", res);
    return false;
  }

  res = s->set_special_effect(s, cfg.getSpecialEffect());
  if (res != 0) {
    Serial.printf("Unable to set 'special_effect': return code %d\n", res);
    return false;
  }

  return true;
}