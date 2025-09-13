/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:09:39 by ufo               #+#    #+#             */
/*   Updated: 2025/09/13 14:36:13 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>  // rand
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
    int r = std::rand() % 3;
    if (r == 0) return new A();
    if (r == 1) return new B();
    return new C();
}

void identify(Base* p) {
    if (p == NULL) {
        std::cout << "pointer is empty" << std::endl;
        return;
    }

    if (dynamic_cast<A*>(p)) {
        std::cout << "given pointer is: Class A" << std::endl;
        return;
    }
    else if (dynamic_cast<B*>(p)) {
        std::cout << "given pointer is: Class B" << std::endl;
        return;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "given pointer is: Class C" << std::endl;
        return;
    }
}

void identify(Base& p) {
    try {
        (void) dynamic_cast<A&>(p);
        std::cout << "given pointer is: Class A " << std::endl;
        return;
    } catch (std::bad_cast) {
        std::cout << "error during casting to A";
    }
    
    try {
        (void) dynamic_cast<B&>(p);
        std::cout << "given pointer is: Class B " << std::endl;
        return;
    } catch (std::bad_cast) {
        std::cout << "error during casting to B ";
    }

    try {
        (void) dynamic_cast<C&>(p);
        std::cout << "given pointer is: Class B " << std::endl;
        return;
    } catch (std::bad_cast) {
        std::cout << "error during casting to B ";
    }
    std::cout << "Unknown\n";
}

int main() {
    std::srand(std::time(0)); // seed rand once

    for (int i = 0; i < 5; i++) {
        std::cout << "=== Test " << i + 1 << " ===" << std::endl;

        Base* obj = generate();

        std::cout << "identify(Base*): ";
        identify(obj);

        std::cout << "identify(Base&): ";
        identify(*obj);

        delete obj;
        std::cout << std::endl;
    }

    return 0;
}