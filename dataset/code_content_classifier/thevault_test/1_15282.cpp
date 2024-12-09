NvU16 engine_ast::DependencyParams::getDependencyCount()
{
    NvU16 num_producers = 0;
    for (size_t cc = 0; cc < EngineType::num_elements(); ++cc)
    {
        if (cc == EngineTypeEnum::CPU || cc == EngineTypeEnum::SPLIT || cc == EngineTypeEnum::CONCATENATION)
        {
            // dont count cpu/emu ops as a producer of dla ops
            continue;
        }

        if (producer(cc).nodeAnnId() != -1)
        {
            num_producers++;
        }
    }
    // if a fused downstream op exists, then the combo is enabled in the reverse order -
    // thus the fused node becomes a signalling operation
    num_producers += fusedNode(IODirectionEnum::OUTPUT) ? 1 : 0;
    return num_producers;
}