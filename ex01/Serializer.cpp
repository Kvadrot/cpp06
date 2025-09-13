/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:06:51 by ufo               #+#    #+#             */
/*   Updated: 2025/09/13 13:27:36 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer:: Serializer() {
    
};

Serializer:: Serializer(const Serializer& )
{
    
}

Serializer Serializer:: operator=(const Serializer&) {
    return *this;
}

Serializer:: ~Serializer() {
    
}


//Static Funcs
uintptr_t Serializer:: serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer:: deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}