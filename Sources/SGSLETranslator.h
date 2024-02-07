//
// Created by ilya on 07.02.24.
//

#ifndef SGSLETRANSLATOR_SGSLETRANSLATOR_H
#define SGSLETRANSLATOR_SGSLETRANSLATOR_H

#include <string>
#include <vector>
#include <set>

namespace SGCore
{
    class SGSLETranslator
    {
    public:
        std::string processCode(const std::string& path, const std::string& code);

    private:
        std::string sgsleCodeCorrector(const std::string& code);
        std::string sgslePreprocessor(const std::string& path, const std::string& code);
        std::string sgslePreProcessor(const std::string& path, const std::string& code, SGSLETranslator& translator);
        std::string sgsleMainProcessor(const std::string& code);
        
        std::set<std::string> m_includedFiles;
    };
}

#endif //SGSLETRANSLATOR_SGSLETRANSLATOR_H