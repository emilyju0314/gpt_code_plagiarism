void FABRIKSolver::WorldToIKChain()
{
   unsigned int numJoints = GetNumberOfJointsInIKChain();

   // Loop over the joints in the IK chain
   for (unsigned int jointIndex = 0; jointIndex < numJoints - 1; ++jointIndex)
   {
      // Get the unsolved global transforms of the current joint and the next one
      Transform originalWorldTransfOfCurrJoint = GetGlobalTransform(jointIndex);
      Transform originalWorldTransfOfNextJoint = GetGlobalTransform(jointIndex + 1);

      // Get the unsolved world position and rotation of the current joint
      glm::vec3 originalWorldPosOfCurrJoint = originalWorldTransfOfCurrJoint.position;
      Q::quat   originalWorldRotOfCurrJoint = originalWorldTransfOfCurrJoint.rotation;

      // Calculate a vector that goes from the unsolved world position of the current joint to the unsolved world position of the next joint
      glm::vec3 toNext = originalWorldTransfOfNextJoint.position - originalWorldPosOfCurrJoint;
      // Calculate a vector that goes from the unsolved world position of the current joint to the solved world position of the next joint
      glm::vec3 toDesired = mWorldPositionsChain[jointIndex + 1] - originalWorldPosOfCurrJoint;

      // NOTE: The quaternion operations below are reversed because q * p is implemented as p * q

      /*
         The rotation that goes from toNext to toDesired is the rotation that we need to apply to the current joint to achieve the solved pose
         Since toNext and toDesired are world space vectors, the rotation below is a world rotation:

            Q::quat worldDelta = Q::fromTo(toNext, toDesired);

         To apply worldDelta to the world rotation of the current joint we must multiply it on the right, since it's a world rotation:

            Q::quat newWorldRotOfCurrJoint = originalWorldRotOfCurrJoint * worldDelta;

         Finally, we must convert newWorldRotOfCurrJoint into a local rotation so that we can store it in mIKChain
         We can do that as follows:

            Q::quat newLocalRotOfCurrJoint = newWorldRotOfCurrJoint;
            if (i > 0)
            {
               // Here we multiply the new global rotation of the current joint with the inverse of the global rotation of its parent,
               // which leaves us with the new local rotation of the current joint
               newLocalRotOfCurrJoint = newWorldRotOfCurrJoint * Q::inverse(GetGlobalTransform(i - 1).rotation);
            }

         To understand the code above, imagine if the local transforms in our IK chain looked like this:

            (root) D ---- C
                          |
                          |
                          B ---- A'

         Where the new local transform of the current joint is A',
         and where the new global transform of the current joint is (D * C * B * A')
         You can think of the last quaternion multiplication that we performed above in this way (in standard notation i.e. q * p is not implemented as p * q):

            newLocalRotOfCurrJoint =  Q::inverse(GetGlobalTransform(i - 1).rotation) * newWorldRotOfCurrJoint = (D * C * B)^-1 * (D * C * B * A') = (B^-1 * C^-1 * D^-1) * (D * C * B * A') = A'

         Note that the if-statement is necessary because the root doesn't have a parent, so its world rotation is the same as its local rotation

         The problem with the code above is that it requires us to calculate the global transform of the current joint's parent, which is expensive
         We can avoid doing that with this approach:

            // Here we take toNext and toDesired from world space into the local space of the current joint by
            // multiplying them with the inverse of the world rotation of the current joint
            toNext = Q::inverse(originalWorldRotOfCurrJoint) * toNext;
            toDesired = Q::inverse(originalWorldRotOfCurrJoint) * toDesired;

            // With the vectors in the local space of the current joint, we can now calculate the local rotation that goes from toNext to toDesired
            Q::quat localDelta = Q::fromTo(toNext, toDesired);

            // Finally, we can apply the local rotation to the rotation of the current joint to achieve the solved pose
            // Note how we multiply it on the left, since it's a local rotation
            Q::quat newLocalRotOfCurrJoint = localDelta * mIKChain[jointIndex].rotation;

         That's the approach that's implemented below
      */

      // We want to use the two vectors that we calculated above to determine the local rotation that we must apply to the current joint to achieve the solved pose
      // Since we want to determine the necessary LOCAL rotation, we must multiply both vectors by the inverse of the world rotation of the current joint,
      // which takes them from world space to the local space of the current joint
      toNext = Q::inverse(originalWorldRotOfCurrJoint) * toNext;
      toDesired = Q::inverse(originalWorldRotOfCurrJoint) * toDesired;

      // With the vectors in the local space of the current joint, we can now calculate the local rotation that goes from toNext to toDesired
      Q::quat localDelta = Q::fromTo(toNext, toDesired);

      // Finally, we can apply the local rotation to the rotation of the current joint to achieve the solved pose
      mIKChain[jointIndex].rotation = localDelta * mIKChain[jointIndex].rotation;
   }
}