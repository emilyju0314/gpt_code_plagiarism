void IAGSEngine::DisableSound() {
    shutdown_sound();
    usetup.digicard = DIGI_NONE;
    usetup.midicard = MIDI_NONE;
    reserve_voices(0, 0);
    install_sound(DIGI_NONE, MIDI_NONE, nullptr);
}