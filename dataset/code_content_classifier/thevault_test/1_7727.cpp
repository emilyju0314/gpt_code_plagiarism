void LocApiV02 ::
    injectPosition(double latitude, double longitude, float accuracy, bool onDemandCpi)
{
    Location location = {};

    location.flags |= LOCATION_HAS_LAT_LONG_BIT;
    location.latitude = latitude;
    location.longitude = longitude;

    location.flags |= LOCATION_HAS_ACCURACY_BIT;
    location.accuracy = accuracy;

    struct timespec time_info_current;
    if(clock_gettime(CLOCK_REALTIME,&time_info_current) == 0) //success
    {
        location.timestamp = (time_info_current.tv_sec)*1e3 +
            (time_info_current.tv_nsec)/1e6;
    }

    injectPosition(location, onDemandCpi);
}