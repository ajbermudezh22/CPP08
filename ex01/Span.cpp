/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:35:58 by albbermu          #+#    #+#             */
/*   Updated: 2026/01/27 15:35:58 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span() : _capacity(0), _values() {}

Span::Span(unsigned int n) : _capacity(n), _values() {
    _values.reserve(n);
}

Span::Span(const Span &other) : _capacity(other._capacity), _values(other._values) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _capacity = other._capacity;
        _values = other._values;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
    if (_values.size() >= _capacity) {
        throw FullException();
    }
    _values.push_back(value);
}

int Span::shortestSpan() const {
    if (_values.size() < 2) {
        throw NotEnoughNumbersException();
    }
    std::vector<int> sorted = _values;
    std::sort(sorted.begin(), sorted.end());

    long long best = static_cast<long long>(sorted[1]) - sorted[0];
    for (std::vector<int>::size_type i = 2; i < sorted.size(); ++i) {
        long long diff = static_cast<long long>(sorted[i]) - sorted[i - 1];
        if (diff < best) {
            best = diff;
        }
    }
    return static_cast<int>(best);
}

int Span::longestSpan() const {
    if (_values.size() < 2) {
        throw NotEnoughNumbersException();
    }
    std::vector<int>::const_iterator minIt = std::min_element(_values.begin(), _values.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_values.begin(), _values.end());
    return *maxIt - *minIt;
}

unsigned int Span::size() const {
    return static_cast<unsigned int>(_values.size());
}
