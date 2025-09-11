/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:20:32 by ufo               #+#    #+#             */
/*   Updated: 2025/09/11 10:58:42 by ufo              ###   ########.fr       */
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

# define MIN_INT std::numeric_limits<int>::min() //-2147483648
# define MAX_INT std::numeric_limits<int>::max() //2147483647
# define MIN_FLOAT std::numeric_limits<float>::min() //-3.40282e+38
# define MAX_FLOAT std::numeric_limits<float>::max() //3.40282e+38
# define MIN_DOUBLE std::numeric_limits<double>::min() //-1.79769e+308
# define MAX_DOUBLE std::numeric_limits<double>::max() //1.79769e+308

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