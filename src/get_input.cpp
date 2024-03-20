#include "../inc/get_input.h"
#include <limits> // for std::numeric_limits

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool extraction_success()
{
    if (!std::cin) // Has a previous extraction failed or overflowed?
    {
        if (std::cin.eof()) // If the stream was closed
        {
            exit(0); // Shut down the program now
        }

        // Yep, so let's handle the failure
        std::cin.clear(); // Put us back in 'normal' operation mode
        ignoreLine();

        return false;
    }
    return true;
}

unsigned get_unsigned()
{
    while (true) // Loop until user enters a valid input
    {
        unsigned x{};
        std::cin >> x;
        if (not extraction_success())
        {
            std::cout << ERROR_TEXT;
            continue;
        }

        ignoreLine(); // Remove any extraneous input
        return x;     // Return the value we extracted
    }
}

float get_float()
{
    while (true) // Loop until user enters a valid input
    {
        float x{};
        std::cin >> x;
        if (not extraction_success())
        {
            std::cout << "Oops, that input is invalid.  Please try again.\n";
            continue;
        }

        ignoreLine(); // Remove any extraneous input
        return x;     // Return the value we extracted
    }
}

std::string get_string()
{
    while (true) // Loop until user enters a valid input
    {
        std::string x{};
        std::cin >> x;
        if (not extraction_success())
        {
            std::cout << "Oops, that input is invalid.  Please try again.\n";
            continue;
        }

        ignoreLine(); // Remove any extraneous input
        return x;     // Return the value we extracted
    }
}