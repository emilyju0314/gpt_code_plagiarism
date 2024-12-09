static RHI::BufferViewDescriptor CreateResourceViewWithDifferentFormat(size_t offsetInBytes, uint32_t realElementCount, uint32_t realElementSize,  RHI::Format format, RHI::BufferBindFlags overrideBindFlags)
        {
            RHI::BufferViewDescriptor viewDescriptor;
            size_t elementOffset = offsetInBytes / aznumeric_cast<size_t>(RHI::GetFormatSize(format));
            AZ_Assert(elementOffset <= std::numeric_limits<uint32_t>().max(), "The offset in bytes from the start of the SkinnedMeshOutputStream buffer is too large to be expressed as a uint32_t element offset in the BufferViewDescriptor.");
            viewDescriptor.m_elementOffset = aznumeric_cast<uint32_t>(elementOffset);

            viewDescriptor.m_elementCount = realElementCount * (realElementSize / RHI::GetFormatSize(format));
            viewDescriptor.m_elementFormat = format;
            viewDescriptor.m_elementSize = RHI::GetFormatSize(format);
            viewDescriptor.m_overrideBindFlags = overrideBindFlags;
            return viewDescriptor;
        }