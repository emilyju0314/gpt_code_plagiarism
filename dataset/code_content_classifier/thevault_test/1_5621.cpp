void ComputeForwVector( int* recon_right_for_ptr, int* recon_down_for_ptr,
                        VidStream* the_stream )
{

  Pict *picture;
  Macroblock *mblock;

  picture = &(the_stream->picture);
  mblock = &(the_stream->mblock);

  ComputeVector(recon_right_for_ptr, recon_down_for_ptr,
		mblock->recon_right_for_prev, 
		mblock->recon_down_for_prev,
		(int) picture->forw_f,
		picture->full_pel_forw_vector,
		mblock->motion_h_forw_code, mblock->motion_v_forw_code,
		mblock->motion_h_forw_r, mblock->motion_v_forw_r); 
}