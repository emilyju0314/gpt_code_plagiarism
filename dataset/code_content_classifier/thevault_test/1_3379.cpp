void* GetDstPtrByDLDataType(DLDataType type, framework::Tensor* dst,
                            const platform::Place& dst_place) {
  // vector types not currently supported
  PADDLE_ENFORCE_LE(type.lanes, 1,
                    platform::errors::Unimplemented(
                        "Vector type is not supported currently."));

  switch (type.bits) {
    case 8:
      if (type.code == kDLInt)
        return static_cast<void*>(dst->mutable_data<int8_t>(dst_place));
      if (type.code == kDLUInt)
        return static_cast<void*>(dst->mutable_data<uint8_t>(dst_place));
      PADDLE_THROW(platform::errors::Unimplemented(
          "DLDataType code <%d> is illegal when DLDataType.bits is <%d>.",
          type.code, type.bits));
    case 16:
      if (type.code == kDLInt)
        return static_cast<void*>(dst->mutable_data<int16_t>(dst_place));
      if (type.code == kDLFloat)
        return static_cast<void*>(
            dst->mutable_data<paddle::platform::float16>(dst_place));
      if (type.code == kDLBfloat)
        return static_cast<void*>(
            dst->mutable_data<paddle::platform::bfloat16>(dst_place));
      PADDLE_THROW(platform::errors::Unimplemented(
          "DLDataType code <%d> is illegal when DLDataType.bits is <%d>.",
          type.code, type.bits));
    case 32:
      if (type.code == kDLInt)
        return static_cast<void*>(dst->mutable_data<int32_t>(dst_place));
      if (type.code == kDLFloat)
        return static_cast<void*>(dst->mutable_data<float>(dst_place));
      PADDLE_THROW(platform::errors::Unimplemented(
          "DLDataType code <%d> is illegal when DLDataType.bits is <%d>.",
          type.code, type.bits));
    case 64:
      if (type.code == kDLInt)
        return static_cast<void*>(dst->mutable_data<int64_t>(dst_place));
      if (type.code == kDLFloat)
        return static_cast<void*>(dst->mutable_data<double>(dst_place));
      if (type.code == kDLComplex)
        return static_cast<void*>(
            dst->mutable_data<paddle::platform::complex<float>>(dst_place));
      PADDLE_THROW(platform::errors::Unimplemented(
          "DLDataType code <%d> is illegal when DLDataType.bits is <%d>.",
          type.code, type.bits));
    case 128:
      if (type.code == kDLComplex)
        return static_cast<void*>(
            dst->mutable_data<paddle::platform::complex<double>>(dst_place));
      PADDLE_THROW(platform::errors::Unimplemented(
          "DLDataType code <%d> is illegal when DLDataType.bits is <%d>.",
          type.code, type.bits));
    default:
      PADDLE_THROW(platform::errors::Unimplemented(
          "Unsupported DLDataType.bits %d.", type.bits));
  }
}