String ESP8266WiFiSTAClass::psk() const {
    struct station_config conf;
    wifi_station_get_config(&conf);
    return String(reinterpret_cast<char*>(conf.password));
}