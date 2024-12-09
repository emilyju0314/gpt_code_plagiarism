String ESP8266WiFiSTAClass::SSID() const {
    struct station_config conf;
    wifi_station_get_config(&conf);
    return String(reinterpret_cast<char*>(conf.ssid));
}