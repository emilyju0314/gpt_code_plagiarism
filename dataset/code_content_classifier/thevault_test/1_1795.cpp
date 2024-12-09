Pose LoadBindPose(cgltf_data* data)
{
   // Initialize the global bind pose transforms with the global rest pose transforms
   // By doing this, we ensure that we have good default values if there are any skins that don't provide
   // inverse bind matrices for all of their joints
   Pose restPose = LoadRestPose(data);
   unsigned int numJointsOfPose = restPose.GetNumberOfJoints();
   std::vector<Transform> globalBindPoseTransforms(numJointsOfPose);
   for (unsigned int poseJointIndex = 0; poseJointIndex < numJointsOfPose; ++poseJointIndex)
   {
      globalBindPoseTransforms[poseJointIndex] = restPose.GetGlobalTransform(poseJointIndex);
   }

   // Loop over the array of skins of the glTF file
   unsigned int numSkins = static_cast<unsigned int>(data->skins_count);
   for (unsigned int skinIndex = 0; skinIndex < numSkins; ++skinIndex)
   {
      // Get the current skin
      cgltf_skin& skin = data->skins[skinIndex];

      // Get the global inverse bind matrices from the inverse bind matrices accessor of the current skin
      std::vector<float> globalInverseBindMatrices;
      GLTFHelpers::GetFloatsFromAccessor(*skin.inverse_bind_matrices, 16, globalInverseBindMatrices);

      // Loop over the array of joints of the current skin
      unsigned int numJointsOfSkin = (unsigned int)skin.joints_count;
      for (unsigned int skinJointIndex = 0; skinJointIndex < numJointsOfSkin; ++skinJointIndex)
      {
         // Get the global inverse bind matrix of the current joint
         glm::mat4 globalInverseBindMatrix = glm::make_mat4(&(globalInverseBindMatrices[skinJointIndex * 16]));

         // Invert the global inverse bind matrix to get the global bind matrix, then convert it into a transform
         Transform globalBindTransform = mat4ToTransform(glm::inverse(globalInverseBindMatrix));

         // Store the gloal bind transform at the index of the joint node it corresponds to
         cgltf_node* jointNode = skin.joints[skinJointIndex];
         int jointNodeIndex = GLTFHelpers::GetNodeIndex(jointNode, data->nodes, numJointsOfPose);
         globalBindPoseTransforms[jointNodeIndex] = globalBindTransform;
      }
   }

   // Convert the global bind pose into a local bind pose
   Pose bindPose = restPose;
   for (unsigned int poseJointIndex = 0; poseJointIndex < numJointsOfPose; ++poseJointIndex)
   {
      // Get the global bind transform of the current joint
      Transform transform = globalBindPoseTransforms[poseJointIndex];

      // If the current joint has a parent, bring the global bind transform into the space of that parent,
      // making it a local bind transform (i.e. a bind transform that's relative to the parent's bind transform)
      int parentIndex = bindPose.GetParent(poseJointIndex);
      if (parentIndex >= 0)
      {
         Transform parentTransform = globalBindPoseTransforms[parentIndex];

         /*
            Let's say our pose looks like this:

            (root) A ---- B        (root) 0 ---- 1
                          |                      |
                          |                      |
                          C ---- D               2 ---- 3

            Where A, B, C and D are the local transforms of the joints 0, 1, 2 and 3
            The global transform of joint 3 is composed like this:

               Global_3 = A * B * C * D

            The global transform of the parent of joint 3, which is joint 2, is composed like this:

               Global_2 = A * B * C

            If we only knew Global_3 and Global_2, how would we find the local transform of joint 3?
            It's simple. All we would need to do is combine the inverse of Global_2 with Global_3, which gives us:

               Local_3 = Inverse_Global_2 * Global_3 = (A * B * C)^-1 * (A * B * C * D) = D

            That's exactly what we do below
         */

         transform = combine(inverse(parentTransform), transform);
      }

      bindPose.SetLocalTransform(poseJointIndex, transform);
   }

   return bindPose;
}