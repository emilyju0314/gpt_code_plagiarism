void AFPS_Character::SmoothCrouch(float DeltaTime) 
{

	
	//Crouch
	if (bIsCrouching && CurrentEyeHeight - CrouchRealEyeHeight > 0.f)  {

		CrouchAlpha += DeltaTime;
		CrouchAlpha = FMath::Clamp(CrouchAlpha, 0.f, CrouchTransitionTime); //Time Interval for zooming

		CrouchAlphaLerp = CrouchAlpha / CrouchTransitionTime;
		CrouchAlphaLerp = CrouchAlphaLerp * CrouchAlphaLerp ; //quadratic function for smoothness (x^2)


		CurrentEyeHeight = FMath::Lerp(BaseEyeHeight, CrouchRealEyeHeight, CrouchAlphaLerp); //Calculate FOV
		CameraComponent->SetRelativeLocation(FVector(CameraComponent->GetRelativeLocation().X, CameraComponent->GetRelativeLocation().Y, CurrentEyeHeight)); //Adjust FOV

		if (bIsSprinting) {
			SprintReleased();
		}

	}//Uncrouch
	else if (!bIsCrouching && BaseEyeHeight - CurrentEyeHeight > 0.f) {

		//Calculate interpolation alpha
		CrouchAlpha -= DeltaTime;
		CrouchAlpha = FMath::Clamp(CrouchAlpha,0.f, CrouchTransitionTime); //Time Interval for crouching

		CrouchAlphaLerp = CrouchAlpha / CrouchTransitionTime;
		CrouchAlphaLerp = CrouchAlphaLerp * CrouchAlphaLerp ; //quadratic function for smoothness (x^2)


		CurrentEyeHeight = FMath::Lerp(BaseEyeHeight, CrouchRealEyeHeight, CrouchAlphaLerp); //Calculate eye height
		CameraComponent->SetRelativeLocation(FVector(CameraComponent->GetRelativeLocation().X, CameraComponent->GetRelativeLocation().Y, CurrentEyeHeight)); //Adjust eye height
	}
}