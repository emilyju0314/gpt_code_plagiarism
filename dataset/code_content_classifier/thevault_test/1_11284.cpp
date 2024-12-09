explicit inline flex_date_time(int64_t posix_timestamp, 
                                 int32_t tz_15min_offset = EMPTY_TIMEZONE,
                                 int32_t microsecond = 0) { 
    set_posix_timestamp(posix_timestamp);
    set_time_zone_offset(tz_15min_offset);
    set_microsecond(microsecond);
  }