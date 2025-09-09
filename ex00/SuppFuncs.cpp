/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuppFuncs.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:19:27 by ufo               #+#    #+#             */
/*   Updated: 2025/09/09 12:38:17 by ufo              ###   ########.fr       */
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

    return (true);
}

TypeLiteral detectType(const std::string& text) {
    if (isChar(text))
        return typeChar;
    return typeInvalid;
}