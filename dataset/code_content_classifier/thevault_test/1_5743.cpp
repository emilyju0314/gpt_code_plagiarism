FVector ConvertLeapToUE(Leap::Vector LeapVector)
{
	//Convert Axis
	FVector ConvertedVector = FVector(-LeapVector.z, LeapVector.x, LeapVector.y);

	//Hmd orientation adjustment
	if (LeapShouldAdjustForFacing)
	{
		FRotator Rotation = FRotator(90.f, 0.f, 180.f);
		ConvertedVector = FQuat(Rotation).RotateVector(ConvertedVector);
		
		if (LeapShouldAdjustRotationForHMD)
		{
			if (GEngine->HMDDevice.IsValid())
			{
				FQuat orientationQuat;
				FVector position;
				GEngine->HMDDevice->GetCurrentOrientationAndPosition(orientationQuat, position);
				ConvertedVector = orientationQuat.RotateVector(ConvertedVector);
			}
		}
	}

	return ConvertedVector;
}