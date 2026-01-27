/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:35:47 by albbermu          #+#    #+#             */
/*   Updated: 2026/01/27 15:35:47 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

static void printResult(const char *label, int value, bool found) {
    std::cout << label << " -> ";
    if (found) {
        std::cout << "found " << value;
    } else {
        std::cout << "not found";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> v;
    v.push_back(3);
    v.push_back(7);
    v.push_back(42);

    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    std::deque<int> d;
    d.push_back(-1);
    d.push_back(0);
    d.push_back(1);

    try {
        easyfind(v, 42);
        printResult("vector", 42, true);
    } catch (const std::exception &) {
        printResult("vector", 42, false);
    }

    try {
        easyfind(l, 25);
        printResult("list", 25, true);
    } catch (const std::exception &) {
        printResult("list", 25, false);
    }

    try {
        std::deque<int>::const_iterator it = easyfind(d, 0);
        printResult("deque", *it, true);
    } catch (const std::exception &) {
        printResult("deque", 0, false);
    }

    const std::vector<int> cv(v);
    try {
        easyfind(cv, 7);
        printResult("const vector", 7, true);
    } catch (const std::exception &) {
        printResult("const vector", 7, false);
    }

    return 0;
}
