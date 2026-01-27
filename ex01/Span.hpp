#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iterator>

class Span {
public:
    class FullException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Span: capacity exceeded";
        }
    };

    class NotEnoughNumbersException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Span: not enough numbers";
        }
    };

    Span();
    explicit Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int value);

    template <typename InputIt>
    void addRange(InputIt first, InputIt last) {
        typename std::iterator_traits<InputIt>::difference_type dist =
            std::distance(first, last);
        if (dist < 0 || _values.size() + static_cast<unsigned int>(dist) > _capacity) {
            throw FullException();
        }
        _values.insert(_values.end(), first, last);
    }

    int shortestSpan() const;
    int longestSpan() const;

    unsigned int size() const;

private:
    unsigned int _capacity;
    std::vector<int> _values;
};

#endif
