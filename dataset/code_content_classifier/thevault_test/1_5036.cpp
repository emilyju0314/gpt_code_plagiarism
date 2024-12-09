void ts::SDT::Service::setType(uint8_t service_type)
{
    // Locate the service descriptor
    const size_t index(descs.search(DID_SERVICE));

    if (index >= descs.count() || descs[index]->payloadSize() < 2) {
        // No valid service_descriptor, add a new one.
        ByteBlock data(5);
        data[0] = DID_SERVICE;  // tag
        data[1] = 3;            // descriptor length
        data[2] = service_type;
        data[3] = 0;            // provider name length
        data[4] = 0;            // service name length
        descs.add(DescriptorPtr(new Descriptor(data)));
    }
    else if (descs[index]->payloadSize() > 0) {
        // Replace service type in existing descriptor
        uint8_t* payload = descs[index]->payload();
        payload[0] = service_type;
    }
}