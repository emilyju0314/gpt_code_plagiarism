void FABRIKSolver::IKChainToWorld()
{
   unsigned int numJoints = GetNumberOfJointsInIKChain();

   // Loop over the joints in the IK chain
   for (unsigned int jointIndex = 0; jointIndex < numJoints; ++jointIndex)
   {
      // Calculate the world position of the current joint and store it
      glm::vec3 worldPosOfCurrJoint = GetGlobalTransform(jointIndex).position;
      mWorldPositionsChain[jointIndex] = worldPosOfCurrJoint;

      // If the current joint has a parent (i.e. it's not the root joint), calculate the distance between it and its parent and store it
      if (jointIndex >= 1)
      {
         glm::vec3 worldPosOfPrevJoint = mWorldPositionsChain[jointIndex - 1];
         mDistancesBetweenJoints[jointIndex] = glm::length(worldPosOfCurrJoint - worldPosOfPrevJoint);
      }
   }

   // If the IK chain is not empty, set the distance between the root joint and its parent equal to 0.0f
   if (numJoints > 0)
   {
      mDistancesBetweenJoints[0] = 0.0f;
   }
}