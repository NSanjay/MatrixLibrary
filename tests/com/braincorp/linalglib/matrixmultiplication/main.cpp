// main.cpp
#include "iostream"
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TextOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <com/braincorp/linalglib/matrixmultiplication/MatrixTest.hpp>

#include <netinet/in.h>

using namespace std;
/*!
*  Starting point to run the tests
*/
int main(int argc, char **argv)
{
    CppUnit::TestResult testResult;

    CppUnit::TestResultCollector collectedresults;

    testResult.addListener (&collectedresults);

    CppUnit::BriefTestProgressListener progress;

    testResult.addListener (&progress);

    CppUnit::TextUi::TestRunner runner;
    
    runner.addTest(MatrixUnitTests::suite());

    runner.run(testResult);
    int wasSuccessful = collectedresults.wasSuccessful() ? 0 : 1;

    CppUnit::CompilerOutputter compileroutputter(&collectedresults, std::cerr);

    compileroutputter.write ();

    ofstream xmlFileOut("cppTestBasicMathResults.xml");

    CppUnit::XmlOutputter xmlOut(&collectedresults, xmlFileOut);

    xmlOut.write();

  return !wasSuccessful;
}
