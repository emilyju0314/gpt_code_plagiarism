void copy_field(std::unique_ptr<VariantFieldBase>& dst, const std::unique_ptr<VariantFieldBase>& src)
{
  auto dst_non_null = dst.get() ? 1u : 0u;
  auto src_non_null = src.get() ? 1u : 0u;
  auto combined = (dst_non_null << 1u) | src_non_null;
  switch(combined)
  {
    case 0u:     //both null, nothing to do
      break;
    case 1u:     //dst null, src non-null, create copy
      dst = std::move(std::unique_ptr<VariantFieldBase>(src->create_copy()));
      break;
    case 2u:     //dst non-null, src null, invalidate
      dst->set_valid(false);
      break;
    case 3u:     //both non-null, do fast copy
      dst->copy_from(src.get());
      break;
    default:
      break;
  }
}