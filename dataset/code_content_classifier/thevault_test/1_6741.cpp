void RTPAgent::finish()
{
        running_ = 0;
        Tcl::instance().evalf("%s done", this->name());
}