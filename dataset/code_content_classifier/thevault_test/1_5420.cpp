void NumberBox::UpdateTextToValue()
{
    if (auto&& textBox = m_textBox.get())
    {
        // Rounding the value here will prevent displaying digits caused by floating point imprecision.
        const auto roundedValue = m_displayRounder.RoundDouble(Value());

        const auto formattedValue = NumberFormatter().FormatDouble(roundedValue);
        textBox.Text(formattedValue);
    }
}