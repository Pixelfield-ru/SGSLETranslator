//
// Created by ilya on 09.02.24.
//

#ifndef SGSLETRANSLATOR_SGSLEINFO_H
#define SGSLETRANSLATOR_SGSLEINFO_H

#include <vector>
#include "SGSLEFunction.h"

namespace SGCore::SGSLEInfo
{
    // by default build-in functions
    std::vector<SGSLEFunction> n_functions {
            { "SGGetTexturesFromMaterial", true },
            { "SGGetTextures", true }
    };
}

#endif //SGSLETRANSLATOR_SGSLEINFO_H
