void Emiter::ThrowParticles() {

	//You could use delta time instead of particlesPerFrame, but i dont recommend it
	particlesEmited += particlesPerFrame;

	if (particlesEmited >= 1)
	{
		int emited = 0;

		for(int i = 0; i < particleVector.size(); i++)
		{
			// Call Activate(), use Generate...() functions to get the parameters Activate() needs.
			//Activate returns false if the particle is already active, and true if we activate it.

			if (particleVector[i].Activate())
			{
				particleVector[i].SetLife(particlesLifeTime);
				particleVector[i].Reset(GeneratePosX(), GeneratePosY(), GenerateSpeedX(), GenerateSpeedY(), GenerateAccelerationX(), GenerateAccelerationY(), GenerateAngularSpeed());
				emited++;
			}

			//If we activated the necesary particles this frame, break
			if ((int)particlesEmited == emited)
				break;

		}

		particlesEmited -= emited;
	}
}