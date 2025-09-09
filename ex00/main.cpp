/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:03:44 by ufo               #+#    #+#             */
/*   Updated: 2025/09/09 12:39:04 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvertor.hpp"
#include  "SuppFuncs.hpp"

int main (void)  {
    //isChar Tests
    std::string text = "1";
    std::cout << text << " = " << detectType(text) << std::endl;
    
    text = "9";
    std::cout << text << " = " << detectType(text) << std::endl;
    
    text = " ";
    std::cout << text << " = " << detectType(text) << std::endl;
    
    text = "a";
    std::cout << text << " = " << detectType(text) << std::endl;
    
    text = "";
    std::cout << text << " = " << detectType(text) << std::endl;
    
    text = "n";
    std::cout << text << " = " << detectType(text) << std::endl;
    
    text = "1e";
    std::cout << text << " = " << detectType(text);
    
}