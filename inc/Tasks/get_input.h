#ifndef GET_INPUT_H
#define GET_INPUT_H

#include <iostream>
#include "../Text.h"

void ignoreLine();

bool extraction_success();

unsigned get_unsigned(std::string);

float get_float(std::string);

std::string get_string(std::string);

#endif