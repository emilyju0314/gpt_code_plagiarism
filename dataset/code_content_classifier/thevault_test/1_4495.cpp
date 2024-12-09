HRESULT CEncoder::Init()
{
    CAutoLock l(&m_lock);

    m_outOffset     = 0;
    m_outReadOffset = 0;

    m_bFinished     = FALSE;

    m_frameCount    = 0;

    if (!pgf)
    {
        if (!m_bInpuTypeSet || !m_bOutpuTypeSet)
            return E_UNEXPECTED;

        // Init Lame library
        // note: newer, safer interface which doesn't 
        // allow or require direct access to 'gf' struct is being written
        // see the file 'API' included with LAME.
        if (pgf = lame_init())
        {
            lame_set_num_channels(pgf, m_wfex.nChannels);
            lame_set_in_samplerate(pgf, m_wfex.nSamplesPerSec);
            lame_set_out_samplerate(pgf, m_mabsi.dwSampleRate);
            if ((lame_get_out_samplerate(pgf) >= 32000) && (m_mabsi.dwBitrate < 32))
                lame_set_brate(pgf, 32);
            else
                lame_set_brate(pgf, m_mabsi.dwBitrate);
            lame_set_VBR(pgf, m_mabsi.vmVariable);
            lame_set_VBR_min_bitrate_kbps(pgf, m_mabsi.dwVariableMin);
            lame_set_VBR_max_bitrate_kbps(pgf, m_mabsi.dwVariableMax);

            lame_set_copyright(pgf, m_mabsi.bCopyright);
            lame_set_original(pgf, m_mabsi.bOriginal);
            lame_set_error_protection(pgf, m_mabsi.bCRCProtect);

            lame_set_bWriteVbrTag(pgf, m_mabsi.dwXingTag);
            lame_set_strict_ISO(pgf, m_mabsi.dwStrictISO);
            lame_set_VBR_hard_min(pgf, m_mabsi.dwEnforceVBRmin);

            if (lame_get_num_channels(pgf) == 2 && !m_mabsi.bForceMono)
            {
                //int act_br = pgf->VBR ? pgf->VBR_min_bitrate_kbps + pgf->VBR_max_bitrate_kbps / 2 : pgf->brate;

                // Disabled. It's for user's consideration now
                //int rel = pgf->out_samplerate / (act_br + 1);
                //pgf->mode = rel < 200 ? m_mabsi.ChMode : JOINT_STEREO;

                lame_set_mode(pgf, m_mabsi.ChMode);
            }
            else
                lame_set_mode(pgf, MONO);

            if (lame_get_mode(pgf) == JOINT_STEREO)
                lame_set_force_ms(pgf, m_mabsi.dwForceMS);
            else
                lame_set_force_ms(pgf, 0);

//            pgf->mode_fixed = m_mabsi.dwModeFixed;

            if (m_mabsi.dwVoiceMode != 0)
            {
                lame_set_lowpassfreq(pgf,12000);
                ///pgf->VBR_max_bitrate_kbps = 160;
            }

            if (m_mabsi.dwKeepAllFreq != 0)
            {
                ///pgf->lowpassfreq = -1;
                ///pgf->highpassfreq = -1;
                /// not available anymore
            }

            lame_set_quality(pgf, m_mabsi.dwQuality);
            lame_set_VBR_q(pgf, m_mabsi.dwVBRq);

            lame_init_params(pgf);

            // encoder delay compensation
            {
                int const nch = lame_get_num_channels(pgf);
                short * start_padd = (short *)calloc(48, nch * sizeof(short));

				int out_bytes = 0;

                if (nch == 2)
                    out_bytes = lame_encode_buffer_interleaved(pgf, start_padd, 48, m_outFrameBuf, OUT_BUFFER_SIZE);
                else
                    out_bytes = lame_encode_buffer(pgf, start_padd, start_padd, 48, m_outFrameBuf, OUT_BUFFER_SIZE);

				if (out_bytes > 0)
					m_outOffset += out_bytes;

                free(start_padd);
            }

            return S_OK;
        }

        return E_FAIL;
    }

    return S_OK;
}