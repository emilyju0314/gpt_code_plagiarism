Mqtt_Helper::Mqtt_Helper(String ID="") {

    // check if an id was given or id is ok
    if (ID == "" || ID.length() != 6) { // no id given or bad id
        // generate a random id
        _ID = "ABCDEF";
    } else {
        _ID = ID;
    }
}