#include <iostream>
#include <string>

#include "Input.h"

char Input::get_input()
{
    std::string input;

    std::cin >> input;

    if (input.size() > 1)
        return 0;

    return input[0];
}