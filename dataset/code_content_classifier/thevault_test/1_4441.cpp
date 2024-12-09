METAIO_STL::string MET_ReadType(METAIO_STREAM::istream &_fp)
  {
  METAIO_STL::streampos pos = _fp.tellg();
  METAIO_STL::vector<MET_FieldRecordType *> fields;
  MET_FieldRecordType* mF = new MET_FieldRecordType;
  MET_InitReadField(mF, "ObjectType", MET_STRING, false);
  mF->required = false;
  mF->terminateRead = true;
  fields.push_back(mF);

  MET_Read(_fp, &fields, '=', true);
  _fp.seekg(pos);

  METAIO_STL::string value;

  if(mF && mF->defined)
    {
    value = (char *)(mF->value);
    delete mF;
    return value;
    }

  value[0] = '\0';
  delete mF;
  return value;
  }