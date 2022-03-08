// ALL Definations of the utils library
#include "../include/utils.hpp"
#include <iostream>
#include <cmath>

/*
 * Reverse integer
 *
 * @param n: the integer to be reversed
 * @return: the reversed integer
 * @note: the reversed integer is returned as a long long integer
 *       if the input integer is greater than or equal to 2^63-1
 * Time complexity: Big-O(n)
 */
std::int64_t utils::reverse_integer(std::int64_t n)
{
    std::int64_t reversed_integer = 0;
    std::int64_t lastdigit = 0;
    while (n != 0)
    {
        lastdigit = n % 10;                                   // Get the last digit: 125 % 10 = 5
        reversed_integer = reversed_integer * 10 + lastdigit; // reversed_integer = 0 * 10 + 5 = 5
        n /= 10;                                              // 125 / 10 = 12.5 -> 125 = 12
    }
    return reversed_integer;
}

/*
 * Check if an integer is an armstrong integer
 *
 * @param n: the integer to be checked
 * @return: true if the integer is an armstrong integer, false otherwise
 * Time complexity: Big-O(log(n))
 */
bool utils::is_armstrong_integer(std::int64_t n)
{
    std::int64_t lastdigit = 0, sum = 0, x = n;
    std::int64_t dig = log10(n) + 1; // Total number of digits of n
    while (n > 0)
    {
        lastdigit = n % 10;         // Get the last digit: 125 % 10 = 5
        sum += pow(lastdigit, dig); // sum = 0 + pow(5, 3) = pow(5, 3) = 125
        n /= 10;                    // 125 / 10 = 12.5 -> 125 = 12
    }
    return sum == x; // sum = 125, n = 125 os your integer is an armstrong integer
}