UTexture2D* PrivateLeapImage::Texture32PrettyFromLeapDistortion(int32 SrcWidth, int32 SrcHeight, float* ImageBuffer)
{
	// Lock the texture so it can be modified
	if (Self->PDistortionPointer == nullptr)
	{
		return nullptr;
	}

	int32 DestWidth = SrcWidth / 2; // Put 2 floats in the R and G channels
	int32 DestHeight = SrcHeight;

	// Lock the texture so it can be modified
	uint8* MipData = static_cast<uint8*>(Self->PDistortionPointer->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE));

	// Create base mip.
	uint8* DestPtr = nullptr;
	const float* SrcPtr = ImageBuffer;
	DestPtr = MipData;

	for (int d = 0; d < SrcWidth * SrcHeight; d += 2)
	{
		float dX = ImageBuffer[d];
		float dY = ImageBuffer[d + 1];
		int destIndex = d * 2;

		if (!((dX < 0) || (dX > 1)) && !((dY < 0) || (dY > 1))) {
			//R
			DestPtr[destIndex] = (uint8)FMath::Clamp<int32>(FMath::TruncToInt(dX *255.f), 0, 255);

			//G
			DestPtr[destIndex + 1] = (uint8)FMath::Clamp<int32>(255 - FMath::TruncToInt(dY *255.f), 0, 255);

			//B
			DestPtr[destIndex + 2] = 0;

			//A
			DestPtr[destIndex + 3] = 255;

			//if (d == (SrcHeight / 2) * SrcWidth + (SrcWidth / 2))
			//	UE_LOG(LeapPluginLog, Log, TEXT("(%d, %d, %d, %d), (%1.3f,%1.3f) @pos: %d"), DestPtr[destIndex], DestPtr[destIndex + 1], DestPtr[destIndex + 2], DestPtr[destIndex + 3],dX, dY, d);
		}
		else
		{
			//R
			DestPtr[destIndex] = 0;
			
			//G
			DestPtr[destIndex + 1] = 0;

			//B
			DestPtr[destIndex + 2] = 255;

			//A
			DestPtr[destIndex + 3] = 255;
		}
	}

	// Unlock the texture
	Self->PDistortionPointer->PlatformData->Mips[0].BulkData.Unlock();
	Self->PDistortionPointer->UpdateResource();

	return Self->PDistortionPointer;
}