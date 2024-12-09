Pose GetAdditiveBasePoseFromAdditiveClip(Skeleton& skeleton, const Clip& additiveClip)
{
   Pose additiveBasePose = skeleton.GetRestPose();
   additiveClip.Sample(additiveBasePose, additiveClip.GetStartTime());
   return additiveBasePose;
}