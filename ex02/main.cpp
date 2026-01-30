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
#include <string>
#include "MutantStack.hpp"

// Helper to print separator lines
static void printHeader(const std::string& title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "========================================" << std::endl;
}

static void subjectTest() {
    printHeader("Subject Test (Basic Stack & Iterator)");
    
    MutantStack<int> mstack;
    
    std::cout << "-> Pushing 5, 17" << std::endl;
    mstack.push(5);
    mstack.push(17);

    std::cout << "-> Top element: " << mstack.top() << std::endl;
    
    std::cout << "-> Popping top element" << std::endl;
    mstack.pop();
    
    std::cout << "-> Current size: " << mstack.size() << std::endl;

    std::cout << "-> Pushing 3, 5, 737, 0" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "-> Iterating from begin() to end():" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::cout << "-> Copy constructing std::stack from MutantStack (verification of inheritance)..." << std::endl;
    std::stack<int> s(mstack);
    std::cout << "OK" << std::endl;
}

static void compareWithList() {
    printHeader("Comparison Test (MutantStack vs std::list)");
    
    std::cout << "-> Filling MutantStack and std::list with: 1, 2, 3" << std::endl;
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

    std::cout << "-> Comparing iteration order and values..." << std::endl;
    bool same = true;
    for (; it != ite && lit != lite; ++it, ++lit) {
        if (*it != *lit) {
            same = false;
            std::cout << "MISMATCH: Stack " << *it << " vs List " << *lit << std::endl;
            break;
        }
    }
    
    if (same && it == ite && lit == lite) {
        std::cout << "SUCCESS: MutantStack iteration matches std::list perfectly." << std::endl;
    } else {
        std::cout << "FAILURE: Iteration did not match." << std::endl;
    }
}

static void reverseIteratorTest() {
    printHeader("Reverse Iterator Test");
    
    MutantStack<int> mstack;
    std::cout << "-> Pushing 0, 1, 2, 3, 4" << std::endl;
    for (int i = 0; i < 5; ++i) {
        mstack.push(i);
    }

    std::cout << "-> Iterating from rbegin() to rend():" << std::endl;
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
