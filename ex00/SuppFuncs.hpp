/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuppFuncs.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:17:21 by ufo               #+#    #+#             */
/*   Updated: 2025/09/09 12:43:43 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// SuppFuncs.hpp
#ifndef SUPPFUNCS_HPP
#define SUPPFUNCS_HPP

#include <string>

bool isChar(const std::string &text);
bool isInt(const std::string &text);

TypeLiteral detectType(const std::string& text);


#endif // SUPPFUNCS_HPP