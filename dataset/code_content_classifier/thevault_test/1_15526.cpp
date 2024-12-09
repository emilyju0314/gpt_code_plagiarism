nmi_window_handler::nmi_window_handler(
    gsl::not_null<vcpu *> vcpu
) :
    m_vcpu{vcpu}
{
    using namespace vmcs_n;

    vcpu->add_handler(
        exit_reason::basic_exit_reason::nmi_window,
        ::handler_delegate_t::create<nmi_window_handler, &nmi_window_handler::handle>(this)
    );
}