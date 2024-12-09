CINO_INLINE
AABB::AABB(const std::vector<AABB> & list, const double scaling_factor)
{
    reset();
    push(list);
    if(scaling_factor!=1) scale(scaling_factor);
}