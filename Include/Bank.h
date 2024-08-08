#pragma once

#include "Precompile.h"

#include "CurrencysHash.h"
#include "Money.h"


namespace Exchanger
{

    /// @brief Класс реализующий обмен валют
    class Bank
    {
    public:
        /// @brief Преобразование валюты
        /// @param source Исходное значение валюты
        /// @param to Треубемый тип валюты
        /// @return Новое преобразованное значение валюты
        std::shared_ptr<Money> Reduce(std::shared_ptr<Expression> source, std::string to);

        /// @brief Добавить значение обмена валют в таблицу
        /// @param from Из какой валюты
        /// @param to В какую валюты
        /// @param rate Коэффициент 
        void AddRate(std::string from, std::string to, double rate);
        
        /// @brief Получить значение коэффициент
        /// @param from Из какой валюты
        /// @param to В какую валюты
        /// @return Коэффициент
        double Rate(std::string from, std::string to);

    private:
        using currencys = std::pair<std::string, std::string>;
        std::unordered_map<currencys, double, currencysHash> _hashtable;
    };

}