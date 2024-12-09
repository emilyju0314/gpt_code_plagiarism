UAbstractClient::error_type
  UAbstractClient::sendSound(const char* device, const USound& sound,
			     const char* tag)
  {
    switch (sound.soundFormat)
    {
    case SOUND_MP3:
    case SOUND_OGG:
      // We don't handle chunking for these formats.
      return sendBin(sound.data, sound.size,
		     "%s +report:  %s.val = BIN %lu %s;",
		     tag, device, static_cast<unsigned long>(sound.size),
                     sound.soundFormat == SOUND_MP3 ? "mp3" : "ogg");
      break;

    case SOUND_WAV:
    case SOUND_RAW:
    {
      const char* dev = device ? device : "speaker";
      send("%s.removeSlot(\"sendsoundsaveblend\") |"
           "var %s.sendsoundsaveblend = %s.val->blend;"
           "%s.val->blend=\"queue\";",
           dev, dev, dev, dev);
      sendSoundData* s = new sendSoundData();
      s->bytespersec = sound.channels * sound.rate * (sound.sampleSize / 8);
      s->uc = this;
      s->buffer = new char[sound.size];
      memcpy(s->buffer, sound.data, sound.size);
      s->length = sound.size;
      s->tag = tag ? strdup(tag) : 0;
      s->device = strdup(device);
      s->pos = 0;
      s->format = sound.soundFormat;
      if (sound.soundFormat == SOUND_RAW)
	sprintf(s->formatString, "%zd %zd %zd %d",
		sound.channels, sound.rate, sound.sampleSize,
		sound.sampleFormat);
      else
	s->formatString[0] = 0;
      s->startNotify = false;
      std::string utag = fresh();
      (*this) << "var " + utag +" = Channel.new(\"" << utag << "\");";
      UCallbackID cid = setCallback(sendSound_, s, utag.c_str());
      // Invoke it 2 times to queue sound.
      if (sendSound_(s, UMessage(*this, 0, utag, "*** stop",
				 binaries_type()))
          == URBI_CONTINUE)
      {
	if (sendSound_(s, UMessage(*this, 0, utag, "*** stop",
				   binaries_type()))
            == URBI_REMOVE)
	  deleteCallback(cid);
      }
      else
	deleteCallback(cid);
      return 0;
    }

    default:
      // Unrecognized format.
      return 1;
    }
  }