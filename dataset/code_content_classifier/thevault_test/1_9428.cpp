Vertex(VertexAttributeBitmask attribs, const vec3& p, const vec3& n,
           const vec4& t, const vec4& q, const vec4& c,
           const vec2& u, const vec2& v, const SkinBinding& skin_binding)
        : vertex(attribs & kVertexAttributeBit_Position ? p : kZeros3f),
          normal(attribs & kVertexAttributeBit_Normal ? n : kZeros3f),
          tangent(attribs & kVertexAttributeBit_Tangent ? t : kZeros4f),
          orientation(attribs & kVertexAttributeBit_Orientation ? q : kZeros4f),
          uv(attribs & kVertexAttributeBit_Uv ? u : kZeros2f),
          uv_alt(attribs & kVertexAttributeBit_UvAlt ? v : kZeros2f),
          color(attribs & kVertexAttributeBit_Color ? FlatBufferVec4ub(c)
                                                    : Vec4ub(0, 0, 0, 0)) {
      if (attribs & kVertexAttributeBit_Bone) this->skin_binding = skin_binding;
    }