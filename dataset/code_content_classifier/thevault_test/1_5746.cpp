UTexture2D* PrivateLeapImage::EnqueuedTexture32FromLeapImage(int32 SrcWidth, int32 SrcHeight, uint8* ImageBuffer)
{
	
	// Lock the texture so it can be modified
	if (Self->PImagePointer == nullptr)
	{
		return nullptr;
	}

	UpdateTextureRegions(Self->PImagePointer, 0, 1, &UpdateTextureRegion, 4 * SrcWidth, 4, ImageBuffer, false);
	return Self->PImagePointer;
}