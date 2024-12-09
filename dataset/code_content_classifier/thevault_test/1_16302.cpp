void ElementObjectData::deserialize(std::istream& in)
    {
      SerUtil::deserialize(in, elIndex);
      SerUtil::deserialize(in, ithObject);
    }