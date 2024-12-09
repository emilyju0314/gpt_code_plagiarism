void GetFloatsFromAccessor(const cgltf_accessor& accessor, unsigned int componentCount, std::vector<float>& outValues)
   {
      outValues.resize(accessor.count * componentCount);

      for (cgltf_size i = 0; i < accessor.count; ++i)
      {
         cgltf_accessor_read_float(&accessor, i, &outValues[i * componentCount], componentCount);
      }
   }