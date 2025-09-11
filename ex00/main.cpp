/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:03:44 by ufo               #+#    #+#             */
/*   Updated: 2025/09/11 15:10:42 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvertor.hpp"
#include  "SuppFuncs.hpp"

static void run(const char *s)
{
	std::string in = s ? s : "";
	std::cout << "\n=== \"" << in << "\" ===\n";
	ScalarConvertor::convert(in);
}

int main()
{
	const char *cases[] = {
		// char (single printable, non-digit)
		"a", " ", "~",

		// int (valid)
		"0", "7", "-0", "+42", "-2",
		"2147483647",       // INT_MAX
		"-2147483648",      // INT_MIN

		// int (overflow -> int: impossible; float/double ok)
		"2147483648",
		"-2147483649",
		"145234857923745",

		// double (valid)
		"42.0", "-3.5", "0.0",

		// float (valid, ends with 'f')
		"42.0f", "-3.5f", "0.0f",

		// pseudo (you said you’ll handle them now)
		"nan", "nanf", "+inf", "-inf", "+inff", "-inff",

		// invalid/malformed (should be typeInvalid)
		"", "1.2ff", "1..2", "1.2.3f", "f1", "+", "++42",
		" 42", "42 ", "1.", ".5", "2.f", "+.5f", "42f"
	};

	const size_t n = sizeof(cases) / sizeof(cases[0]);
	for (size_t i = 0; i < n; ++i)
		run(cases[i]);

	return 0;
}