bool CycleTracksAndFXs(int _trStart, int _fxStart, int _dir, bool _selectedTracks,
		bool (*job)(MediaTrack*,int,bool), bool* _cycled) // see 2 "jobs" below..
{
	int cpt1 = 0;
	int i = _trStart;
	while (cpt1 <= GetNumTracks())
	{
		if (i > GetNumTracks()) {
			i = 0;
			*_cycled = (cpt1 > 0); // ie not the first loop
		}
		else if (i < 0)  {
			i = GetNumTracks();
			*_cycled = (cpt1 > 0); // ie not the first loop
		}

		MediaTrack* tr = CSurf_TrackFromID(i, false);
		int fxCount = tr ? TrackFX_GetCount(tr) : 0;
		if (tr && fxCount &&  (!_selectedTracks || (_selectedTracks && *(int*)GetSetMediaTrackInfo(tr, "I_SELECTED", NULL))))
		{
			int cpt2 = 0;
			int j = (i==_trStart ? _fxStart+_dir : (_dir<0 ? fxCount-1 : 0));
			while (cpt2 < fxCount)
			{
				if (j >= fxCount || j < 0)
					break; // implies track cycle

				// NF fix #864: check for offline FX and skip them
				if (TrackFX_GetOffline) { // we can use API, added in R5.95, optional for now
					if (!TrackFX_GetOffline(tr, j)) { // FX is online, perform job, otherwise skip to next
						// perform custom stuff
						if (job(tr, j, _selectedTracks))
							return true;
					}
				}
				else {
					char state[2] = "0";
					SNM_ChunkParserPatcher p(tr);
					p.SetWantsMinimalState(true);
					p.Parse(SNM_GET_CHUNK_CHAR, 2, "FXCHAIN", "BYPASS", j, 2, state);

					if (strcmp(state, "0") == 0) { // FX is online, perform job, otherwise skip to next
						// perform custom stuff
						if (job(tr, j, _selectedTracks))
							return true;
					}
				}

				cpt2++;
				j += _dir;
			}
		}
		cpt1++;
		i += _dir;
	}
	return false;
}