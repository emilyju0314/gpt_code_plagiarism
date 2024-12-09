Transform GetLocalTransformFromNode(const cgltf_node& node)
   {
      Transform localTransform;

      if (node.has_matrix)
      {
         localTransform = mat4ToTransform(glm::make_mat4(node.matrix));
      }

      if (node.has_translation)
      {
         localTransform.position = glm::vec3(node.translation[0], node.translation[1], node.translation[2]);
      }

      if (node.has_rotation)
      {
         localTransform.rotation = Q::quat(node.rotation[0], node.rotation[1], node.rotation[2], node.rotation[3]);
      }

      if (node.has_scale)
      {
         localTransform.scale = glm::vec3(node.scale[0], node.scale[1], node.scale[2]);
      }

      return localTransform;
   }