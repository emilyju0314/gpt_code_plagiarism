std::vector<Triangle> GetTrianglesFromMeshes(std::vector<AnimatedMesh>& meshes)
{
   std::vector<Triangle> triangles;

   // Loop over the meshes
   unsigned int numMeshes = static_cast<unsigned int>(meshes.size());
   for (unsigned int meshIndex = 0; meshIndex < numMeshes; ++meshIndex)
   {
      AnimatedMesh&             mesh      = meshes[meshIndex];
      std::vector<glm::vec3>    positions = mesh.GetPositions();
      std::vector<unsigned int> indices   = mesh.GetIndices();

      if (indices.size() == 0)
      {
         // If the current mesh doesn't have indices, each sequential set of 3 positions makes up a triangle
         unsigned int numPositions = static_cast<unsigned int>(positions.size());
         for (unsigned int i = 0; i < numPositions; i += 3)
         {
            triangles.push_back(Triangle(positions[i + 0],
                                         positions[i + 1],
                                         positions[i + 2]));
         }
      }
      else
      {
         // If the current mesh has indices, each sequential set of 3 indices makes up a triangle
         unsigned int numIndices = static_cast<unsigned int>(indices.size());
         for (unsigned int i = 0; i < numIndices; i += 3)
         {
            triangles.push_back(Triangle(positions[indices[i + 0]],
                                         positions[indices[i + 1]],
                                         positions[indices[i + 2]]));
         }
      }
   }

   return triangles;
}