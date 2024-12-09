void HideFXChain(COMMAND_T* _ct) 
{
	Undo_BeginBlock();
	for (int i=0; i <= GetNumTracks(); i++) // incl. master
	{
		MediaTrack* tr = CSurf_TrackFromID(i, false);
		if (tr && (!_ct || (_ct && *(int*)GetSetMediaTrackInfo(tr, "I_SELECTED", NULL)))) 
		{
			TrackFX_Show(tr, -1, 0); // no valid index required for closing FX chain

			// take fx
			for (int j = 0; j < CountTrackMediaItems(tr); j++) 
			{
				MediaItem* item = GetTrackMediaItem(tr, j);
				for (int k = 0; k < CountTakes(item); k++) 
				{
					MediaItem_Take* take = GetMediaItemTake(item, k);
					TakeFX_Show(take, -1, 0);
				}
			}
		}
	}
	Undo_EndBlock("SWS/S&M: Close all FX chain windows", -1);
}