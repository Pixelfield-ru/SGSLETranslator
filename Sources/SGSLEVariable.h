//
// Created by ilya on 10.02.24.
//

#ifndef SGSLETRANSLATOR_SGSLEEXPR_H
#define SGSLETRANSLATOR_SGSLEEXPR_H

#include <string>
#include <vector>
#include <functional>

namespace SGCore
{
    struct SGSLEVariable
    {
        std::string m_functionName;
        std::string m_lValueVarType;
        bool m_isLValueArray = false;
        int m_lValueArraySize = -1;
        std::vector<size_t> m_arrayIndices;
        std::string m_lValueVarName;
    };
}

#endif //SGSLETRANSLATOR_SGSLEEXPR_H
