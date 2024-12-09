void Network::loadConfig()
{
  SERIAL_DEBUG_LN(F("Loading config"));
  // Loads configuration from EEPROM into RAM
  EEPROM.begin(4095);
  EEPROM.get(0, cfg);
  EEPROM.end();

  if (!isValidHostname(cfg.hostname, sizeof(cfg.hostname)))
  {
    strncpy(cfg.hostname, DEFAULT_HOSTNAME, sizeof(cfg.hostname));
    setConfigChanged();
  }

#ifdef ENABLE_MQTT_SUPPORT
  // fall back to default settings if hostname is invalid
  char *mqtt_host = (char *)cfg.MQTTBroker;
  if (!isValidHostname(mqtt_host, sizeof(cfg.MQTTBroker)))
  {
    cfg.MQTTEnabled = MQTT_ENABLED;
    // Convert String data of global definitions into Char pointers for use in strncpy
    char *MQTT_BROKER = StringtoChar(MQTT_HOSTNAME);
    char *mqtt_user = StringtoChar(MQTT_USER);
    char *mqtt_pass = StringtoChar(MQTT_PASS);
    char *mqtt_topic = StringtoChar(MQTT_TOPIC);
    char *mqtt_topic_set = StringtoChar(MQTT_HOMEASSISTANT_TOPIC_SET);
    char *mqtt_device_name = StringtoChar(MQTT_DEVICE_NAME);

    if (MQTT_SECURE_ENABLED != 0)
    {
      cfg.MQTTPort = uint16_t(MQTT_PORT_SECURE);
    }
    else
    {
      cfg.MQTTPort = uint16_t(MQTT_PORT);
    }

    strncpy(mqtt_host, MQTT_BROKER, sizeof(cfg.MQTTBroker));
    strncpy(cfg.MQTTUser, mqtt_user, sizeof(cfg.MQTTUser));
    strncpy(cfg.MQTTPass, mqtt_pass, sizeof(cfg.MQTTPass));
    strncpy(cfg.MQTTTopic, mqtt_topic, sizeof(cfg.MQTTTopic));
    strncpy(cfg.MQTTSetTopic, mqtt_topic_set, sizeof(cfg.MQTTSetTopic));
    strncpy(cfg.MQTTDeviceName, mqtt_device_name, sizeof(cfg.MQTTDeviceName));
    setConfigChanged();
  }
#endif

  SERIAL_DEBUG_LNF("Loaded config: hostname %s, MQTT enabled %s, MQTT host %s, MQTT port %d, MQTT user %s, MQTT pass %s, MQTT topic %s, MQTT set topic %s, MQTT device name %s",
                   cfg.hostname,
                   (cfg.MQTTEnabled == MQTT_ENABLED) ? "true" : "false",
                   cfg.MQTTBroker,
                   cfg.MQTTPort,
                   cfg.MQTTUser,
                   cfg.MQTTPass,
                   cfg.MQTTTopic,
                   cfg.MQTTSetTopic,
                   cfg.MQTTDeviceName)
}