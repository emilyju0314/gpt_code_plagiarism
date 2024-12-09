void AdditiveBlend(const Pose& animatedPose, const Pose& additivePose, const Pose& additiveBasePose, int blendRoot, Pose& outBlendedPose)
{
   unsigned int numJoints = additivePose.GetNumberOfJoints();

   // When the user wants to blend all the joints of the two poses, they pass a negative blendRoot (typically -1)
   // If that's the case, we don't need to perform a hierarchy check while looping over the joints
   if (blendRoot < 0)
   {
      for (unsigned int jointIndex = 0; jointIndex < numJoints; ++jointIndex)
      {
         Transform animated     = animatedPose.GetLocalTransform(jointIndex);
         Transform additive     = additivePose.GetLocalTransform(jointIndex);
         Transform additiveBase = additiveBasePose.GetLocalTransform(jointIndex);

         // Combine the position, rotation and scale of the transforms using the additive blending formula:
         // outBlendedPose = animatedPose + (additivePose - additiveBasePose)
         glm::vec3 position = animated.position + (additive.position - additiveBase.position);
         glm::vec3 scale = animated.scale + (additive.scale - additiveBase.scale);
         // NOTE: Reversed because q * p is implemented as p * q
         Q::quat rotation = normalized(animated.rotation * (Q::inverse(additiveBase.rotation) * additive.rotation));

         outBlendedPose.SetLocalTransform(jointIndex, Transform(position, rotation, scale));
      }
   }
   else
   {
      for (unsigned int jointIndex = 0; jointIndex < numJoints; ++jointIndex)
      {
         // If the current joint is not in the hierarchy of the blendRoot, we don't blend it
         if (!IsJointInHierarchy(additivePose, blendRoot, jointIndex))
         {
            continue;
         }

         Transform animated     = animatedPose.GetLocalTransform(jointIndex);
         Transform additive     = additivePose.GetLocalTransform(jointIndex);
         Transform additiveBase = additiveBasePose.GetLocalTransform(jointIndex);

         // Combine the position, rotation and scale of the transforms using the additive blending formula:
         // outBlendedPose = animatedPose + (additivePose - additiveBasePose)
         glm::vec3 position = animated.position + (additive.position - additiveBase.position);
         glm::vec3 scale = animated.scale + (additive.scale - additiveBase.scale);
         // NOTE: Reversed because q * p is implemented as p * q
         Q::quat rotation = normalized(animated.rotation * (Q::inverse(additiveBase.rotation) * additive.rotation));

         outBlendedPose.SetLocalTransform(jointIndex, Transform(position, rotation, scale));
      }
   }
}