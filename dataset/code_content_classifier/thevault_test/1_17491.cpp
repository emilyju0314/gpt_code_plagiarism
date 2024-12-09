void Aircraft::ComputeMapLabel ()
{
    mapLabel =
    IsCurrentlyShownAsAI() ?
        (std::string("[") + label + ']') :
    IsCurrentlyShownAsTcasTarget() ?
        (std::string(">") + label + '<') :
    label;
}