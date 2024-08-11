#pragma once

#include "Precompile.h"

#include "WasRun.h"


namespace xUnit
{

    /// @brief Класс контейнер тестов
    /// @tparam T Тип тестируемых функций
    template<class T> class TestSuite
    {
    public:
        /// @brief Конструктор
        TestSuite() = default;

        /// @brief Добавить тест
        /// @param test Тест
        void Add(WasRun<T>&& test)
        {
            _tests.emplace_back(std::forward<WasRun<T>>(test));
        }

        /// @brief Запустить тесты
        /// @param result Возвращаемый результат
        void Run(TestResult& result)
        {
            for (auto& x: _tests)
                x.Run(result);
        }

    private:
        std::list<WasRun<T>> _tests;
    };

}