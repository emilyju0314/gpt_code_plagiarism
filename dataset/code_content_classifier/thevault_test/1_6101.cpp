int JPEGHandler::fixAspect( Frame &frame )
{
	int width = frame.GetWidth( );
	int height = frame.GetHeight( );
	static JSAMPLE image[ 2048 * 2048 * 3 ];
	register JSAMPLE *dest = image_buffer, *src = image;
	int new_width = frame.IsPAL() ? 337 : 320;
	int n = width / 2 - new_width;
	int d = width / 2;
	int a = n;

	memcpy( src, dest, width * height * 3 );

	for ( register int j = 0; j < height; j += 2 )
	{
		src = image + j * ( width * 3 );
		for ( register int i = 0; i < new_width ; i++ )
		{
			if ( a > d )
			{
				a -= d;
				src += 3;
			}
			else
				a += n;

			*dest++ = *src++;
			*dest++ = *src++;
			*dest++ = *src++;
			src += 3;
		}
	}
	return new_width;
}