inline
btTransform transformToBullet(const geometry_msgs::msg::TransformStamped & t)
{
  return btTransform(
    btQuaternion(
      static_cast<float>(t.transform.rotation.x),
      static_cast<float>(t.transform.rotation.y),
      static_cast<float>(t.transform.rotation.z),
      static_cast<float>(t.transform.rotation.w)),
    btVector3(
      static_cast<float>(t.transform.translation.x),
      static_cast<float>(t.transform.translation.y),
      static_cast<float>(t.transform.translation.z)));
}