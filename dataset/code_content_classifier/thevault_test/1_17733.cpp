int radioSetup(struct Container *container, struct Args *args)
{
	if (args->debugEnabled)
		std::cout << "Setting up radio transceiver..." << std::endl;

	container->rf = new ORF24(21);
	ORF24 *rf = container->rf;

	if (args->debugEnabled)
		rf->enableDebug();

	rf->begin();
	rf->setPayloadSize(1);
	rf->setChannel(76);
	rf->setCRCLength(CRC_2_BYTE);
	rf->setPowerLevel(RF_PA_HIGH);

	return 0;
}