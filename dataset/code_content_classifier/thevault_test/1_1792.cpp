void StoreValuesOfAttributeInAnimatedMesh(cgltf_attribute& attribute, cgltf_skin* skin, cgltf_node* nodes, unsigned int nodeCount, AnimatedMesh& outMesh)
   {
      // Get the accessor of the attribute and its component count
      cgltf_accessor& accessor = *attribute.data;
      unsigned int componentCount = 0;
      if (accessor.type == cgltf_type_vec2)
      {
         componentCount = 2;
      }
      else if (accessor.type == cgltf_type_vec3)
      {
         componentCount = 3;
      }
      else if (accessor.type == cgltf_type_vec4)
      {
         componentCount = 4;
      }

      // Read the floats from the accessor
      std::vector<float> attributeFloats;
      GetFloatsFromAccessor(accessor, componentCount, attributeFloats);

      // Get the vectors that will store the attributes of the mesh that we are loading
      // In each call to this function we only fill one of these, since a cgltf_attribute only describes one attribute
      std::vector<glm::vec3>&  positions  = outMesh.GetPositions();
      std::vector<glm::vec3>&  normals    = outMesh.GetNormals();
      std::vector<glm::vec2>&  texCoords  = outMesh.GetTexCoords();
      std::vector<glm::ivec4>& influences = outMesh.GetInfluences();
      std::vector<glm::vec4>&  weights    = outMesh.GetWeights();

      // Loop over all the values of the accessor
      // Note that accessor.count is not equal to the number of floats in the accessor
      // It's equal to the number of attribute values (e.g, vec2s, vec3s, vec4s, etc.) in the accessor
      cgltf_attribute_type attributeType = attribute.type;
      unsigned int numAttributeValues = static_cast<unsigned int>(accessor.count);
      for (unsigned int attributeValueIndex = 0; attributeValueIndex < numAttributeValues; ++attributeValueIndex)
      {
         // Store the current attribute value in the correct vector of the mesh
         // TODO: This looks inefficient. I think it would be better to have separate for loops inside if-statements
         //       Since this function only loads one attribute type when it's called, it doesn't make sense to check
         //       the attribute type in each iteration of this loop
         int indexOfFirstFloatOfCurrAttribValue = attributeValueIndex * componentCount;
         switch (attributeType)
         {
         case cgltf_attribute_type_position:
            // Store a position vec3
            positions.push_back(glm::vec3(attributeFloats[indexOfFirstFloatOfCurrAttribValue + 0],
                                          attributeFloats[indexOfFirstFloatOfCurrAttribValue + 1],
                                          attributeFloats[indexOfFirstFloatOfCurrAttribValue + 2]));
            break;
         case cgltf_attribute_type_texcoord:
            // Store a texture coordinates vec2
            texCoords.push_back(glm::vec2(attributeFloats[indexOfFirstFloatOfCurrAttribValue + 0],
                                          attributeFloats[indexOfFirstFloatOfCurrAttribValue + 1]));
            break;
         case cgltf_attribute_type_weights:
            // Store a weights vec4
            weights.push_back(glm::vec4(attributeFloats[indexOfFirstFloatOfCurrAttribValue + 0],
                                        attributeFloats[indexOfFirstFloatOfCurrAttribValue + 1],
                                        attributeFloats[indexOfFirstFloatOfCurrAttribValue + 2],
                                        attributeFloats[indexOfFirstFloatOfCurrAttribValue + 3]));
            break;
         case cgltf_attribute_type_normal:
         {
            // Store a normal vec3
            glm::vec3 normal = glm::vec3(attributeFloats[indexOfFirstFloatOfCurrAttribValue + 0],
                                         attributeFloats[indexOfFirstFloatOfCurrAttribValue + 1],
                                         attributeFloats[indexOfFirstFloatOfCurrAttribValue + 2]);

            // TODO: Use a constant here and add an error message
            if (glm::length2(normal) < 0.000001f)
            {
               normal = glm::vec3(0, 1, 0);
            }

            normals.push_back(glm::normalize(normal));
         }
         break;
         case cgltf_attribute_type_joints:
         {
            // Store an influences ivec4
            // Remember that in this function we are processing a node that has a mesh and a skin,
            // so the indices we are storing below are indices into the array of nodes of the skin,
            // not indices into the array of nodes of the glTF file, so we need to convert them from being
            // skin-relative to being file-relative

            // Note that we read the ints below as floats using the GetFloatsFromAccessor function,
            // so we need to convert them into ints
            // Why do we add 0.5 before casting? Because if an index is stored as 1.999999999999943157,
            // it will be truncated into being equal to 1 instead of 2 by the cast
            glm::ivec4 jointsIndices(static_cast<int>(attributeFloats[indexOfFirstFloatOfCurrAttribValue + 0] + 0.5f),
                                     static_cast<int>(attributeFloats[indexOfFirstFloatOfCurrAttribValue + 1] + 0.5f),
                                     static_cast<int>(attributeFloats[indexOfFirstFloatOfCurrAttribValue + 2] + 0.5f),
                                     static_cast<int>(attributeFloats[indexOfFirstFloatOfCurrAttribValue + 3] + 0.5f));

            // TODO: Display error for negative indices
            // Convert the indices from being skin-relative to being file-relative
            // and store negative indices as zeroes
            jointsIndices.x = std::max(0, GetNodeIndex(skin->joints[jointsIndices.x], nodes, nodeCount));
            jointsIndices.y = std::max(0, GetNodeIndex(skin->joints[jointsIndices.y], nodes, nodeCount));
            jointsIndices.z = std::max(0, GetNodeIndex(skin->joints[jointsIndices.z], nodes, nodeCount));
            jointsIndices.w = std::max(0, GetNodeIndex(skin->joints[jointsIndices.w], nodes, nodeCount));

            influences.push_back(jointsIndices);
         }
         break;
         case cgltf_attribute_type_invalid:
         case cgltf_attribute_type_tangent:
         case cgltf_attribute_type_color:
            break;
         }
      }
   }