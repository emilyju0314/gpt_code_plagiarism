fltx4 ConvertLightmapColorToRGBScale( FLTX4 lightmapColor )
{
	
	static const fltx4 vTwoFiftyFive = {255.0f, 255.0f, 255.0f, 255.0f};
	static const fltx4 FourPoint1s = { 0.1, 0.1, 0.1, 0.1 };
	static const fltx4 vTwoFiftyFiveOverSixteen = {255.0f / 16.0f, 255.0f / 16.0f, 255.0f / 16.0f, 255.0f / 16.0f};
	// static const fltx4 vSixteenOverTwoFiftyFive = { 16.0f / 255.0f, 16.0f / 255.0f, 16.0f / 255.0f, 16.0f / 255.0f };


	// find the highest color value in lightmapColor and replicate it
	fltx4 scale = FindHighestSIMD3( lightmapColor );
	fltx4 minscale = FindLowestSIMD3( lightmapColor );
	fltx4 fl4OutofRange = OrSIMD( CmpGeSIMD( scale, Four_Ones ), CmpLeSIMD( scale, FourPoint1s ) );
	fl4OutofRange = OrSIMD( fl4OutofRange, CmpGtSIMD( minscale, MulSIMD( Four_PointFives, scale ) ) );

	// scale needs to be divided by 16 (because the shader multiplies it by 16)
	// then mapped to 0..255 and quantized. 
	scale = __vrfip(MulSIMD(scale, vTwoFiftyFiveOverSixteen)); // scale = ceil(scale * 255/16)
		
	fltx4 result = MulSIMD(vTwoFiftyFive, lightmapColor); // start the scale cooking on the final result
		
	fltx4 invScale = ReciprocalEstSIMD(scale); // invScale = (16/255)(1/scale). may be +inf
	invScale = MulSIMD(invScale, vTwoFiftyFiveOverSixteen); // take the quantizing factor back out
															// of the inverse scale (one less
															// dependent op if you do it this way)
		
	// scale the input channels
	// compute so the numbers are all 0..255 ints. (if one happens to 
	// be 256 due to numerical error in the reciprocation, the unsigned-saturate
	// store we'll use later on will bake it back down to 255)
	result = MulSIMD(result, invScale);
		
	// now, output --
	// if the input color was nonzero, slip the scale into return value's w
	// component and return. If the input was zero, return zero.

	result = MaskedAssign( 
		fl4OutofRange,
		SetWSIMD( result, scale ),
		SetWSIMD( MulSIMD( lightmapColor, vTwoFiftyFive ), vTwoFiftyFiveOverSixteen ) );
	return result;
}