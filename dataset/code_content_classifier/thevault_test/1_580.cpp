void ParticleObserver::publish(const String & eventName, const String & content, int flags) {
    if (m_name.empty()) {
        return;
      }
    int milisec = millis();
    //3600000 milliseconds in an hour
    int hours = milisec / 3600000;
    milisec = milisec - 3600000 * hours;
    //60000 milliseconds in a minute
    int min = milisec / 60000;
    milisec = milisec - 60000 * min;
    //1000 milliseconds in a second
    int sec = milisec / 1000;
    milisec = milisec - 1000 * sec;

    char dateBuff[30];
    snprintf(dateBuff, sizeof(dateBuff), "2020-07-01T%02d:%02d:%02d.%d00Z", hours, min, sec, milisec);
    //the wanted format: 2019-04-10T13:15:52.087Z

    fprintf(stderr,"event: %s\ndata: {\"data\":\"%s\",\"ttl\":\"60\",\"published_at\":\"%s\",\"coreid\":\"%s\"}\n",
            eventName.str().c_str(),
            content.str().c_str(),
            dateBuff,
            m_name.c_str()
    );
}