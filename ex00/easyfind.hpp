/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:35:43 by albbermu          #+#    #+#             */
/*   Updated: 2026/01/27 15:35:43 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class EasyFindNotFoundException : public std::exception {
public:
    virtual const char *what() const throw() {
        return "easyfind: value not found";
    }
};

template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw EasyFindNotFoundException();
    }
    return it;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw EasyFindNotFoundException();
    }
    return it;
}

#endif
