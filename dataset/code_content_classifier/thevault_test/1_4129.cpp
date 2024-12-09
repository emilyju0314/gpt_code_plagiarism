bool ESP8266WiFiSTAClass::hostname(char* aHostname) {
    if(strlen(aHostname) > 32) {
        return false;
    }
    return wifi_station_set_hostname(aHostname);
}