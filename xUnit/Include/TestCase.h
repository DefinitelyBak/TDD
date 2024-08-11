#pragma once

#include "Precompile.h"

#include "TestResult.h"


namespace xUnit
{

    /// @brief Класс запускаемых тестов
    /// @tparam T Тип тестируемой функции
    template<class T> class TestCase
    {
    public:
        /// @brief Используемый тип функции
        using fuctionType = std::function<T>;

        /// @brief Дефолдный конструктор
        TestCase() = default;

        /// @brief Конструктор
        /// @param funct Тестируемая функция 
        /// @param nameFunction Название тестируемой функции
        TestCase(fuctionType funct, std::string nameFunction): _funct(funct), _nameFunction(nameFunction)
        {}

        /// @brief Запуск теста
        /// @param result Объект компоновщик
        void Run(TestResult& result)
        {
            result.TestStarted();
            SetUp();
            try
            {
                _funct();
            }
            catch(const std::exception& e)
            {
                result.TestFailed(e);
            }
            catch(...)
            {
                result.TestFailed(std::exception());
            }

            TearDown();
        }

    protected:
        /// @brief Вернуть название тестируемой функции
        /// @return Название функции
        std::string GetNameFunction() const
        {
            return _nameFunction;
        }

    private:
        /// @brief Подготовка функции
        virtual void SetUp(){};

        /// @brief Функция очистки
        virtual void TearDown(){};

        fuctionType _funct;
        std::string _nameFunction;
    };

}