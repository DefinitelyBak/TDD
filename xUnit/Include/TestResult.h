#pragma once

#include "Precompile.h"


namespace xUnit
{

    /// @brief Класс хранилище результата тестов
    class TestResult
    {
    public:
        /// @brief Конструктор
        TestResult();

        /// @brief Сформировать результат
        /// @return Результат
        [[nodiscard]] std::string Summary() const;

        /// @brief Запуск теста
        void TestStarted();

        /// @brief Фиксация ошибки
        /// @param e Ошибка
        void TestFailed(const std::exception& e = std::exception());

    private:
        int _runCount;
        int _errorCount;
        std::string _errorLog;
    };

}