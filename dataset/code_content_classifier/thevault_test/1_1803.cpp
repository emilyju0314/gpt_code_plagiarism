void FABRIKSolver::IterateForward(const glm::vec3& oriPosOfRoot)
{
   int numJoints = static_cast<int>(GetNumberOfJointsInIKChain());

   // Move the root to its original position
   if (numJoints > 0)
   {
      mWorldPositionsChain[0] = oriPosOfRoot;
   }

   // Loop forwards over the joints in the IK chain, starting with the one that comes after the root
   for (int i = 1; i < numJoints; ++i)
   {
      // Calculate a vector that goes from the current joint to the previous one
      glm::vec3 dirToPrev = normalizeWithZeroLengthCheck(mWorldPositionsChain[i - 1] - mWorldPositionsChain[i]);
      // mDistancesBetweenJoints contains the distance between each joint and its parent,
      // so the distance between the current joint and the previous one is stored in the index of the current one (mDistancesBetweenJoints[i])
      float distToPrev = mDistancesBetweenJoints[i];

      // To move the current joint towards the previous one while preserving the original distance between them, we would need to calculate that distance as follows:
      //
      // float distToMove = glm::length(mWorldPositionsChain[i - 1] - mWorldPositionsChain[i]) - distToPrev;
      //
      // We can avoid doing that calculation by moving the previous joint towards the current one, in which case distToMove is equal to distToPrev
      // That's what we do below, but note how dirToPrev is negated, since we calculated it as a vector that goes from the current joint to the previous one,
      // and we want move in the opposite direction
      mWorldPositionsChain[i] = mWorldPositionsChain[i - 1] - (dirToPrev * distToPrev);
   }
}