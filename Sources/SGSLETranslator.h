//
// Created by ilya on 07.02.24.
//

#ifndef SGSLETRANSLATOR_SGSLETRANSLATOR_H
#define SGSLETRANSLATOR_SGSLETRANSLATOR_H

#include <string>
#include <vector>
#include <set>
#include <regex>
#include "SGSLETranslatorConfiguration.h"
#include "ShaderAnalyzedFile.h"

namespace SGCore
{
    class SGSLETranslator
    {
    public:
        std::shared_ptr<ShaderAnalyzedFile> processCode(const std::string& path, const std::string& code, SGSLETranslator& translator);
        std::shared_ptr<ShaderAnalyzedFile> processCode(const std::string& path, const std::string& code);

        SGSLETranslatorConfiguration m_config;

    private:
        std::shared_ptr<ShaderAnalyzedFile> processCode(const std::string& path, const std::string& code, SGSLETranslator& translator, bool isRootShader);

        std::string sgsleCodeCorrector(const std::string& code);
        std::shared_ptr<ShaderAnalyzedFile> sgslePreprocessor(const std::string& path, const std::string& code);
        std::shared_ptr<ShaderAnalyzedFile> sgslePreProcessor(const std::string& path, const std::string& code, SGSLETranslator& translator);
        std::shared_ptr<ShaderAnalyzedFile> sgsleMainProcessor(const std::shared_ptr<ShaderAnalyzedFile>& code);
        
        static inline const std::regex s_rSideOfAssignExprRegex = std::regex(R"(\s*(\w+)\s*\(([^)]*)\);)");
        static inline const std::regex m_sgslFuncWithArgsCallRegex = std::regex(R"(\s*(\w+)\s*\(([^)]*)\))");
        static inline const std::regex m_funcArgsDividerRegex = std::regex(R"([a-zA-Z]+)");
        static inline const std::sregex_iterator m_regexIterEnd;
        
        std::vector<SGSLESubPass*> m_currentSubPasses;
        std::vector<std::pair<SGSLESubPass*, SGSLESubShader*>> m_currentSubShaders;
        
        std::set<std::string> m_includedFiles;
    };
}

#endif //SGSLETRANSLATOR_SGSLETRANSLATOR_H
