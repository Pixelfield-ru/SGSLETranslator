#include <iostream>
#include "SGSLETranslator.h"
#include "FileUtils.h"
#include "Utils.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;
    
    SGCore::SGSLETranslator translator;
    
    std::string path = "../shaders/default_shader.glsl";
    
    auto analyzedFile = translator.processCode(path, SGUtils::FileUtils::readFile(path));
    
    std::string proceedCode = analyzedFile->getSubShaderCode("GeometryPass", SGCore::SST_FRAGMENT);
    
    std::cout << proceedCode << std::endl;
    
    return 0;
}
