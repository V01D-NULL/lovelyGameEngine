# 3 standard logging methods -> info, warn, and err:

### EXAMPLE:
    lovely::logging::logger::info("test", NULL);

### !IMPORTANT!
 - ONLY STRINGS, 
 - MUST END WITH THE >NULL< keyword,
 - THERE IS NO LIMIT TO THE ARGUMENTS ONE CAN PASS TO THE FUNCTION

### Passing variables to the lovely logger:
 NOTE:
 - The string must be either a C style string, or converted to one
 - A non string datatype CAN be converted to a string (MUST be C style)
 
 DEMO:
 
 ```C++
    int a  = 4;
    std::string msg = "test"; //Or const char*
    std::string a_converted = std::to_string(a); //Convert 4 to "4"
    //Incase std::string is passed, use the .c_str() function.
    ...info(msg.c_str(), a_converted.c_str(), NULL);
```
