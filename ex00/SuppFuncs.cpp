/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuppFuncs.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:19:27 by ufo               #+#    #+#             */
/*   Updated: 2025/09/10 13:08:58 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvertor.hpp"
#include <iostream>
//Helper func

bool isChar(const std::string &text) {
    if (text.size() > 1)
        return false;
        
    char chr = text[0];
    if (chr < 32 || chr > 126)
        return false;
        
    if (isdigit(chr))
        return false;

    return true;
}

bool isInt(const std::string &text) {
    size_t i = 0;
    if (text[i] == '-' || text[i] == '+')
        i++;
    if (i >= text.size())
        return false;
    for (; i < text.size(); i++) {
        if (text[i] < '0' || text[i] > '9')
            return false;
    }
    return true;
}

// +.5f = 2

bool isFloat(const std::string &text) {
    
    size_t i = 0;
    size_t minSize = 4; // 0.0f
    char delim = '.';
    int delimCounter = 0;

    if (text.size() < minSize)
        return false;
    if (text[i] == '-' || text[i] == '+')
        i++;
    if (i >= text.size())
        return false;
    if (text[i] < '0' || text[i] > '9')
        return false;

    for (; i < text.size(); i++) {
        if (text[i] == delim && delimCounter >= 1)
            return false;
        if (text[i] == delim) {
            delimCounter++;
            continue;
        }
        if (text[i] < '0' || text[i] > '9')
            break;
    }
    
    if (i < text.size() - 1 || text[i] != 'f')
        return false;
    
    return true;
}

bool isDouble(const std::string &text) {    
    size_t i = 0;
    size_t minSize = 3; // 0.0
    char delim = '.';
    int delimCounter = 0;

    if (text.size() < minSize)
        return false;
    if (text[i] == '-' || text[i] == '+')
        i++;
    if (i >= text.size())
        return false;
    if (text[i] < '0' || text[i] > '9')
        return false;

    for (; i < text.size(); i++) {
        if (text[i] == delim && delimCounter >= 1)
            return false;
        if (text[i] == delim) {
            delimCounter++;
            continue;
        }
        if (text[i] < '0' || text[i] > '9')
            return false;
    }
    
    return true;
}


TypeLiteral detectType(const std::string& text) {
    if (isChar(text))
        return typeChar;
    if (isInt(text))
        return typeInt;
    if (isFloat(text))
        return typeFloat;
    if (isDouble(text))
        return typeDouble;
    // if (isPseudo(text))
    //     return typePseudo;
 
    return typeInvalid;
}