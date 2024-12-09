auto BlockHeaderRepository::getHashById(const primitives::BlockId &id) const
      -> outcome::result<base::Hash256> {
    return visit_in_place(
        id,
        [this](const primitives::BlockNumber &n) { return getHashByNumber(n); },
        [](const base::Hash256 &hash) { return hash; });
  }