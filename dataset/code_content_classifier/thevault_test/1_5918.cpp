foreach (const Primitive::values_type::value_type& elt, content_)
      {
        if (elt.first >= arity)
          minAbove = std::min(minAbove, elt.first);
        if (elt.first <= arity)
          maxBelow = std::max(maxBelow, elt.first);
        min = std::min(min, elt.first);
        max = std::max(max, elt.first);
      }