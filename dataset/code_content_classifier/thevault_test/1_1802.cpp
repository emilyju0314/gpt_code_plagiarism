void FABRIKSolver::IterateBackward(const glm::vec3& goalPos)
{
   int numJoints = static_cast<int>(GetNumberOfJointsInIKChain());

   // Move the end effector to where the goal is
   if (numJoints > 0)
   {
      mWorldPositionsChain[numJoints - 1] = goalPos;
   }

   // Loop backwards over the joints in the IK chain, starting with the one that comes before the end effector
   for (int i = numJoints - 2; i >= 0; --i)
   {
      // Calculate a vector that goes from the current joint to the next one
      glm::vec3 dirToNext = normalizeWithZeroLengthCheck(mWorldPositionsChain[i + 1] - mWorldPositionsChain[i]);
      // mDistancesBetweenJoints contains the distance between each joint and its parent,
      // so the distance between the current joint and the next one is stored in the index of the next one (mDistancesBetweenJoints[i + 1])
      float distToNext = mDistancesBetweenJoints[i + 1];

      // To move the current joint towards the next one while preserving the original distance between them, we would need to calculate that distance as follows:
      //
      // float distToMove = glm::length(mWorldPositionsChain[i + 1] - mWorldPositionsChain[i]) - distToNext;
      //
      // We can avoid doing that calculation by moving the next joint towards the current one, in which case distToMove is equal to distToNext
      // That's what we do below, but note how dirToNext is negated, since we calculated it as a vector that goes from the current joint to the next one,
      // and we want move in the opposite direction
      mWorldPositionsChain[i] = mWorldPositionsChain[i + 1] - (dirToNext * distToNext);
   }
}