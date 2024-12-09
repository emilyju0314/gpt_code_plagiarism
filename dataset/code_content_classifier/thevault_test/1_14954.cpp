static BOOLEAN ConvertToETRLE(UINT8** const ppDest, UINT32* const puiDestLen, std::vector<STCISubImage>& subImages, UINT8* const p8BPPBuffer, const UINT16 usWidth, const UINT16 usHeight, const UINT32 fFlags)
try
{
	INT16						sCurrX;
	INT16						sCurrY;
	INT16						sNextX;
	INT16						sNextY;
	UINT8 *					pOutputNext;
	BOOLEAN					fContinue = TRUE;
	BOOLEAN					fOk = TRUE;
	BOOLEAN					fStore;
	BOOLEAN					fNextExists;
	UINT32					uiSubImageCompressedSize;
	UINT32					uiSpaceLeft;

	// worst-case situation	estimate
	uiSpaceLeft = (UINT32) usWidth * (UINT32) usHeight * 3;
	SGP::Buffer<UINT8> dest(uiSpaceLeft);
	*puiDestLen = uiSpaceLeft;

	pOutputNext = dest;

	if (fFlags & CONVERT_ETRLE_COMPRESS_SINGLE)
	{
		// there are no walls in this image, but we treat it as a "subimage" for
		// the purposes of calling the compressor

		// we want a 1-element SubImage array for this...
		// allocate!
		subImages.assign(1, STCISubImage{});
		STCISubImage* const pCurrSubImage = &subImages.back();
		pCurrSubImage->sOffsetX = 0;
		pCurrSubImage->sOffsetY = 0;
		pCurrSubImage->usWidth = usWidth;
		pCurrSubImage->usHeight = usHeight;
		if (!(fFlags & CONVERT_ETRLE_NO_SUBIMAGE_SHRINKING))
		{
			if (!DetermineSubImageUsedSize(p8BPPBuffer, usWidth, usHeight, pCurrSubImage)) return FALSE;
		}
		uiSubImageCompressedSize = ETRLECompressSubImage( pOutputNext, uiSpaceLeft, p8BPPBuffer, usWidth, usHeight, pCurrSubImage );
		if (uiSubImageCompressedSize == 0) return FALSE;

		pCurrSubImage->uiDataOffset = 0;
		pCurrSubImage->uiDataLength = uiSubImageCompressedSize;
		*puiDestLen = uiSubImageCompressedSize;
		*ppDest     = dest.Release();
		return TRUE;
	}
	else
	{
		// skip any initial wall bytes to find the first subimage
		if (!GoPastWall(&sCurrX, &sCurrY, usWidth, usHeight, p8BPPBuffer, 0, 0)) return FALSE;
		subImages.clear();

		while (fContinue)
		try
		{
			STCISubImage subImage = STCISubImage{};

			subImage.sOffsetX = sCurrX;
			subImage.sOffsetY = sCurrY;
			// determine the subimage's full size
			if (!DetermineSubImageSize( p8BPPBuffer, usWidth, usHeight, &subImage ))
			{
				fOk = FALSE;
				break;
			}
			if (subImages.size() == 0 && subImage.usWidth == usWidth && subImage.usHeight == usHeight)
			{
				printf( "\tWarning: no walls (subimage delimiters) found.\n" );
			}

			STCISubImage tempSubImage = subImage;
			if (DetermineSubImageUsedSize( p8BPPBuffer, usWidth, usHeight, &tempSubImage))
			{
				// image has nontransparent data; we definitely want to store it
				fStore = TRUE;
				if (!(fFlags & CONVERT_ETRLE_NO_SUBIMAGE_SHRINKING))
				{
					subImage = tempSubImage;
				}
			}
			else if (fFlags & CONVERT_ETRLE_DONT_SKIP_BLANKS)
			{
				// image is transparent; we will store it if there is another subimage
				// to the right of it on the same line
				// find the next subimage
				fNextExists = GoToNextSubImage( &sNextX, &sNextY, p8BPPBuffer, usWidth, usHeight, sCurrX, sCurrY );
				if (fNextExists && sNextY == sCurrY )
				{
					fStore = TRUE;
				}
				else
				{
					// junk transparent section at the end of the line!
					fStore = FALSE;
				}
			}
			else
			{
				// transparent data; discarding
				fStore = FALSE;
			}

			if (fStore)
			{
				// we want to store this subimage!
				uiSubImageCompressedSize = ETRLECompressSubImage( pOutputNext, uiSpaceLeft, p8BPPBuffer, usWidth, usHeight, &subImage );
				if (uiSubImageCompressedSize == 0)
				{
					fOk = FALSE;
					break;
				}
				subImage.uiDataOffset = (*puiDestLen - uiSpaceLeft);
				subImage.uiDataLength = uiSubImageCompressedSize;
				// this is a cheap hack; the sOffsetX and sOffsetY values have been used
				// to store the location of the subimage within the whole image.  Now
				// we want the offset within the subimage, so, we subtract the coordatines
				// for the upper-left corner of the subimage.
				subImage.sOffsetX -= sCurrX;
				subImage.sOffsetY -= sCurrY;
				subImages.push_back(subImage);
				pOutputNext += uiSubImageCompressedSize;
				uiSpaceLeft -= uiSubImageCompressedSize;
			}
			// find the next subimage
			fContinue = GoToNextSubImage( &sCurrX, &sCurrY, p8BPPBuffer, usWidth, usHeight, sCurrX, sCurrY );
		}
		catch (...)
		{
			fOk = FALSE;
			break;
		}
	}
	if (!fOk)
	{
		return( FALSE );
	}

	*puiDestLen -= uiSpaceLeft;
	*ppDest      = dest.Release();
	return TRUE;
}
catch (...) { return FALSE; }