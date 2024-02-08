//
// Created by ilya on 09.02.24.
//

#ifndef SGSLETRANSLATOR_SGSLEFUNCTION_H
#define SGSLETRANSLATOR_SGSLEFUNCTION_H

#include <string>

namespace SGCore
{
    struct SGSLEFunction
    {
        std::string m_name;
        bool m_requiresExactSizeOfLValueArray = false;
        
        bool operator==(const SGSLEFunction& other) const noexcept
        {
            return m_name == other.m_name;
        }
        
        bool operator!=(const SGSLEFunction& other) const noexcept
        {
            return !(*this == other);
        }
    };
}

#endif //SGSLETRANSLATOR_SGSLEFUNCTION_H
