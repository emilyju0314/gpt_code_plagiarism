bool DoesRayIntersectTriangle(const Ray& ray, const Triangle& triangle, glm::vec3& hitPoint)
{
   // Calculate the denominator of the solved plane equation:
   // t = ((A dot N) - (origin dot N)) / (direction dot N)
   float rayDirDotNormal = glm::dot(ray.direction, triangle.normal);

   // If the ray is perpendicular to the normal of the triangle, the ray and the plane in which the triangle lies are parallel
   // TODO: Use constant here
   // NOTE: This check has been updated to also exclude triangles whose normal points in the same direction as the ray by adding this:
   //       rayDirDotNormal > 0
   //       When that is the case, the ray is hitting the backface of the triangle, which is why we want to ignore it
   if (rayDirDotNormal > 0 || glm::abs(rayDirDotNormal) < 0.0000001f)
   {
      return false;
   }

   // Evaluate the solved plane equation:
   // t = ((A dot N) - (origin dot N)) / (direction dot N)
   float distAlongRayToHit = (glm::dot(triangle.vertexA, triangle.normal) - glm::dot(ray.origin, triangle.normal)) / rayDirDotNormal;

   // If the distance along to the ray to the hit point is negative, the plane in which the triangle lies is behind the origin of the ray
   if (distAlongRayToHit < 0)
   {
      return false;
   }

   // Calculate the hit point
   hitPoint = (ray.direction * distAlongRayToHit) + ray.origin;

   // Check if P is to the left of each edge to determine if it lies inside the triangle
   /*
                C
               / \
              /   \
             /     \
            /   P   \
           /         \
          A-----------B
   */

   glm::vec3 normalOfTriABC = glm::cross((triangle.vertexB - triangle.vertexA), (triangle.vertexC - triangle.vertexA));

   // If P is to the left of edge (C - B), the normal of sub-triangle BCP will point in the same direction as the normal of triangle ABC
   // If P is to the right of edge (C - B), the normal of sub-triangle BCP will point in the opposite direction of the normal of triangle ABC
   glm::vec3 normalOfSubTri = glm::cross((triangle.vertexC - triangle.vertexB), (hitPoint - triangle.vertexB));
   if (dot(normalOfSubTri, normalOfTriABC) < 0)
   {
      return false; // P is to the right of edge (C - B)
   }

   // If P is to the left of edge (B - A), the normal of sub-triangle ABP will point in the same direction as the normal of triangle ABC
   // If P is to the right of edge (B - A), the normal of sub-triangle ABP will point in the opposite direction of the normal of triangle ABC
   normalOfSubTri = glm::cross((triangle.vertexB - triangle.vertexA), (hitPoint - triangle.vertexA));
   if (dot(normalOfSubTri, normalOfTriABC) < 0)
   {
      return false; // P is to the right of edge (B - A)
   }

   // If P is to the left of edge (A - C), the normal of sub-triangle CAP will point in the same direction as the normal of triangle ABC
   // If P is to the right of edge (A - C), the normal of sub-triangle CAP will point in the opposite direction of the normal of triangle ABC
   normalOfSubTri = glm::cross((triangle.vertexA - triangle.vertexC), (hitPoint - triangle.vertexC));
   if (dot(normalOfSubTri, normalOfTriABC) < 0)
   {
      return false; // P is to the right of edge (A - C)
   }

   // P lies inside triangle ABC
   return true;
}