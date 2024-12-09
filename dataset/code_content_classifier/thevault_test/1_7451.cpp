void app_init(void){
    app.WiFiOnline = OFFLINE;
    app.WiFiMacAddress = "";
    app.WiFiLocalIP = "";
    app.aq.temp = 0;
    app.aq.press = 0;
    app.aq.hum = 0;
    app.aq.gas_res = 0;
    app.aq.alt = 0;

    app.displayState = 1;

    app.hapticState = 0;
    
    app.flags.val = 0;
}