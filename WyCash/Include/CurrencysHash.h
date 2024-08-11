#pragma once

#include "Precompile.h"


namespace Exchanger
{
    
    /// @brief Тип пары валюты
    using currencys = std::pair<std::string, std::string>;

    /// @brief Функтор для расчёта хэша
    struct currencysHash
    {
        /// @brief Расчёт кэша
        /// @param s Пара для которой раситывается кэш
        /// @return Кэш сумма
        std::size_t operator()(const Exchanger::currencys& s) const noexcept;
    };

}