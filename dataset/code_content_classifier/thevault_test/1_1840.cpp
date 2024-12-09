AffineRelation::Relation PresolveContext::GetAffineRelation(int ref) {
  AffineRelation::Relation r = affine_relations.Get(PositiveRef(ref));
  AffineRelation::Relation o = var_equiv_relations.Get(r.representative);
  r.representative = o.representative;
  if (o.coeff == -1) r.coeff = -r.coeff;
  if (!RefIsPositive(ref)) {
    r.coeff *= -1;
    r.offset *= -1;
  }
  return r;
}