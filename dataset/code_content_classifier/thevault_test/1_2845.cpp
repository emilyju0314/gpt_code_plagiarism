void Button::Monitor()
{
	Status = digitalRead(PinNumber);
	
	if (Status != LastStatus) {
		if (Status == LOW) {
			//Serial.println("ButtonPressed" + Description);
			Press();
		}

		if (Status == HIGH) {
			Release();
			//Serial.println("ButtonReleased" + Description);
		}
	}
	
	else if (Status == LastStatus) {
		if (Status == LOW) {
			//Serial.println("Holding Button" + Description);
		}
	}
	
	LastStatus = Status;


}