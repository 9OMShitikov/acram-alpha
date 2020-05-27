#ifndef DIFFERENTIATOR_MY_ASSERT_H
#define DIFFERENTIATOR_MY_ASSERT_H

#include <cstdio>
#include <iostream>
#ifndef PRINT_CHECKING
#define ASSERT(expr) if (!(expr)) throw std::exception()
#else
#define ASSERT(expr) std::cout<<"Checking " << #expr << std::endl; if (!(expr)) throw std::exception()
#endif

#endif //DIFFERENTIATOR_MY_ASSERT_H
