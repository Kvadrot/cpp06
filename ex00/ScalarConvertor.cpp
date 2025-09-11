/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:19:27 by ufo               #+#    #+#             */
/*   Updated: 2025/09/11 13:23:30 by ufo              ###   ########.fr       */
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
        std::cout << "double: " << (text == "nanf" ? "nan" : (text[0]== '-' ? "-inf" : "+inf")) << "\n";
    } else {
        std::cout << "float: "  << (text == "nan" ? "nanf" : (text[0]== '-' ? "-inff" : "+inff")) << "\n";
        std::cout << "double: " << text << "\n";
    }
    return;
 }
 

 void print_char_from_double(const double& numD) {
    int intedNumD = 0;
    if (numD < 0.0 || numD > 127) {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    intedNumD = static_cast<int>(numD);
	if (intedNumD < 32 || intedNumD == 127) { 
        std::cout << "char: Non displayable\n";
        return;
    }
    std::cout << "char: " << static_cast<char>(intedNumD) << std::endl;
 }
 

 void print_int_from_double(const double& numD) {
    int intedNumD = 0;
    if (numD != numD || numD < MIN_INT || numD > MAX_INT) {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    intedNumD = static_cast<int>(numD);
    std::cout << "int: " << intedNumD << std::endl;
 }
 

  void print_float_from_double(const double& numD) {
    int floatedNumD = 0.0f;
    if (numD < MIN_FLOAT || numD > MAX_FLOAT) {
        std::cout << "float: impossible" << std::endl;
        return;
    }
    floatedNumD = static_cast<float>(numD);
    std::cout << "float: " << floatedNumD << std::endl;
 }
 

   void print_double(const double& numD) {
    if (numD < MIN_DOUBLE || numD > MAX_DOUBLE) {
        std::cout << "double: impossible" << std::endl;
        return;
    }
    std::cout << "double: " << numD << std::endl;
 }
 

//Casting funcs
//
double castCharToDouble(const std::string& text) {
    double res = 0.0;
    res = static_cast<unsigned char>(text[0]);
    return res;
}

bool castStrToIntableDouble(const std::string text, double& inoutWD) {
    long num = 0;
    char *end = 0;
    num = std::strtol(text.c_str(), &end, 10);

    if (errno == ERANGE || end == text.c_str() || *end != '\0')
        return false;

    inoutWD = static_cast<double>(num);
    return true;
}

bool castStrToFloatableDouble(const std::string text, double &out) {
	std::string core = text.substr(0, text.size()-1);
	char *end = 0;
	double res = std::strtod(core.c_str(), &end);
	if (errno == ERANGE || end == core.c_str() || *end != '\0')
		return false;
	out = res; // pivot is double

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
    print_char_from_double(wildCard);
	print_int_from_double(wildCard);
	print_float_from_double(wildCard);
	print_double(wildCard);
}
