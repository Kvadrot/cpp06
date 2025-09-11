/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:19:27 by ufo               #+#    #+#             */
/*   Updated: 2025/09/11 12:43:48 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvertor.hpp"
#include "SuppFuncs.hpp"


//Consructors
ScalarConvertor:: ScalarConvertor() {
    
}

ScalarConvertor:: ScalarConvertor(const ScalarConvertor&) {
    
}

ScalarConvertor& ScalarConvertor:: operator=(const ScalarConvertor& other) {
    if (this != &other) {
        return (*this);
    }
    return *this;
}

ScalarConvertor:: ~ScalarConvertor() {
    
}



// prints funcs:
//
void printInputErr(const std::string& text) {
    std::cout << text << " is invalid input" << std::endl;
}

 void printPseudo(const std::string& text) {
    std::cout << "char: impossible\nint: impossible\n";
    if (text == "nanf" || text == "+inff" || text == "-inff") {
        std::cout << "float: "  << text << "\n";
        std::cout << "double: " << (text == "nanf" ? "nan" : (text[0]=='-'?"-inf":"+inf")) << "\n";
    } else {
        std::cout << "float: "  << (text == "nan" ? "nanf" : (text[0]=='-'?"-inff":"+inff")) << "\n";
        std::cout << "double: " << text << "\n";
    }
    return;
 }

//Casting funcs
//
double castCharToDouble(const std::string& text) {
    double res = 0.0;
    res = static_cast<unsigned char>(text[0]);
    return res;
}

bool castStrToIntableDouble(const std::string text, double& inoutWD) {
    long long num = 0;
    char *end = 0;
    num = std::strtoll(text.c_str(), &end, 10);

    if (errno == ERANGE || end == text.c_str() || *end != '\0')
        return false;

    inoutWD = static_cast<double>(num);
    return true;
}

bool castStrToFloatableDouble(const std::string text, double& inoutWD) {
    double numD = 0;
    char *end = 0;
    numD = std::strtod(text.c_str(), &end);

    if (errno == ERANGE || end == text.c_str() || *end != '\0')
        return false;

    inoutWD = static_cast<double>(numD);
    return true;
}

bool castStrToDouble(const std::string text, double& inoutWD) {
    double numD = 0;
    char *end = 0;
    numD = std::strtod(text.c_str(), &end);

    if (errno == ERANGE || end == text.c_str() || *end != '\0')
        return false;

    inoutWD = static_cast<double>(numD);
    return true;
}

//Public
void ScalarConvertor:: convert(const std::string& text) {
    TypeLiteral typeVal = detectType(text);
    double wildCard = 0.0;

    switch (typeVal) {
        case typeChar:
            wildCard = castCharToDouble(text);
            break;
        case typeInt:
            if (castStrToIntableDouble(text, wildCard) == false)
                return printInputErr(text);
            break;
        case typeFloat:
            if (castStrToFloatableDouble(text, wildCard) == false)
                return printInputErr(text);
            break;
        case typeDouble:
            if (castStrToDouble(text, wildCard) == false)
                return printInputErr(text);
            break;
        case typePseudo:
            printPseudo(text);
            return;
        default: //typeInvalid:
            break;
    }
    std::cout << wildCard << " ====== " << std::endl;
}
