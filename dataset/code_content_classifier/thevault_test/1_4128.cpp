wl_status_t ESP8266WiFiSTAClass::begin(const char* ssid, const char *passphrase, int32_t channel, const uint8_t* bssid, bool connect) {

    if(!WiFi.enableSTA(true)) {
        // enable STA failed
        return WL_CONNECT_FAILED;
    }

    if(!ssid || *ssid == 0x00 || strlen(ssid) > 31) {
        // fail SSID too long or missing!
        return WL_CONNECT_FAILED;
    }

    if(passphrase && strlen(passphrase) > 64) {
        // fail passphrase too long!
        return WL_CONNECT_FAILED;
    }

    struct station_config conf;
    strcpy(reinterpret_cast<char*>(conf.ssid), ssid);

    if(passphrase) {
        if (strlen(passphrase) == 64) // it's not a passphrase, is the PSK
            memcpy(reinterpret_cast<char*>(conf.password), passphrase, 64);
        else
            strcpy(reinterpret_cast<char*>(conf.password), passphrase);
    } else {
        *conf.password = 0;
    }

    if(bssid) {
        conf.bssid_set = 1;
        memcpy((void *) &conf.bssid[0], (void *) bssid, 6);
    } else {
        conf.bssid_set = 0;
    }

    struct station_config current_conf;
    wifi_station_get_config(&current_conf);
    if(sta_config_equal(current_conf, conf)) {
        DEBUGV("sta config unchanged");
    }
    else {
        ETS_UART_INTR_DISABLE();

        if(WiFi._persistent) {
            // workaround for #1997: make sure the value of ap_number is updated and written to flash
            // to be removed after SDK update
            wifi_station_ap_number_set(2);
            wifi_station_ap_number_set(1);

            wifi_station_set_config(&conf);
        } else {
            wifi_station_set_config_current(&conf);
        }

        ETS_UART_INTR_ENABLE();
    }

    ETS_UART_INTR_DISABLE();
    if(connect) {
        wifi_station_connect();
    }
    ETS_UART_INTR_ENABLE();

    if(channel > 0 && channel <= 13) {
        wifi_set_channel(channel);
    }

    if(!_useStaticIp) {
        wifi_station_dhcpc_start();
    }

    return status();
}