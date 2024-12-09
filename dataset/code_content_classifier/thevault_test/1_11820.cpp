struct ColorRGB colorHSV( byte hue, byte saturation, byte value ) {
	struct ColorRGB colorHue = wheel( hue );

	return {
		.r = hsvMix( colorHue.r, saturation, value ),
		.g = hsvMix( colorHue.g, saturation, value ),
		.b = hsvMix( colorHue.b, saturation, value )
	};
}