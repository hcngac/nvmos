#ifndef TEST_H_
#define TEST_H_

#include <kernel/kdef.h>

int nvmos_test_runAllTests(
    nvmos_ptr_t availMem,
    size_t availMemLen);

void nvmos_test_success(
    char *testName,
    size_t testCaseNum);

#define nvmos_test_fail(                             \
    testName,                                        \
    testCaseNum,                                     \
    errorMsg,                                        \
    ...)                                             \
    printf(                                          \
        "---!!! Test: %s Case: %d Failed! !!!---\n", \
        testName,                                    \
        testCaseNum);                                \
    printf("---!!! ErrorMsg: ");                     \
    printf(errorMsg, __VA_ARGS__);                   \
    printf(" !!!---\n");

#define nvmos_test_TestRunner(testPart, testNo) \
    int nvmos_test_run_##testPart##_##testNo(   \
        nvmos_ptr_t availMem,                   \
        size_t availMemLen,                     \
        nvmos_test_case_##testPart##_##testNo##_t *testCase[testPart##_##testNo##_TESTCASE_COUNT])

#define nvmos_test_defTestRunner(testPart, testNo)                        \
    nvmos_test_testRunner(testPart, testNo)                               \
    {                                                                     \
        char testName[] = #testPart "_" #testNo;                          \
        for (size_t i = 0; i < testPart##_##testNo##_TESTCASE_COUNT; ++i) \
        {                                                                 \
            int testResult =                                              \
                nvmos_test_driver_##testPart##testNo(                     \
                    availMem,                                             \
                    availMemLen,                                          \
                    testCase[i]);                                         \
            if (testResult)                                               \
            {                                                             \
                nvmos_test_fail(                                          \
                    testName,                                             \
                    i,                                                    \
                    "Case failed at %d",                                  \
                    testResult);                                          \
            }                                                             \
            else                                                          \
            {                                                             \
                nvmos_test_success(testName, i);                          \
            }                                                             \
        }                                                                 \
    }

#define nvmos_test_testDriver(testPart, testNo)  \
    int nvmos_test_driver_##testPart##_##testNo( \
        nvmos_ptr_t availMem,                    \
        size_t availMemLen,                      \
        nvmos_test_case_##testPart##_##testNo##_t *testCase)

#define nvmos_test_runTest(testPart, testNo, availMem, availMemLen) \
    nvmos_test_run_##testPart##_##testNo(availMem, availMemLen, testPart##_##testNo##_cases);

#endif