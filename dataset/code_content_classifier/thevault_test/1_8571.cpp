void MovieAsset::Update(wxString wanted_filename, int assume_number_of_frames)
{
	filename = wanted_filename;
	is_valid = false;
	
	if (filename.IsOk() == true && filename.FileExists() == true)
	{
		if (filename.GetExt().IsSameAs("mrc",false) || filename.GetExt().IsSameAs("mrcs",false))
		{
			is_valid = GetMRCDetails(filename.GetFullPath().fn_str(), x_size, y_size, number_of_frames);
		}
		else if (filename.GetExt().IsSameAs("tif",false))
		{
			TiffFile temp_tif;
			is_valid = temp_tif.OpenFile(filename.GetFullPath().ToStdString(), false, false, assume_number_of_frames);
			x_size = temp_tif.ReturnXSize();
			y_size = temp_tif.ReturnYSize();
			number_of_frames = temp_tif.ReturnNumberOfSlices();
			temp_tif.CloseFile();
		}
		else if (filename.GetExt().IsSameAs("eer",false))
		{
			EerFile temp_eer;
			is_valid = temp_eer.OpenFile(filename.GetFullPath().ToStdString(), false, false, assume_number_of_frames,eer_super_res_factor,eer_frames_per_image);
			x_size = temp_eer.ReturnXSize();
			y_size = temp_eer.ReturnYSize();
			number_of_frames = temp_eer.ReturnNumberOfSlices();
			temp_eer.CloseFile();
		}
		else
		{
			is_valid = false;
		}
	}
}