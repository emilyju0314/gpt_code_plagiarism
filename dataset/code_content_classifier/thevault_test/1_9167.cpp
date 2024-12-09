double PID::Tuning(double params[3], double error){
    
    double steering = -p[0]*error - (error-lastError)*p[2] - integralError*p[1];
    integralError += error;
    lastError = error;
    totalError += error*error;
    
    
    if(tuningCounter > (nP-1)){ tuningCounter = 0;}
     
    if(counter>counterMax){
        counter = 0;
        if(totalError/counterMax < bestError){
            bestError = totalError/counterMax;
            p[tuningCounter] += dp[tuningCounter];
            cout << "Increasing p " << p[tuningCounter] << endl;
        }
        else{
            p[tuningCounter] -= dp[tuningCounter];
            cout << "Decreasing p " << p[tuningCounter] << endl;
        }
        tuningCounter++;
        p[tuningCounter] += dp[tuningCounter];
        restartFlag = true;
        tryout++;
        lastError = 0;
        integralError = 0;
        
            
    }
    counter++;
    
    if(steering >1) steering = 1;
    if(steering < -1) steering = -1;
    return steering;
}