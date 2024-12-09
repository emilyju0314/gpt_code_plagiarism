void Send()
{
    //if statements checks button press, sends data and displays that data on display
    if (uBit.buttonA.isPressed())
    {
        uBit.radio.datagram.send("1");
        uBit.display.print(".");
    }

    else if (uBit.buttonB.isPressed())
    {
        uBit.radio.datagram.send("2");
        uBit.display.print("-");
    }

    uBit.sleep(500);
    uBit.display.clear();
}