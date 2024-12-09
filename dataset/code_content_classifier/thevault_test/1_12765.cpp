void Geometry::pack(BinaryFile& bf)
{
	int version=1; // version 1: geometry. 
	bf.packInt(version);
	bf.packInt(elements.size());
	for (int i=0; i<elements.size(); i++)
	{
		bf.packInt(elements[i].elementType);
		bf.pack( elements[i].elementSize );
		bf.pack( elements[i].tf.rotation);
		bf.pack( elements[i].tf.translation);
		bf.packInt( faceGroups.start(i));
		bf.packInt( faceGroups.end(i));
	}
	Mesh::pack(bf);
}