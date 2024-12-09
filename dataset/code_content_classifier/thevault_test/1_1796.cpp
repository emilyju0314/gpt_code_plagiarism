std::vector<AnimatedMesh> LoadAnimatedMeshes(cgltf_data* data)
{
   std::vector<AnimatedMesh> animatedMeshes;

   // Loop over the array of nodes of the glTF file
   unsigned int numNodes = static_cast<unsigned int>(data->nodes_count);
   for (unsigned int nodeIndex = 0; nodeIndex < numNodes; ++nodeIndex)
   {
      // This function only loads animated meshes, so the node must contain a mesh and a skin for us to process it
      cgltf_node* currNode = &data->nodes[nodeIndex];
      if (currNode->mesh == nullptr || currNode->skin == nullptr)
      {
         continue;
      }

      // Loop over the array of mesh primitives of the current node
      unsigned int numPrimitives = static_cast<unsigned int>(currNode->mesh->primitives_count);
      for (unsigned int primitiveIndex = 0; primitiveIndex < numPrimitives; ++primitiveIndex)
      {
         // Get the current mesh primitive
         cgltf_primitive* currPrimitive = &currNode->mesh->primitives[primitiveIndex];

         // Create an AnimatedMesh for the current mesh primitive
         animatedMeshes.push_back(AnimatedMesh());
         AnimatedMesh& currMesh = animatedMeshes[animatedMeshes.size() - 1];

         // Loop over the attributes of the current mesh primitive
         unsigned int numAttributes = static_cast<unsigned int>(currPrimitive->attributes_count);
         for (unsigned int attributeIndex = 0; attributeIndex < numAttributes; ++attributeIndex)
         {
            // Get the current attribute
            cgltf_attribute* attribute = &currPrimitive->attributes[attributeIndex];
            // Read the values of the current attribute and store them in the current mesh
            GLTFHelpers::StoreValuesOfAttributeInAnimatedMesh(*attribute, currNode->skin, data->nodes, numNodes, currMesh);
         }

         // If the current mesh primitive has a set of indices, store them too
         if (currPrimitive->indices != nullptr)
         {
            unsigned int indexCount = static_cast<unsigned int>(currPrimitive->indices->count);

            // Get the vector that will store the indices of the current mesh
            std::vector<unsigned int>& indices = currMesh.GetIndices();
            indices.resize(indexCount);

            // Loop over the indices of the current mesh primitive
            for (unsigned int i = 0; i < indexCount; ++i)
            {
               indices[i] = static_cast<unsigned int>(cgltf_accessor_read_index(currPrimitive->indices, i));
            }
         }

         // TODO: Perhaps we shouldn't do this here. The user should choose when this is done
         // Once we are done loading the current mesh, we load its VBOs with the data that we read
         currMesh.LoadBuffers();
      }
   }

   return animatedMeshes;
}