#pragma once

#include "Precompile.h"

#include "TestSuite.h"
#include "TestFunctions.h"


namespace xUnit
{
    
    /// @brief Класс тестов для тестирования xUnit
    class TestCaseTest: public TestCase<void()>
    {
    public:
        /// @brief Используемый тип функции
        using fuctionType = std::function<void( TestCaseTest* obj)>;

        /// @brief Конструктор
        /// @param func Тестируемая функция
        /// @param nameFunction Название тестируемой функции
        TestCaseTest(fuctionType func, std::string nameFunction);

        /// Описание тестов:
        ///
        /// @brief Тест логов
        void TestTemplateMethod()
        {
            _test.Run(_resultTest);
            assert("setUp TestTemplateMethod tearDown" == _test.GetLog());
        }

        /// @brief Тест вывода результата
        void TestResult()
        {
            _test.Run(_resultTest);
            assert("1 run, 0 failed" == _resultTest.Summary());
        }

        /// @brief Тест, неудачного окончания теста
        void TestFailedResult()
        {
            xUnit::TestResult resultTest;
            _test = WasRun<void()>(xUnit::TestBrokenMethod, TestCase::GetNameFunction());
            _test.Run(resultTest);
            assert("1 run, 1 failed error: Error in TestBrokenMethod" == resultTest.Summary());
        }

        /// @brief Тестирование лога при неадчном не прошедшем тесте 
        void FailedResultFormatting()
        {
            auto result = xUnit::TestResult();
            result.TestStarted();
            result.TestFailed();
            assert("1 run, 1 failed error: std::exception" == result.Summary());
        }

        /// @brief Тестирование контейнера тестов
        void TestSuite()
        {
            auto suite = xUnit::TestSuite<void()>();
            suite.Add(WasRun<void()>(xUnit::TestFirst, "testMethod"));
            suite.Add(WasRun<void()>(xUnit::TestBrokenMethod, "TestBrokenMethod"));
            suite.Run(_resultTest);
            assert("2 run, 1 failed error: Error in TestBrokenMethod" == _resultTest.Summary());
        }

    private:
        /// @brief Подготовка функции
        void SetUp() override;

        WasRun<void()> _test;
        xUnit::TestResult _resultTest;
    };

}