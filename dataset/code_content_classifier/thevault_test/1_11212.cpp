void UNICHARSET::UNICHAR_PROPERTIES::CopyFrom(const UNICHAR_PROPERTIES &src) {
  // Apart from the fragment, everything else can be done with a default copy.
  CHAR_FRAGMENT *saved_fragment = fragment;
  *this = src; // Bitwise copy.
  fragment = saved_fragment;
}