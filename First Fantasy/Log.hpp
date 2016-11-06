//
//  Log.hpp
//  First Fantasy
//
//  Created by Alex on 11/4/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#ifndef Log_hpp
#define Log_hpp

#include <iostream>

enum class LogLevel {
    DBG,
    INFO,
    WARN,
    ERROR
};

void setLogFile(std::string);
void log(LogLevel, std::string);

#endif /* Log_hpp */
