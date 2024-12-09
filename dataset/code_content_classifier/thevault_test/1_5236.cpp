bool ts::TablesLogger::AnalyzeUDPMessage(const uint8_t* data, size_t size, bool no_encapsulation, SectionPtrVector& sections, Time& timestamp)
{
    // Clear output parameters.
    sections.clear();
    timestamp = Time::Epoch;

    // Filter invalid parameters.
    if (data == nullptr) {
        return false;
    }

    Variable<SimulCryptDate> scDate;
    Variable<PID> pid;

    if (no_encapsulation) {

        // Raw sections in UDP packets.
        // Loop on sections in the packet.
        while (size > 0) {
            const size_t sect_size = Section::SectionSize(data, size);
            assert(sect_size <= size);
            if (sect_size == 0) {
                return false;
            }
            const SectionPtr section(new Section(data, sect_size, ts::PID_NULL, ts::CRC32::CHECK));
            if (!section->isValid()) {
                return false;
            }
            sections.push_back(section);
            data += sect_size;
            size -= sect_size;
        }
    }
    else {
        // TLV messages in UDP packets. Decode the message.
        tlv::MessageFactory mf(data, size, duck::Protocol::Instance());
        tlv::MessagePtr msg(mf.factory());

        // We expected only two possible messages:
        const duck::LogSection* logSection = dynamic_cast<const duck::LogSection*>(msg.pointer());
        const duck::LogTable* logTable = dynamic_cast<const duck::LogTable*>(msg.pointer());

        if (logSection != nullptr) {
            scDate = logSection->timestamp;
            pid = logSection->pid;
            if (logSection->section.isNull() || !logSection->section->isValid()) {
                return false;
            }
            else {
                sections.push_back(logSection->section);
            }
        }
        else if (logTable != nullptr) {
            scDate = logTable->timestamp;
            pid = logTable->pid;
            sections = logTable->sections;
        }
        else {
            return false;
        }
    }

    // Set the PID in all sections.
    if (pid.set()) {
        for (SectionPtrVector::const_iterator it = sections.begin(); it != sections.end(); ++it) {
            if (!it->isNull()) {
                (*it)->setSourcePID(pid.value());
            }
        }
    }

    // Interpret the timestamp.
    if (scDate.set()) {
        try {
            timestamp = Time(scDate.value());
        }
        catch (...) {
            timestamp = Time::Epoch;
        }
    }

    return true;
}