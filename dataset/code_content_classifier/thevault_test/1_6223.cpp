int 
YARPFlowTracker::GenerateAndSend(YARPOutputPortOf<YARPGenericImage>& port)
{
	// segmentation_mask_copy
	// frame from seq
	// port from reader

	// YARPImageSequence& seq = reader->GetSequenceRef();
	// YARPOutputPortOf<YARPGenericImage>& port = reader->GetSegmentedImagePort();

	YARPImageOf<YarpPixelBGR>& frame = seq->GetImageRef (contact_frame);
	YARPImageOf<YarpPixelMono>& mask = segmentation_mask_copy;

#ifdef LOGGING_SEGMENTATIONS
	// awful to just hack this in here... bound to cause trouble...
	// but I'm going to do it anyway.
#ifdef SENDING_SEGMENTATIONS
	{
	  // send frame and mask
	  out_seg.Content().c1.PeerCopy(frame);
	  out_seg.Content().c2.PeerCopy(frame);
	  out_seg.Content().c2.CastCopy(mask);
	  out_seg.Write();
	}
#endif	  
	{
	  char buf[256];
	  long int tick = (long int) YARPTime::GetTimeAsSeconds();
	  sprintf(buf,"%s/%ld.ppm", LOGGING_DIR, tick);
	  printf("Saving frame %s\n", buf);
	  YARPImageFile::Write(buf,frame);
	  sprintf(buf,"%s/%ld.pgm", LOGGING_DIR, tick);
	  printf("Saving mask %s\n", buf);
	  YARPImageFile::Write(buf,mask);
	}
#endif

	YarpPixelBGR black;
	black.r = black.g = black.b = 0;
	YarpPixelBGR black1;
	black1.r = black1.g = black1.b = 1;

	for (int i = 0; i < mask.GetHeight(); i++)
		for (int j = 0; j < mask.GetWidth(); j++)
		{
			if (frame(j,i).r != 0 ||
				frame(j,i).g != 0 ||
				frame(j,i).b != 0)
				output_image(j,i) = (mask(j,i) != 0) ? frame(j,i) : black;
			else
				output_image(j,i) = (mask(j,i) != 0) ? frame(j,i) : black1;
		}

	// send.
	port.Content().Refer (output_image); 
	port.Write ();

	return 0;
}