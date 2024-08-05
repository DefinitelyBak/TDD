#pragma once

#include <memory>
#include <string>


namespace Exchanger
{

    class Money
    {
    public:
        Money(double amount, std::string currency);
        virtual ~Money() = default;

        /// @brief Фабричные методы для создания Dollar
        /// @param Численное значение 
        /// @return Новый объект Dollar
        static std::unique_ptr<Money> Dollar(double ammount);

        /// @brief Фабричные методы для создания Franc
        /// @param Численное значение 
        /// @return Новый объект Franc
        static std::unique_ptr<Money> Franc(double ammount);

        bool Equals(std::unique_ptr<Money> value) const;
        std::string Currency() const;
        std::unique_ptr<Money> Times(double multiplier);

        std::string ToString() const;

    protected:       
       double _ammount;
       std::string _currency;

    };

}