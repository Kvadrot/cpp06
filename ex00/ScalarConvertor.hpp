/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:20:32 by ufo               #+#    #+#             */
/*   Updated: 2025/09/09 12:26:52 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTOR_HPP
#define SCALARCONVERTOR_HPP

#include <string>
#include <iostream>
// 1) Detect main type (char / int / float / double / pseudo).

// 2) Parse it.

// 3) Convert to all other types.

enum TypeLiteral {
    typeChar,
    typeInt,
    typeFloat,
    typeDouble,
    typePseudo,
    typeInvalid
};

class ScalarConvertor {
    private:
        ScalarConvertor();
        ScalarConvertor(const ScalarConvertor& other);
        ScalarConvertor& operator=(const ScalarConvertor& other);
        ~ScalarConvertor();
    

    public:
        static void convert(const std::string& text);
};

#endif