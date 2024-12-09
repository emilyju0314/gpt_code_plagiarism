UTexture2D* PrivateLeapImage::Texture128FromLeapDistortion(int32 SrcWidth, int32 SrcHeight, float* ImageBuffer)
{
	// Lock the texture so it can be modified
	if (Self->PDistortionPointer == nullptr)
	{
		return nullptr;
	}

	int32 DestWidth = SrcWidth / 2; // Put 2 floats in the R and G channels
	int32 DestHeight = SrcHeight;

	// Lock the texture so it can be modified
	float* MipData = static_cast<float*>(Self->PDistortionPointer->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE));

	// Create base mip.
	float* DestPtr = nullptr;
	const float* SrcPtr = ImageBuffer;
	DestPtr = MipData;
	int32 length = SrcWidth * SrcHeight;

	for (int d = 0; d < length; d += 2)
	{
		float dX = ImageBuffer[d];
		float dY = ImageBuffer[d + 1];
		int destIndex = d * 2;

		//R
		DestPtr[destIndex] = dX;

		//G
		DestPtr[destIndex + 1] = dY;

		//B
		DestPtr[destIndex + 2] = 0.f;

		//A
		DestPtr[destIndex + 3] = 0.f;
	}

	// Unlock the texture
	Self->PDistortionPointer->PlatformData->Mips[0].BulkData.Unlock();
	Self->PDistortionPointer->UpdateResource();

	return Self->PDistortionPointer;
}