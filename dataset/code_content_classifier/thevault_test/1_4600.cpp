void Data(MicroBitEvent e)
{
    //Takes data sent from Sender and stores it in a variable
    ManagedString dataFromSender = uBit.radio.datagram.recv();

    //If-statement issued to display correct corossponding values
    if (dataFromSender == "1")
    {
        uBit.display.print(".");
    }
    else if (dataFromSender == "2")
    {
        uBit.display.print("-");
    }

    //Delay duration given for the Micro:bit to go to sleep
    uBit.sleep(500);
    //Clears the screen after delay is done
    uBit.display.clear();
}