MaybeError CommandEncoder::ValidateFinish(CommandIterator* commands,
                                              const PerPassUsages& perPassUsages) const {
        TRACE_EVENT0(GetDevice()->GetPlatform(), Validation, "CommandEncoder::ValidateFinish");
        DAWN_TRY(GetDevice()->ValidateObject(this));

        for (const PassResourceUsage& passUsage : perPassUsages) {
            DAWN_TRY(ValidatePassResourceUsage(passUsage));
        }

        uint64_t debugGroupStackSize = 0;

        commands->Reset();
        Command type;
        while (commands->NextCommandId(&type)) {
            switch (type) {
                case Command::BeginComputePass: {
                    commands->NextCommand<BeginComputePassCmd>();
                    DAWN_TRY(ValidateComputePass(commands));
                    break;
                }

                case Command::BeginRenderPass: {
                    const BeginRenderPassCmd* cmd = commands->NextCommand<BeginRenderPassCmd>();
                    DAWN_TRY(ValidateRenderPass(commands, cmd));
                    break;
                }

                case Command::CopyBufferToBuffer: {
                    commands->NextCommand<CopyBufferToBufferCmd>();
                    break;
                }

                case Command::CopyBufferToTexture: {
                    commands->NextCommand<CopyBufferToTextureCmd>();
                    break;
                }

                case Command::CopyTextureToBuffer: {
                    commands->NextCommand<CopyTextureToBufferCmd>();
                    break;
                }

                case Command::CopyTextureToTexture: {
                    commands->NextCommand<CopyTextureToTextureCmd>();
                    break;
                }

                case Command::InsertDebugMarker: {
                    const InsertDebugMarkerCmd* cmd = commands->NextCommand<InsertDebugMarkerCmd>();
                    commands->NextData<char>(cmd->length + 1);
                    break;
                }

                case Command::PopDebugGroup: {
                    commands->NextCommand<PopDebugGroupCmd>();
                    DAWN_TRY(ValidateCanPopDebugGroup(debugGroupStackSize));
                    debugGroupStackSize--;
                    break;
                }

                case Command::PushDebugGroup: {
                    const PushDebugGroupCmd* cmd = commands->NextCommand<PushDebugGroupCmd>();
                    commands->NextData<char>(cmd->length + 1);
                    debugGroupStackSize++;
                    break;
                }

                case Command::ResolveQuerySet: {
                    commands->NextCommand<ResolveQuerySetCmd>();
                    break;
                }

                case Command::WriteTimestamp: {
                    commands->NextCommand<WriteTimestampCmd>();
                    break;
                }
                default:
                    return DAWN_VALIDATION_ERROR("Command disallowed outside of a pass");
            }
        }

        DAWN_TRY(ValidateFinalDebugGroupStackSize(debugGroupStackSize));

        return {};
    }