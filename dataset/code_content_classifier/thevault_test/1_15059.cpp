void InsuranceContractEndGameShutDown()
{
	//Free up the memory allocated to the insurance payouts
	LaptopSaveInfo.pLifeInsurancePayouts.clear();
}