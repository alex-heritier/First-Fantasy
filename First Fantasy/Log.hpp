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

enum class LogType {
    DBG,
    INFO,
    WARN,
    ERROR
};

class Logger {
public:
    Logger(LogType);
    void put(std::string);
    static void setLogFile(std::string);
protected:
    Logger();
    void _log(std::ostream &, std::string &, bool);
    static std::ofstream fout;
    LogType logType;
};

#endif /* Log_hpp */
