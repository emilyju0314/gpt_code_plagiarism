void TBControl::feedbackMoveZ(int fastSteps, double thresh) {
    double weight = 0; 
    int st = 0;
    
    // fastSteps determines how many steps will be 
    // taken quickly, with no load cell feedback.
    zaxis->setForward();
    
    zaxis->stepBlocking(fastSteps);

    while (weight < thresh && zPos() < 1275) {
        zaxis->stepBlocking();
        if (st == 0) {
            weight = 0;
            for (int i = 0; i < 4; i++) {
                weight += abs((*(scales + i)).get_units()); 
            }
        }
        weight /= 4;
        st = (st + 1) % 20;
    }
    Serial.print("Pressed to max force ");
    Serial.println(weight);
}