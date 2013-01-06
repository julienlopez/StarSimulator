#ifndef __MATRIX_UT_HPP__
#define __MATRIX_UT_HPP__

#include <cppunit/extensions/HelperMacros.h>

class Matrix_UT : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(Matrix_UT);
    CPPUNIT_TEST(testConstructorInitializerList);
    CPPUNIT_TEST_SUITE_END();

public:
    virtual void setUp();
    virtual void tearDown();

    void testConstructorInitializerList();
};

#endif // __MATRIX_UT_HPP__
