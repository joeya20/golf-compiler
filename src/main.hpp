#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "lexer.hpp"
#include "util.hpp"
#include "parse.tab.hh"
#include "location.hh"

// colno defined in Flex-generated file
extern int colno;