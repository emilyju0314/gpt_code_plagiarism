void TasktoAccumulateSensorData(void *pvParameters)
{
  PIR *pir = new PIR;
  AccumulateData *accumulatedData = new AccumulateData;
  Pump *pump = new Pump;
  Buttons *buttons = new Buttons;

  Serial.print("Application Tasks running on core ");
  Serial.println(xPortGetCoreID());

  for (;;)
  {
    if (millis() - lastMillis >= 5000)
    {
      lastMillis = millis(); // get ready for the next iteration
      pump->checkTurnOffPump();
      checkTurnOffSettings();
      accumulatedData->InitAccumulateDataJson();
    }
    pir->SetupMainLoop();  // Setup the main loop for the PIR sensor
    pump->SetupMainLoop(); // Setup the main loop for the pump
    buttons->ButtonLoop(); // Setup the main loop for the buttons

    // Automatic Functionality
    if ((S_OnOff == true) && (S_Menu == false) && (S_ManAut == true))
    {
      pump->Automatic();
    }

    // Manual Functionality
    if ((S_OnOff == true) && (S_Menu == false) && (S_ManAut == false))
    {
      pump->Manual();
    }
  }
  delete pir;
  delete pump;
  delete buttons;
  delete accumulatedData;
}