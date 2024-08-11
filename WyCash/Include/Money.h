#pragma once

#include "Precompile.h"

#include "Expression.h"


namespace Exchanger
{

    class Sum;
    class Bank;

    /// @brief Класс реализующий валюту
    class Money: public Expression
    {
    public:
        /// @brief Конструктор
        /// @param amount Значение валюты 
        /// @param currency Наименование валюты
        explicit Money(double amount, std::string currency);

        /// @brief Фабричные методы для создания Dollar
        /// @param Численное значение 
        /// @return Новый объект Dollar
        static std::shared_ptr<Money> Dollar(double ammount);

        /// @brief Фабричные методы для создания Franc
        /// @param Численное значение 
        /// @return Новый объект Franc
        static std::shared_ptr<Money> Franc(double ammount);

        /// @brief Получить наименвание валюты
        /// @return Имя валюты
        [[nodiscard]] inline std::string GetCurrency() const
        {
            return _currency;
        };

        /// @brief Получить численное значение валюты
        /// @return Значение
        [[nodiscard]] inline double GetAmmount() const
        {
            return _ammount;
        };

        /// @brief Преобразование валюты
        /// @param source Исходное значение валюты
        /// @param to Треубемый тип валюты
        /// @return Новое преобразованное значение валюты
        std::shared_ptr<Money> Reduce(Bank* bank, std::string to) const override;

        /// @brief Операция сложения
        /// @param addend Слагаемое
        /// @return Новое значение валюты
        std::shared_ptr<Expression> Plus(std::shared_ptr<Expression> addend) const override;

        /// @brief Операция сложения
        /// @param addend Слагаемое
        /// @return Новое значение валюты
        std::shared_ptr<Expression> Plus(std::shared_ptr<Money> addend) const;

        /// @brief Операция умножения
        /// @param multiplier Множитель
        /// @return Новое значение валюты
        std::shared_ptr<Expression> Times(double multiplier) const override;

        /// @brief Вывод числа в виде строки
        /// @return Валюта в формате строке
        [[nodiscard]] std::string ToString() const;

    private:
        std::string _currency;
        double _ammount;
    };

    bool operator==(std::shared_ptr<Expression> lhs, std::shared_ptr<Expression> rhs);
    bool operator==(std::shared_ptr<Money> lhs, std::shared_ptr<Money> rhs);
    bool operator==(std::shared_ptr<Expression> lhs, std::shared_ptr<Money> rhs);
    bool operator==(std::shared_ptr<Money> lhs, std::shared_ptr<Expression> rhs);

}