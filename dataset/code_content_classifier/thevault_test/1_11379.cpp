void create_image(fitsfile *fits, std::vector<size_t> &shape, std::string name=std::string())
{
	int error(0);
	std::vector<long> naxes(shape.size());
	std::reverse_copy(shape.begin(), shape.end(), naxes.begin());
	fits_create_img(fits, FLOAT_IMG, shape.size(), &naxes[0], &error);
	if (error != 0) {
		log_fatal_stream("Could not create image: " << error_text(error));
	}
	if (name.size() > 0) {
		fits_write_key(fits, TSTRING, "EXTNAME", (void*)(name.c_str()),
		    NULL, &error);
	}
	if (error != 0) {
		log_fatal_stream("Could name HDU "<<name<<": " << error_text(error));
	}
}