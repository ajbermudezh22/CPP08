/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:36:11 by albbermu          #+#    #+#             */
/*   Updated: 2026/01/27 15:36:11 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

static void subjectTest() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

static void compareWithList() {
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    MutantStack<int>::const_iterator it = mstack.begin();
    MutantStack<int>::const_iterator ite = mstack.end();
    std::list<int>::const_iterator lit = lst.begin();
    std::list<int>::const_iterator lite = lst.end();

    bool same = true;
    for (; it != ite && lit != lite; ++it, ++lit) {
        if (*it != *lit) {
            same = false;
            break;
        }
    }
    if (it != ite || lit != lite) {
        same = false;
    }
    std::cout << "same output as list: " << (same ? "yes" : "no") << std::endl;
}

static void reverseIteratorTest() {
    MutantStack<int> mstack;
    for (int i = 0; i < 5; ++i) {
        mstack.push(i);
    }
    std::cout << "reverse: ";
    MutantStack<int>::reverse_iterator it = mstack.rbegin();
    MutantStack<int>::reverse_iterator ite = mstack.rend();
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

int main() {
    subjectTest();
    compareWithList();
    reverseIteratorTest();
    return 0;
}
