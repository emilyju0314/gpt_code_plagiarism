int
CBQClass::ancestor(CBQClass *p)
{
	if (!p->permit_borrowing_ || p->lender_ == NULL)
		return (0);
	else if (p->lender_ == this)
		return (1);
	return (ancestor(p->lender_));
}