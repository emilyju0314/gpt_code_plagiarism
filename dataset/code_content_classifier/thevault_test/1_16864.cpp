JaniceError physical_frame(JaniceMediaIterator it, uint32_t logical, uint32_t *physical)
{
  if (physical == nullptr) {
    return JANICE_BAD_ARGUMENT;
  }
  *physical = logical;
  return JANICE_SUCCESS;
}