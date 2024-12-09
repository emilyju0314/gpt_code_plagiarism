PLYValue *createValue(ply_type type, ply_encoding encoding)
{
  if (encoding == ply_ascii)
  {
    switch (type)
    {
      case ply_int8:
      case ply_int16:
      case ply_int32:
        return new PLYValueASCIIInt();

      case ply_uint8:
      case ply_uint16:
      case ply_uint32:
        return new PLYValueASCIIUInt();

      case ply_float32:
      case ply_float64:
        return new PLYValueASCIIDouble();

      default:
        break;
    }
  }
  else if (encoding == ply_big_endian)
  {
    switch (type)
    {
      case ply_int8:
        return new PLYValueInt8();

      case ply_uint8:
        return new PLYValueUInt8();

      case ply_int16:
        return new PLYValueBigInt16();

      case ply_uint16:
        return new PLYValueBigUInt16();

      case ply_int32:
        return new PLYValueBigInt32();

      case ply_uint32:
        return new PLYValueBigUInt32();

      case ply_float32:
        if (gutil::isMSBFirst())
        {
          return new PLYValueFloat32();
        }
        else
        {
          return new PLYValueSwapFloat32();
        }

      case ply_float64:
        if (gutil::isMSBFirst())
        {
          return new PLYValueFloat64();
        }
        else
        {
          return new PLYValueSwapFloat64();
        }

      default:
        break;
    }
  }
  else if (encoding == ply_little_endian)
  {
    switch (type)
    {
      case ply_int8:
        return new PLYValueInt8();

      case ply_uint8:
        return new PLYValueUInt8();

      case ply_int16:
        return new PLYValueLittleInt16();

      case ply_uint16:
        return new PLYValueLittleUInt16();

      case ply_int32:
        return new PLYValueLittleInt32();

      case ply_uint32:
        return new PLYValueLittleUInt32();

      case ply_float32:
        if (gutil::isMSBFirst())
        {
          return new PLYValueSwapFloat32();
        }
        else
        {
          return new PLYValueFloat32();
        }

      case ply_float64:
        if (gutil::isMSBFirst())
        {
          return new PLYValueSwapFloat64();
        }
        else
        {
          return new PLYValueFloat64();
        }

      default:
        break;
    }
  }

  assert(false);

  return 0;
}