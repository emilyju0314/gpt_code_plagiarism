IPianoRollViewStatus::NoteHeight IPianoRollViewStatus::GetNoteYRange(Int32 note_number) const
{
    double const yzoom = GetZoomFactor(wxVERTICAL);
    Int32 const yscroll = GetScrollPosition(wxVERTICAL);
    
    return NoteHeight {
        (float)((kNumKeys - note_number - 1) * kDefaultKeyHeight * yzoom - yscroll),
        (float)((kNumKeys - note_number) * kDefaultKeyHeight * yzoom - yscroll),
    };
}