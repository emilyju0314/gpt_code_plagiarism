void Dsettings :: update()
{
    assert(is_powerOf2(numChannels));
    assert(is_powerOf2(numRanks));
    assert(is_powerOf2(numBanks));
    assert(is_powerOf2(numRows));
    assert(is_powerOf2(numColumns));

    this->numDatabusPackets = (int) ((this->llcacheLineSizeBytes*8)/this->channelBitWidth);

    this->t_RC = this->t_RAS + this->t_RP;
    this->t_RTP = this->t_RAS - this->t_RCD;
    this->t_CWD = (this->t_CAS - 1);
    this->t_RFC = this->numRows*(this->t_RC);

    this->rowShiftBits = (int) (myLog2(this->numColumns));
    this->bankShiftBits = ((int) (myLog2(this->numRows))) + this->rowShiftBits;
    this->rankShiftBits = ((int) (myLog2(this->numBanks))) + this->bankShiftBits;
    this->channelShiftBits = ((int) (myLog2(this->numRanks))) + this->rankShiftBits;
    //this->rowMask = this->getMask(this->numRows);
    //this->bankMask = this->getMask(this->numBanks);
    //this->rankMask = this->getMask(this->numRanks);

    this->rowMask = this->getMask(myLog2(this->numRows));
    this->bankMask = this->getMask(myLog2(this->numBanks));
    this->rankMask = this->getMask(myLog2(this->numRanks));
}