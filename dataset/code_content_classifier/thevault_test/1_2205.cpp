Node::IntersectionInfo HitTestSingleNode(const Node* node, escher::ray4 local_ray,
                                         Node::IntersectionInfo parent_intersection) {
  // Bail if hit testing is suppressed or if the ray is clipped.
  if (node->hit_test_behavior() == ::fuchsia::ui::gfx::HitTestBehavior::kSuppress ||
      (node->clip_to_self() && node->ClipsRay(local_ray))) {
    return Node::IntersectionInfo{.did_hit = false, .continue_with_children = false};
  }

  return node->GetIntersection(local_ray, parent_intersection);
}