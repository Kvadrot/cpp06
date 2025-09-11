/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:19:27 by ufo               #+#    #+#             */
/*   Updated: 2025/09/11 11:52:54 by ufo              ###   ########.fr       */
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



// interpriner funcs:
void printInputErr(const std::string& text) {
    std::cout << text << " is invalid input" << std::endl;
}

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
    if (MIN_INT > num || MAX_INT < num)
        return false;

    inoutWD = static_cast<double>(num);
    return true;
}

// bool castStrToFloatableDouble(const std::string text, double& inoutWD) {
    
// }

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
            break;
        case typeDouble:
            break;
        case typePseudo:
            break;
        case typeInvalid:
            break;
        default:
            break;
    }
    std::cout << wildCard << " ====== " << std::endl;
}
