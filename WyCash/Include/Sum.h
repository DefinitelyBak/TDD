#pragma once

#include "Precompile.h"

#include "Expression.h"
#include "Money.h"


namespace Exchanger
{

    class Bank;

    /// @brief Класс выржение суммы
    class Sum: public Expression
    {
    public:
        /// @brief Конструктор
        /// @param lhs Левое слагаемое
        /// @param rhs Правое слагаемое
        Sum(std::shared_ptr<Expression> lhs, std::shared_ptr<Expression> rhs);
        
        /// @brief Преобразование суммы валют
        /// @param source Исходное значение валюты
        /// @param to Треубемый тип валюты
        /// @return Новое преобразованное значение валюты
        std::shared_ptr<Money> Reduce(Bank* bank, std::string to) const override;

        /// @brief Операция умножения суммы
        /// @param multiplier Множитель
        /// @return Новое значение валюты
        std::shared_ptr<Expression> Times(double multiplier) const override;

        /// @brief Операция сложения к сумме
        /// @param addend Слагаемое
        /// @return Новое значение валюты
        std::shared_ptr<Expression> Plus(std::shared_ptr<Expression> addend) const override;

    private:
        std::shared_ptr<Expression> _augend;
        std::shared_ptr<Expression> _addend;
    };

}