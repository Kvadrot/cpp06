/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:19:27 by ufo               #+#    #+#             */
/*   Updated: 2025/09/09 12:23:32 by ufo              ###   ########.fr       */
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

//Public
void ScalarConvertor:: convert(const std::string& text) {
    std::cout << detectType(text);
}
