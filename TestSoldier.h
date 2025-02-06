#ifndef TEST_SOLDIER_H
#define TEST_SOLDIER_H


class TestSoldier{
public: 
    void runTestSoldier(){
        TestConstructor(); 
        testAttack();
        testDestructor(); 
        testColor();
        testName();
    }
private:
    void TestConstructor(); 
    void testAttack(); 
    void testDestructor(); 
    void testColor();
    void testName();
};

#endif

