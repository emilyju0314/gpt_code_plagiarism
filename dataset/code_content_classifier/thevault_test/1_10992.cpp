void WERD_RES::SetupBoxWord() {
  delete box_word;
  rebuild_word->ComputeBoundingBoxes();
  box_word = tesseract::BoxWord::CopyFromNormalized(rebuild_word);
  box_word->ClipToOriginalWord(denorm.block(), word);
}