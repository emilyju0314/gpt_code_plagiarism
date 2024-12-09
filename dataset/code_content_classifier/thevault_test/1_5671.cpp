void Slot::set(const Slot & orig, int charOffset, size_t sizeAttr, size_t justLevels, size_t numChars)
{
    // leave m_next and m_prev unchanged
    m_glyphid = orig.m_glyphid;
    m_realglyphid = orig.m_realglyphid;
    m_original = orig.m_original + charOffset;
    if (charOffset + int(orig.m_before) < 0)
        m_before = 0;
    else
        m_before = orig.m_before + charOffset;
    if (charOffset <= 0 && orig.m_after + charOffset >= numChars)
        m_after = int(numChars) - 1;
    else
        m_after = orig.m_after + charOffset;
    m_parent = NULL;
    m_child = NULL;
    m_sibling = NULL;
    m_position = orig.m_position;
    m_shift = orig.m_shift;
    m_advance = orig.m_advance;
    m_attach = orig.m_attach;
    m_with = orig.m_with;
    m_flags = orig.m_flags;
    m_attLevel = orig.m_attLevel;
    m_bidiCls = orig.m_bidiCls;
    m_bidiLevel = orig.m_bidiLevel;
    if (m_userAttr && orig.m_userAttr)
        memcpy(m_userAttr, orig.m_userAttr, sizeAttr * sizeof(*m_userAttr));
    if (m_justs && orig.m_justs)
        memcpy(m_justs, orig.m_justs, SlotJustify::size_of(justLevels));
}