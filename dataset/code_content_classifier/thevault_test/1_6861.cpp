const char*
TrafficSource::property() {
  static char text[PROPERTY_STRING_LENGTH];
  char timelist_string[200];
  char * property_list;
  int total_written = 0;

  property_list = text;
  total_written = sprintf(text,
          "{\"Traffic Source %s %d\" title title \"TrafficSource %d\"} ",
          name(), number_, number_);

  property_list = &text[strlen(text)];
  total_written += sprintf(property_list,
                "{\"Agent %s\" agent_name label  } ", agent_->name());

  // ---- CBR -> Constant Bit Rate
  if (strcmp(name(), "CBR") == 0) {
    timelist.getListString(timelist_string, 200);
    property_list = &text[strlen(text)];
    total_written += sprintf(property_list,
                            "{\"Start/Stop Time\" timelist timelist {%s}} ", 
                            timelist_string);

    property_list = &text[strlen(text)];
    total_written += sprintf(property_list,
                      "{\"Interval\" interval_ text %f} ", interval_);

  // ---- Exponential
  } else if (!strcmp(name(), "Exponential")) {  // strcmp returns 0 when equal
    timelist.getListString(timelist_string, 200);
    property_list = &text[strlen(text)];
    total_written += sprintf(property_list,
                            "{\"Start/Stop Time\" timelist timelist {%s}} ", 
                            timelist_string);

//    --- Why Packet size for both traffic generators and agents?
//    property_list = &text[strlen(text)];
//    total_written += sprintf(property_list,
//                      "{\"Interval\" packet_size_ text %d} ", packet_size_);

    property_list = &text[strlen(text)];
    total_written += sprintf(property_list,
                      "{\"Burst Time (ms)\" burst_time_ text %d} ", burst_time_);

    property_list = &text[strlen(text)];
    total_written += sprintf(property_list,
                      "{\"Idle Time (ms)\" idle_time_ text %d} ", idle_time_);

    property_list = &text[strlen(text)];
    total_written += sprintf(property_list,
                      "{\"Rate (k)\" rate_ text %d} ", rate_);


  // ---- FTP
  } else if (!strcmp(name(), "FTP")) {  // strcmp returns 0 when equal
    timelist.getListString(timelist_string, 200);
    property_list = &text[strlen(text)];
    total_written += sprintf(property_list,
                            "{\"Start/Stop Time\" timelist timelist {%s}} ", 
                            timelist_string);

    property_list = &text[strlen(text)];
    total_written += sprintf(property_list,
       "{\"Maximum Number of Packets to Send\" maxpkts_ text %d} ", maxpkts_);
  
  
  // ---- Pareto
  } else if (!strcmp(name(), "Pareto")) {  // strcmp returns 0 when equal
    timelist.getListString(timelist_string, 200);
    property_list = &text[strlen(text)];
    total_written += sprintf(property_list,
                            "{\"Start/Stop Time\" timelist timelist {%s}} ", 
                            timelist_string);

//    --- Why Packet size for both traffic generators and agents?
//    property_list = &text[strlen(text)];
//    total_written += sprintf(property_list,
//                      "{\"Interval\" packet_size_ text %d} ", packet_size_);

    property_list = &text[strlen(text)];
    total_written += sprintf(property_list,
                      "{\"Burst Time (ms)\" burst_time_ text %d} ", burst_time_);

    property_list = &text[strlen(text)];
    total_written += sprintf(property_list,
                      "{\"Idle Time (ms)\" idle_time_ text %d} ", idle_time_);

    property_list = &text[strlen(text)];
    total_written += sprintf(property_list,
                      "{\"Rate (k)\" rate_ text %d} ", rate_);

    property_list = &text[strlen(text)];
    total_written += sprintf(property_list,
                      "{\"Shape\" shape_ text %f} ", shape_);


  // ---- Telnet
  } else if (!strcmp(name(), "Telnet")) {  // strcmp returns 0 when equal
    timelist.getListString(timelist_string, 200);
    property_list = &text[strlen(text)];
    total_written += sprintf(property_list,
                            "{\"Start/Stop Time\" timelist timelist {%s}} ", 
                            timelist_string);

    property_list = &text[strlen(text)];
    total_written += sprintf(property_list,
       "{\"Exponetial Distribution Interval\" interval_ text %f} ", interval_);
  }

  return(text);
}