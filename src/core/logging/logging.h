#pragma once

#include <iostream>
#include <string>
#include <stdarg.h>


namespace lovely
{
    namespace logging
    {

        class logger
        {
        public:
            class info
            {
            public:
                info(const char* arg, ...)
                {
                    va_list arguments;
                    
                    std::cout << "[INFO (";
                    bool printed_src_file = false;

                    for (va_start(arguments, arg); arg != NULL; arg = va_arg(arguments, const char *)) {
                        std::cout << arg << " ";
                        
                        if (!printed_src_file)
                        {
                            std::cout << "\b)]: ";
                            printed_src_file = true;
                        }
                    }

                    va_end(arguments);
                    std::cout << std::endl;
                }
                ~info() { std::cout << std::flush; }
            };
            
            class warn
            {
            public:
                warn(const char* arg, ...)
                {
                    va_list arguments;

                    bool printed_src_file = false;
                    std::cout << "[WARNING (";

                    for (va_start(arguments, arg); arg != NULL; arg = va_arg(arguments, const char *)) {
                        std::cout << arg << " ";

                        if (!printed_src_file)
                        {
                            std::cout << "\b)]: \x1B[33m";
                            printed_src_file = true;
                        }
                    }

                    va_end(arguments);
                    std::cout << "\033[0m" << std::endl;
                }
                ~warn() { std::cout << std::flush; }
            };
            
            class err
            {
            public:
                err(const char* arg, ...)
                {
                    va_list arguments;
                    bool printed_src_file = false;
                    std::cout << "[ERROR ("; //]: \x1B[31m

                    for (va_start(arguments, arg); arg != NULL; arg = va_arg(arguments, const char *)) {
                        std::cout << arg << " ";
                        
                        if (!printed_src_file)
                        {
                            std::cout << "\b)]: \x1B[31m";
                            printed_src_file = true;
                        }
                    }

                    va_end(arguments);
                    std::cout << "\033[0m" << std::endl;
                }
                ~err() { std::cout << std::flush; }
            };
            
        };
    }
}
