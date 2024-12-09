void exemple02()
{
    std::cout << "Example 02" << std::endl;

    Worker worker;

    // Connection to a function ...
    sigc::connection c = worker.m_signal1Finished.connect(sigc::ptr_fun(longOperationFinished));

    // Destroyed on runtime
    {
        Notifier notifier;
        worker.m_signal1Finished.connect(sigc::mem_fun(notifier, &Notifier::longOperationFinished));
    } // notifier no longer exists

    std::cout << "Reaction 01:" << std::endl;
    worker.doLongOperation(); // function reacts

    std::cout << "Reaction 02:" << std::endl;
    c.disconnect();
    worker.doLongOperation(); // No reaction
}