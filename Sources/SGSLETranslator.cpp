//
// Created by ilya on 07.02.24.
//

#include <sstream>
#include "SGSLETranslator.h"
#include "Utils.h"

std::string SGCore::SGSLETranslator::processCode(const std::string& path, const std::string& code)
{
    m_includedFiles.insert(path);
    std::string correctedCode = sgsleCodeCorrector(code);
    std::string preProcessedCode = sgslePreprocessor(path, correctedCode);
    std::string finalCode = sgsleMainProcessor(preProcessedCode);
    
    return finalCode;
}

std::string SGCore::SGSLETranslator::sgsleCodeCorrector(const std::string& code)
{
    // EOL is end-of-line
    // WO - without
    
    enum CommentMode
    {
        NO_COMMENT,
        SINGLE_LINE_COMMENT,
        MULTILINE_COMMENT
    };
    
    std::string outputStr;
    
    std::string currentLine;
    
    size_t currentCharOfStrIdxWOSpaces = 0;
    
    bool preProcDirDeclared = false;
    
    char lastChar = '\0';
    
    CommentMode commentMode = CommentMode::NO_COMMENT;
    
    int currentIndent = 0;
    
    // new line if met symbol '{' or '}'
    // new line by the EOL character if first character of string '#'
    // else collecting characters to line while not met ';'
    for(char c : code)
    {
        if(lastChar == '*' && c == '/' && !preProcDirDeclared)
        {
            commentMode = CommentMode::NO_COMMENT;
            currentCharOfStrIdxWOSpaces = 0;
            continue;
        }
        
        if(lastChar == '/' && c == '/' && !preProcDirDeclared)
        {
            commentMode = CommentMode::SINGLE_LINE_COMMENT;
            currentLine.erase(currentLine.end() - 1);
            continue;
        }
        
        if(commentMode == CommentMode::SINGLE_LINE_COMMENT && c == '\n')
        {
            currentCharOfStrIdxWOSpaces = 0;
            commentMode = CommentMode::NO_COMMENT;
            continue;
        }
        
        if(commentMode == CommentMode::NO_COMMENT)
        {
            if(lastChar == '/' && c == '*' && !preProcDirDeclared)
            {
                commentMode = CommentMode::MULTILINE_COMMENT;
                currentLine.erase(currentLine.end() - 1);
                continue;
            }
            
            if(c == '#' && currentCharOfStrIdxWOSpaces == 0)
            {
                preProcDirDeclared = true;
            }
            
            if(c == '\n' && preProcDirDeclared)
            {
                currentCharOfStrIdxWOSpaces = 0;
                preProcDirDeclared = false;
                currentLine += c;
                outputStr += std::string(currentIndent, '\t') + SGUtils::Utils::reduce(currentLine);
                currentLine = "";
                
                continue;
            }
            
            if(c == ';' && !preProcDirDeclared)
            {
                currentCharOfStrIdxWOSpaces = 0;
                currentLine += c;
                currentLine += '\n';
                outputStr += std::string(currentIndent, '\t') + SGUtils::Utils::reduce(currentLine);
                currentLine = "";
                
                continue;
            }
            
            if((c == '{' || c == '}') && !preProcDirDeclared)
            {
                currentLine += c;
                currentLine += '\n';
                
                outputStr += std::string(c == '}' ? currentIndent - 1 : currentIndent, '\t') + SGUtils::Utils::reduce(currentLine);
                currentLine = "";
                
                if(c == '{')
                {
                    ++currentIndent;
                }
                else
                {
                    --currentIndent;
                }
                
                currentCharOfStrIdxWOSpaces = 0;
                
                continue;
            }
            
            if(c != '\n')
            {
                currentLine += c;
            }
            else
            {
                currentLine += ' ';
            }
            
            if(c != ' ' && c != '\n')
            {
                ++currentCharOfStrIdxWOSpaces;
            }
        }
        
        lastChar = c;
    }
    
    return outputStr;
}

std::string SGCore::SGSLETranslator::sgslePreProcessor(const std::string& path, const std::string& code, SGSLETranslator& translator)
{
    std::stringstream codeStream(code);
    
    std::string line;
    
    std::string outputStr;
    
    while(std::getline(codeStream, line))
    {
        std::vector<std::string> words;
        SGUtils::Utils::splitString(line, ' ', words);
        
        /*if(words.size() >= 2 && words[0] == "#sg_pragma" && words[1] == "once" && m_includedFiles.contains(path))
        {
            return outputStr;
        }
        
        if(!words.empty() && words[0] == "#sg_include")
        {
        
        }*/
        
        outputStr += line + "\n";
    }
    
    return outputStr;
}

std::string SGCore::SGSLETranslator::sgslePreprocessor(const std::string& path, const std::string& code)
{
    return sgslePreProcessor(path, code, *this);
}

std::string SGCore::SGSLETranslator::sgsleMainProcessor(const std::string& code)
{
    return code;
}
