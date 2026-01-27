/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:35:52 by albbermu          #+#    #+#             */
/*   Updated: 2026/01/27 15:35:52 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

static void runSubjectExample() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "longest: " << sp.longestSpan() << std::endl;
}

static void runBulkTest() {
    const unsigned int count = 10000;
    Span sp(count);
    std::vector<int> values;
    values.reserve(count);

    std::srand(static_cast<unsigned int>(std::time(0)));
    for (unsigned int i = 0; i < count; ++i) {
        values.push_back(std::rand() % 100000);
    }
    sp.addRange(values.begin(), values.end());

    std::cout << "bulk size: " << sp.size() << std::endl;
    std::cout << "bulk shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "bulk longest: " << sp.longestSpan() << std::endl;
}

static void runExceptionTests() {
    Span sp(2);
    try {
        sp.shortestSpan();
    } catch (const std::exception &e) {
        std::cout << "shortestSpan exception: " << e.what() << std::endl;
    }

    sp.addNumber(1);
    try {
        sp.longestSpan();
    } catch (const std::exception &e) {
        std::cout << "longestSpan exception: " << e.what() << std::endl;
    }

    sp.addNumber(2);
    try {
        sp.addNumber(3);
    } catch (const std::exception &e) {
        std::cout << "addNumber exception: " << e.what() << std::endl;
    }
}

int main() {
    runSubjectExample();
    runExceptionTests();
    runBulkTest();
    return 0;
}
