/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:53:55 by ufo               #+#    #+#             */
/*   Updated: 2025/09/13 13:26:50 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main(void) {
	//prepair main
	
	Data testData;
	testData.num = 42;
	testData.text = "Duda";
	
	std::cout << "origin pointer testdata: " << &testData << std::endl;
	std::cout << "holding values: " << "text = " << testData.text;
	std::cout << " num = " << testData.num << std::endl;

	//Serialization
	uintptr_t raw = Serializer::serialize(&testData);
	std::cout << "serialized data: " << raw << std::endl;

	//Deserialized
	Data* ptrToData;
	ptrToData = Serializer::deserialize(raw);
	std::cout << "Desirialized ptr: " << ptrToData << std::endl;
	std::cout << "holding values: " << "text = " << testData.text;
	std::cout << " num = " << testData.num << std::endl;

	if (ptrToData == &testData)
        std::cout << "Success: pointer restored correctly!" << std::endl;
    else
        std::cout << "Error: pointer mismatch!" << std::endl;
}