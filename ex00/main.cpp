/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:03:44 by ufo               #+#    #+#             */
/*   Updated: 2025/09/11 12:44:14 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvertor.hpp"
#include  "SuppFuncs.hpp"

int main (void)  {

    std::string text = "1001412342134213412";
    ScalarConvertor::convert(text);

    text = "1232";
    ScalarConvertor::convert(text);

    text = "nanf";
    ScalarConvertor::convert(text);


//     std::cout << text << " = " << detectType(text) << std::endl;
    
//     text = "9";
//     std::cout << text << " = " << detectType(text) << std::endl;
    
//     text = " ";
//     std::cout << text << " = " << detectType(text) << std::endl;
    
//     text = "a";
//     std::cout << text << " = " << detectType(text) << std::endl;
    
//     text = "";
//     std::cout << text << " = " << detectType(text) << std::endl;
    
//     text = "n";
//     std::cout << text << " = " << detectType(text) << std::endl;
    
//     text = "1e";
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "+1";
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "-2";
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "-0";
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "-214647541222";
//     std::cout << text << " = " << detectType(text) << std::endl;
    
//     text = "1.2";
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "1.233.f";
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "-2.1f";
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "42.0f";
//     std::cout << text << " = " << detectType(text) << std::endl;
    

//     // --- edge / failing cases to add ---
// std::cout  << " = ============ ================ =" << std::endl;

//     text = "";               // ❌ UB now: isChar reads text[0]; add empty guard
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = " 42";            // should be invalid (space + digits)
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "42 ";            // should be invalid (digits + space)
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "1.2ff";          // ❌ your isFloat likely returns true (extra 'f')
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "1.233.f";        // ❌ extra dot before 'f' — should be invalid
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "+.5f";           // decide rule: if you require digit before dot, should be invalid
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "2.f";            // length 3 → your isFloat rejects (minSize=4). OK if you want strict.
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = ".5";             // no leading digit; your isDouble rejects (minSize=3). OK if strict.
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "1.";             // no digit after dot; your isDouble may wrongly accept if not checking digits
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "nan";            // pseudo double — your code marks invalid (no isPseudo yet)
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "nanf";           // pseudo float — same, currently invalid
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "+inf";           // pseudo double — should be handled specially
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "-inff";          // pseudo float — should be handled specially
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "+";              // only sign — invalid int
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "++42";           // invalid (two signs)
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "1..2";           // invalid (two dots)
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "1.2.3f";         // invalid (two dots + 'f')
//     std::cout << text << " = " << detectType(text) << std::endl;

//     text = "f1";             // not a char, not a number
//     std::cout << text << " = " << detectType(text) << std::endl;
}