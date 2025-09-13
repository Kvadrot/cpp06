/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:58:05 by ufo               #+#    #+#             */
/*   Updated: 2025/09/13 13:06:06 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <cstdint>

struct Data {
    std::string text;
    int num;
};

class Serializer {
  
  private:
    Serializer();
    Serializer(const Serializer& other);
    Serializer operator=(const Serializer& other);
    ~Serializer();

  public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif