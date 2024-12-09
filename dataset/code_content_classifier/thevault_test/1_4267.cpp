bool intersects(const ImpactZone &z1, const ImpactZone &z2)
{
    std::set<int> temp;
    set_intersection(z1.m_verts.begin(), z1.m_verts.end(), z2.m_verts.begin(), z2.m_verts.end(), inserter(temp, temp.end()));
    return temp.size() > 0;
}