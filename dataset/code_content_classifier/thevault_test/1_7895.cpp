void Phascii_FreeInstance(PHASCII_INSTANCE ph_inst)
{
	CONFIG_INSTANCE *ci;

	ci = (CONFIG_INSTANCE *) ph_inst;

	free_instance(ci->definition, ci->instance);

	free(ci);
}