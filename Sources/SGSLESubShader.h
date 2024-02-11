//
// Created by ilya on 10.02.24.
//

#ifndef SGSLETRANSLATOR_SGSLESUBSHADER_H
#define SGSLETRANSLATOR_SGSLESUBSHADER_H

#include <string>
#include <vector>
#include "SGSLESubShaderType.h"
#include "SGSLEVariable.h"
#include "SGSLEBracketsListener.h"
#include "SGSLEStruct.h"

namespace SGCore
{
    struct SGSLESubShader : SGSLEBracketsListener
    {
        std::string m_name;
        std::string m_code;
        SGSLESubShaderType m_type = SGSLESubShaderType::SST_NONE;
        std::vector<SGSLEVariable> m_variables;
        
        std::vector<SGSLEStruct> m_structs;
        
        SGSLEStruct* tryGetStruct(const std::string& structName) noexcept
        {
            auto it = std::find(m_structs.begin(), m_structs.end(), SGSLEStruct { structName });
            return it == m_structs.end() ? nullptr : &*it;
        }
    };
}

#endif //SGSLETRANSLATOR_SGSLESUBSHADER_H
