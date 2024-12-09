void 
YARPSoundDeviceDriver::Body (void)
{
	SoundResources& d = RES(system_resources);
	MSG		msg;

	const int prio = ACE_Sched_Params::next_priority (ACE_SCHED_OTHER, GetPriority(), ACE_SCOPE_THREAD);
	SetPriority (prio);
	
	//----------------------------------------------------------------------
	//  Wait for a message sent by the audio driver
	//----------------------------------------------------------------------
	while (GetMessage(&msg, 0, 0, 0) == 1 && !IsTerminated()) {

		switch (msg.message) {
			case MM_WIM_DATA: //Buffer filled 
				/*********************************************************************************
				 * the msg.lParam contains a pointer to the WAVEHDR structure for the filled buffer. *
				 *********************************************************************************/
				if (((WAVEHDR *)msg.lParam)->dwBytesRecorded) {
					//----------------------------------------------------------------------
					//  Here write in the local buffer using the syncronization mutexes
					//----------------------------------------------------------------------
					if (d._bmutex.PollingWait () == 1) { // buffer acquired. Reading from the buffer
						if (d.m_InRecord)
							memcpy (d._rawBuffer, 
									((WAVEHDR *)msg.lParam)->lpData, 
                                    ((WAVEHDR *)msg.lParam)->dwBytesRecorded); // Note: is this right?
                                                                               // The buffer could not be full...
						if (d._canpost) {
							d._canpost = false;
							d._new_frame.Post();
						}
						d._bmutex.Post ();
					}
					else
					{
						//----------------------------------------------------------------------
						//  can't acquire, it means the buffer is still in use.
						//  silently ignores this condition.
						//----------------------------------------------------------------------
						ACE_DEBUG ((LM_DEBUG, "lost a frame, acq thread\n"));
					}
				}

				//----------------------------------------------------------------------
				//  Requeue the used buffer	
				//----------------------------------------------------------------------
				waveInAddBuffer(d.m_WaveInHandle, 
								(WAVEHDR *)msg.lParam, 
								sizeof(WAVEHDR));

				break;
				/* Our main thread is opening the WAVE device */
			case MM_WIM_OPEN:
				ACE_DEBUG ((LM_DEBUG, "yarpsounddriver: sound device opened\n"));
				break;
				/* Our main thread is closing the WAVE device */
			case MM_WIM_CLOSE:
				break;
			default:
				//ACE_DEBUG ((LM_DEBUG, "yarpsounddriver: received an unknown message\n"));
				break;
		}
	}

	ACE_DEBUG ((LM_DEBUG, "acquisition thread returning...\n"));
}