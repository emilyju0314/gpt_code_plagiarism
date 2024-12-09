#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

enum { PATTERN_1, PATTERN_2, PATTERN_3, PATTERN_4 };
typedef size_t variation_t;


bool can_match(
    const std::string &str, size_t offset, size_t size,
    const std::string &query)
{
    for (int i = 0; i < size; ++i)
        if (str.at(offset + i) != 'x' and
            str.at(offset + i) != query.at(i))
            return false;

    return true;
}


bool all_zero(const std::string &byte, size_t offset, size_t size)
{
    for (int i = offset; i < offset + size; ++i)
        if (byte.at(i) != '0')
            return false;
    return true;
}


variation_t variation(const std::string &byte, size_t offset, size_t size)
{
    size_t count(0);
    
    for (size_t i = offset; i < offset + size; ++i)
        if (byte.at(i) == 'x')
            ++count;
    
    return (variation_t)(std::pow(2.0, (double)count)) % 1000000;
}


bool can_be_pattern_of(
    int pattern, std::vector<std::string> &input, size_t offset)
{
#define getbyte(i) input.at(offset + i)
    switch (pattern)
    {
    case PATTERN_1:
        if (input.size() - offset >= 1)
        {
            char c = getbyte(0).at(0);
            return (c == '0') or (c == 'x');
        }
        
    case PATTERN_2:
        if (input.size() - offset >= 2)
        {
            return
                can_match(getbyte(0), 0, 3, "110")
                and can_match(getbyte(1), 0, 2, "10")
                and not all_zero(getbyte(0), 3, 4);
        }
        break;
        
    case PATTERN_3:
        if (input.size() - offset >= 3)
        {
            return
                can_match(getbyte(0), 0, 4, "1110")
                and can_match(getbyte(1), 0, 2, "10")
                and can_match(getbyte(2), 0, 2, "10")
                and (not all_zero(getbyte(0), 4, 4) or
                     not all_zero(getbyte(1), 2, 1));
        }
        
    case PATTERN_4:
        if (input.size() - offset >= 4)
        {
            return
                can_match(getbyte(0), 0, 5, "11110")
                and can_match(getbyte(1), 0, 2, "10")
                and can_match(getbyte(2), 0, 2, "10")
                and can_match(getbyte(3), 0, 2, "10")
                and (not all_zero(getbyte(0), 5, 3) or
                     not all_zero(getbyte(1), 2, 2));
        }
    }
    
    return false;
#undef getbyte
}


variation_t count(
    std::vector<std::string> &input, size_t offset,
    std::map<size_t, variation_t> *memo)
{
    if (offset >= input.size()) return 1;

    std::map<size_t, variation_t>::iterator found = memo->find(offset);
    if (found != memo->end())
        return found->second;
    
#define getbyte(i) input.at(offset + i)
    variation_t out(0);

    if (can_be_pattern_of(PATTERN_1, input, offset))
    {
        variation_t var_x = variation(getbyte(0), 1, 7);
        out += var_x * count(input, offset + 1, memo);
        out %= 1000000;
    }
    
    if (can_be_pattern_of(PATTERN_2, input, offset))
    {
        variation_t var_x =
            variation(getbyte(0), 7, 1) *
            variation(getbyte(1), 2, 6);

        variation_t var_y = variation(getbyte(0), 3, 4);
        if (getbyte(0).substr(3, 4).find('1') == std::string::npos)
            --var_y;
                
        out += var_x * var_y * count(input, offset + 2, memo);
        out %= 1000000;
    }
    
    if (can_be_pattern_of(PATTERN_3, input, offset))
    {
        variation_t var_x =
            variation(getbyte(1), 3, 5) *
            variation(getbyte(2), 2, 6);

        variation_t var_y =
            variation(getbyte(0), 4, 4) *
            variation(getbyte(1), 2, 1);
        if (getbyte(0).substr(4, 4).find('1') == std::string::npos
            and getbyte(1).at(2) != '1')
            --var_y;
                
        out += var_x * var_y * count(input, offset + 3, memo);
        out %= 1000000;
    }
    
    if (can_be_pattern_of(PATTERN_4, input, offset))
    {
        variation_t var_x =
            variation(getbyte(1), 4, 4) *
            variation(getbyte(2), 2, 6) *
            variation(getbyte(3), 2, 6);

        variation_t var_y =
            variation(getbyte(0), 5, 3) *
            variation(getbyte(1), 2, 2);
        if (getbyte(0).substr(5, 3).find('1') == std::string::npos
            and getbyte(1).substr(2, 2).find('1') == std::string::npos)
            --var_y;
                
        out += var_x * var_y * count(input, offset + 4, memo);
        out %= 1000000;
    }

    (*memo)[offset] = out; // MEMORIZE
        
    return out;
#undef getbyte
}


int main()
{
    while (true)
    {
        int n;
        std::cin >> n;

        if (n == 0) break;

        std::vector<std::string> input;
        for (int i = 0; i < n; ++i)
        {
            input.push_back(std::string());
            std::cin >> input.back();
        }

        std::map<size_t, variation_t> memo;
        std::cout << count(input, 0, &memo) << std::endl;
    }
    
    return 0;
}