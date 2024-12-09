int GetNodeIndex(cgltf_node* target, cgltf_node* nodes, unsigned int numNodes)
   {
      if (target == nullptr)
      {
         return -1;
      }

      for (unsigned int nodeIndex = 0; nodeIndex < numNodes; ++nodeIndex)
      {
         if (target == &nodes[nodeIndex])
         {
            return static_cast<int>(nodeIndex);
         }
      }

      return -1;
   }