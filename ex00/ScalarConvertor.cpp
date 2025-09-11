/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:19:27 by ufo               #+#    #+#             */
/*   Updated: 2025/09/11 15:20:21 by ufo              ###   ########.fr       */
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
 

void print_float_from_double(const double &d) {
    float f = static_cast<float>(d);

    // NaN
    if (f != f) {
        std::cout << "float: nanf" << std::endl;
        return;
    }

    // +Inf / -Inf
    if (f == std::numeric_limits<float>::infinity()) {
        std::cout << "float: +inff" << std::endl;
        return;
    }
    if (f == -std::numeric_limits<float>::infinity()) {
        std::cout << "float: -inff" << std::endl;
        return;
    }

    // Pretty print with .0f if integer
    if (f == static_cast<int>(f)) {
        std::cout << "float: " 
                  << std::fixed << std::setprecision(1)
                  << f << "f" << std::endl;
    } else {
        std::cout << "float: " << f << "f" << std::endl;
    }
}
 

void print_double(const double &d) {
    // NaN
    if (d != d) {
        std::cout << "double: nan" << std::endl;
        return;
    }

    // +Inf / -Inf
    if (d == std::numeric_limits<double>::infinity()) {
        std::cout << "double: +inf" << std::endl;
        return;
    }
    if (d == -std::numeric_limits<double>::infinity()) {
        std::cout << "double: -inf" << std::endl;
        return;
    }

    // Pretty print with .0 if integer
    if (d == static_cast<long>(d)) {
        std::cout << "double: " 
                  << std::fixed << std::setprecision(1)
                  << d << std::endl;
    } else {
        std::cout << "double: " << d << std::endl;
    }
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
            printInputErr(text);
            return;
    }
    print_char_from_double(wildCard);
	print_int_from_double(wildCard);
	print_float_from_double(wildCard);
	print_double(wildCard);
}
