# 3 standard logging methods (Not programming methods) -> info, warn, and err:

### EXAMPLE:
    lovely::logging::logger::info(__FILE__, "test", NULL);

### !IMPORTANT!
 - The logger only accepts C style strings
 - The arguments must end with a null keyword
 - The logger is a variadic constructor class meaning there is no limit to the amount of arguments one can pass
 - For improved debugging purpose lovely's logging mechanism now expects __FILE__ as the first parameter. Please not that this isn't required but it is recommended (mainly because of the akward formatting you will get otherwise)

### Passing variables to the lovely logger:
 NOTE:
 - The string must be either a C style string, or be converted to one
 - A non string datatype CAN be converted to a string (MUST be C style)
 
 DEMO:
 
 ```C++
    int a  = 4;
    std::string msg = "test"; //Or const char*
    std::string a_converted = std::to_string(a); //Convert 4 to "4"
    //Incase std::string is passed, use the .c_str() function.
    ...info(__FILE__, msg.c_str(), a_converted.c_str(), NULL);
```
