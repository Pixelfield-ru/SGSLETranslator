#include <iostream>
#include "SGSLETranslator.h"
#include "FileUtils.h"
#include "Utils.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;
    
    SGCore::SGSLETranslator translator;
    
    std::string path = "../shaders/default_shader.glsl";
    
    std::string proceedCode = translator.processCode(path, SGUtils::FileUtils::readFile(path))->getSubShaderCode("GeometryPass", SGCore::SST_VERTEX);
    
    std::cout << proceedCode << std::endl;
    
    return 0;
}
