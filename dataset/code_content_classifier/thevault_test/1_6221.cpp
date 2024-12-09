int 
SoundProcessing::GetThresholds(Thresholds *actual_thresholds)
{
	actual_thresholds->nvalidpoints = thresholds.nvalidpoints;
	actual_thresholds->max_left     = thresholds.max_left;
	actual_thresholds->max_right    = thresholds.max_right;
	actual_thresholds->min_left     = thresholds.min_left;
	actual_thresholds->min_right    = thresholds.min_right;
	
	return 1;
}