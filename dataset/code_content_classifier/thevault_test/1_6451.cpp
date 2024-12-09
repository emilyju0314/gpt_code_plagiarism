double
Propagation::Pr(PacketStamp *, PacketStamp *, Phy *)
{
	fprintf(stderr,"Propagation model %s not implemented for generic NetIF\n",
	  name);
	abort();
	return 0; // Make msvc happy
}