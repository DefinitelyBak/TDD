#pragma once

#include "Precompile.h"


namespace Exchanger
{

    class Bank;
    class Money;

    /// @brief Класс выражения
    class Expression
    {
    public:
        /// @brief Преобразование валюты
        /// @param source Исходное значение валюты
        /// @param to Треубемый тип валюты
        /// @return Новое преобразованное значение валюты
        virtual std::shared_ptr<Money> Reduce(Bank* bank, std::string to) const = 0;

        /// @brief Операция умножения
        /// @param multiplier Множитель
        /// @return Новое значение валюты
        virtual std::shared_ptr<Expression> Times(double multiplier) const = 0;

        /// @brief Операция сложения
        /// @param addend Слагаемое
        /// @return Новое значение валюты
        virtual std::shared_ptr<Expression> Plus(std::shared_ptr<Expression> addend) const = 0;
    };

}