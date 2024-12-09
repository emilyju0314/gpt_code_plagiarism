void ts::PESDemux::getAudioAttributes(PID pid, AudioAttributes& va) const
{
    PIDContextMap::const_iterator pci = _pids.find(pid);
    if (pci == _pids.end() || !pci->second.audio.isValid()) {
        va.invalidate();
    }
    else {
        va = pci->second.audio;
    }
}