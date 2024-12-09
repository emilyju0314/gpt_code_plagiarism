std::vector<Clip> LoadClips(cgltf_data* data)
{
   unsigned int numNodes = static_cast<unsigned int>(data->nodes_count);
   unsigned int numClips = static_cast<unsigned int>(data->animations_count);

   std::vector<Clip> clips(numClips);

   // Loop over the array of animations of the glTF file
   for (unsigned int clipIndex = 0; clipIndex < numClips; ++clipIndex)
   {
      // Store the name of the current animation
      clips[clipIndex].SetName(data->animations[clipIndex].name);

      // Loop over the array of channels of the current animation
      unsigned int numChannels = static_cast<unsigned int>(data->animations[clipIndex].channels_count);
      for (unsigned int channelIndex = 0; channelIndex < numChannels; ++channelIndex)
      {
         // Get the current channel
         cgltf_animation_channel& channel = data->animations[clipIndex].channels[channelIndex];

         // Get the index of the node that the current channel targets
         int indexOfTargetNode = GLTFHelpers::GetNodeIndex(channel.target_node, data->nodes, numNodes);

         // Get a position, scale or rotation track from the channel depending on which of those values it animates
         // Note how we pass the index of the target node as a joint ID to the Clip class to get a TransformTrack
         // That's possible because all of our animation classes mirror the order of the nodes of the glTF file
         if (channel.target_path == cgltf_animation_path_type_translation)
         {
            VectorTrack& positionTrack = clips[clipIndex].GetTransformTrackOfJoint(indexOfTargetNode).GetPositionTrack();
            GLTFHelpers::GetTrackFromChannel<glm::vec3, 3>(channel, positionTrack);
         }
         else if (channel.target_path == cgltf_animation_path_type_scale)
         {
            VectorTrack& scaleTrack = clips[clipIndex].GetTransformTrackOfJoint(indexOfTargetNode).GetScaleTrack();
            GLTFHelpers::GetTrackFromChannel<glm::vec3, 3>(channel, scaleTrack);
         }
         else if (channel.target_path == cgltf_animation_path_type_rotation)
         {
            QuaternionTrack& rotationTrack = clips[clipIndex].GetTransformTrackOfJoint(indexOfTargetNode).GetRotationTrack();
            GLTFHelpers::GetTrackFromChannel<Q::quat, 4>(channel, rotationTrack);
         }
      }

      // Recalculate the duration of the current clip once all of its tracks have been loaded
      clips[clipIndex].RecalculateDuration();
   }

   return clips;
}