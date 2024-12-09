void klk::test::printOut(const std::string& message)
{
        CPPUNIT_NS::stdCOut() << message;
        CPPUNIT_NS::stdCOut().flush();
}