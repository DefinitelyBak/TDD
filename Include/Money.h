#pragma once

#include <memory>
#include <string>

#include "Expression.h"


namespace Exchanger
{

    class Sum;
    class Bank;

    class Money: public Expression
    {
    public:
        Money() = default;
        Money(double amount, std::string currency);
        Money(const Money& obj);

        virtual ~Money() = default;

        /// @brief Фабричные методы для создания Dollar
        /// @param Численное значение 
        /// @return Новый объект Dollar
        static std::shared_ptr<Money> Dollar(double ammount);

        /// @brief Фабричные методы для создания Franc
        /// @param Численное значение 
        /// @return Новый объект Franc
        static std::shared_ptr<Money> Franc(double ammount);

        /// @brief 
        /// @param value 
        /// @return 
        bool Equals(std::shared_ptr<Money> value) const;

        /// @brief 
        /// @return 
        std::string Currency() const;

        double Ammount() const;
        std::shared_ptr<Money> Times(double multiplier);

        std::shared_ptr<Money> Reduce(Bank* bank, std::string to);

        std::string ToString() const;

    private:       
       double _ammount;
       std::string _currency;
    };


    std::shared_ptr<Sum> operator+ (std::shared_ptr<Money> lhr, std::shared_ptr<Money> rhs); 
}