asf::DictionaryArray
BrlcadObjectFactory::get_input_metadata() const
{
    asf::DictionaryArray metadata;

    metadata.push_back(
	asf::Dictionary()
	.insert("name", "radius")
	.insert("label", "Radius")
	.insert("type", "numeric")
	.insert("min",
		asf::Dictionary()
		.insert("value", "0.0")
		.insert("type", "hard"))
	.insert("max",
		asf::Dictionary()
		.insert("value", "10.0")
		.insert("type", "soft"))
	.insert("use", "optional")
	.insert("default", "1.0"));

    return metadata;
}