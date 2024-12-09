double check_st_dev(double *freq_values, int length, double old_avg, String freq_name, String time){

    
    double new_avg = find_average(freq_values, length);
    double std = st_dev(freq_values, old_avg, length);
    
    if (freq_name == "70Hz"){
        Serial.println("In check_st_dev *************");
        Serial.println("STD:");
        Serial.println(std/2);

        Serial.println("old avg:");
        Serial.println(old_avg);
        
        Serial.println("new avg:");
        Serial.println(new_avg);
    
        
    }
    
    if ((old_avg - (std/2)) > new_avg || (old_avg + (std/2)) < new_avg) {
        report_drop(old_avg,new_avg, freq_name, time);
    }
    
    return new_avg;
    
}