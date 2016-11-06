//
//  Log.cpp
//  First Fantasy
//
//  Created by Alex on 11/4/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <ctime>

#include "Log.hpp"

static std::ofstream fout;

void setLogFile(std::string filename)
{
    fout.open(filename, std::ios::out | std::ios::app);
}

void log(LogLevel ll, std::string msg)
{
    time_t rawtime;
    struct tm *timeinfo;
    constexpr int buffer_size = 64;
    char buffer[buffer_size] = {'\0'};
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    strftime(buffer, buffer_size, "%F %X", timeinfo);
    
    std::string logMsg(buffer, buffer_size);
    logMsg += " ";
    logMsg += msg;
    
    std::ostream *out = nullptr;
    if (ll == LogLevel::ERROR) {
        out = &std::cerr;
    } else {
        out = &std::cout;
    }
    
    *out << logMsg << std::endl;
    fout << logMsg << std::endl;
}
