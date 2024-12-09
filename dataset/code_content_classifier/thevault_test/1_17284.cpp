void AFPS_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Axis Bindings
	InputComponent->BindAxis("MoveForward", this, &AFPS_Character::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AFPS_Character::MoveRight);
	InputComponent->BindAxis("CameraPitch", this, &AFPS_Character::PitchCamera);
	InputComponent->BindAxis("CameraYaw", this, &AFPS_Character::YawCamera);

	//Action Bindings
	InputComponent->BindAction("Sprint", EInputEvent::IE_Pressed, this, &AFPS_Character::Sprint);
	InputComponent->BindAction("Sprint", EInputEvent::IE_Released, this, &AFPS_Character::SprintReleased);
	
	UCharacterMovementComponent* Movement = (UCharacterMovementComponent*)GetMovementComponent();

	InputComponent->BindAction("Crouch", EInputEvent::IE_Pressed, this, &AFPS_Character::CrouchStarted);
	InputComponent->BindAction("Crouch", EInputEvent::IE_Released, this, &AFPS_Character::CrouchReleased);
	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AFPS_Character::Jump);
	InputComponent->BindAction("Zoom", EInputEvent::IE_Pressed, this, &AFPS_Character::Zoom);
	InputComponent->BindAction("Zoom", EInputEvent::IE_Released, this, &AFPS_Character::ZoomReleased);
	InputComponent->BindAction("Interact", EInputEvent::IE_Pressed, this, &AFPS_Character::Interact);




}