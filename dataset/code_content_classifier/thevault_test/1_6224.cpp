int
YARPFlowTracker::GetObjectProperties (YARPImageOf<YarpPixelMono>& mask, YARPImageOf<YarpPixelBGR>& frame)
{
	// contact_frame
	mask.CastCopy (segmentation_mask_copy);
	frame.CastCopy (seq->GetImageRef(contact_frame));

	return 0;
}