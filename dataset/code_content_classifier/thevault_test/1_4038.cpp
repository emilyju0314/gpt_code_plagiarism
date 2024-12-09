at::ScalarType cnrtType2ScalarType(cnrtDataType_t cnrt_dtype) {
  switch (cnrt_dtype) {
    case CNRT_FLOAT32:
      return at::ScalarType::Float;
    case CNRT_FLOAT64:
      return at::ScalarType::Double;
    case CNRT_FLOAT16:
      return at::ScalarType::Half;
    case CNRT_INT64:
      return at::ScalarType::Long;
    case CNRT_INT32:
      return at::ScalarType::Int;
    case CNRT_INT8:
      return at::ScalarType::Char;
    case CNRT_UINT8:
      return at::ScalarType::Byte;
    case CNRT_BOOL:
      return at::ScalarType::Bool;
    case CNRT_INT16:
      return at::ScalarType::Short;
    default: {
      CNLOG(ERROR) << "Unsupported data type from cnrtDataType_t to at::ScalarType!";
      return at::ScalarType::Undefined;
    }
  }
}