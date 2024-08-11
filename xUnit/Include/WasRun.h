#pragma once

#include "Precompile.h"

#include "TestCase.h"


namespace xUnit
{

    /// @brief Класс сопровождающий тест
    /// @tparam T Тип проверяемой функции
    template<class T> class WasRun: public TestCase<T>
    {
    public:
        /// @brief Используемый тип функции
        using fuctionType = std::function<T>;

        /// @brief Дефолдный конструктор
        WasRun() = default;

        /// @brief Конструктор
        /// @param funct Тестируемая функция 
        /// @param nameFunction Название тестируемой функции
        WasRun(fuctionType funct, std::string nameFunction): TestCase<T>(funct, nameFunction)
        {}

        /// @brief Получить лог теста
        /// @return Лог теста
        [[nodiscard]] std::string GetLog() const
        {
            return _log;
        }

    private:
        /// @brief Подготовка функции
        void SetUp() override
        {
            _log = "setUp ";
        }

        /// @brief Функция очистки
        void TearDown() override
        {
            _log += TestCase<T>::GetNameFunction() + " tearDown";
        }

        std::string _log;
    };

}