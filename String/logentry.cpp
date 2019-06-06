

//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 
#include "logentry.hpp"



////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
LogEntry::LogEntry(String s) {
    std::vector<String> vec = s.split(' ');
    host=vec[0];
    request=vec[5];
    status=vec[8];
    number_of_bytes= strtonum(vec[9]);
    std::vector<String>timdate=vec[3].split(':');
    Time(timdate[1],timdate[2],timdate[3]);
    Date(timdate);
}
////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;
   while(!in.eof()){
    Stirng input;
    in.getline(input);
    result.push_back(LogEntry(input)); 
   } 
   return result;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void output_all(std::ostream& out, const std::vector<LogEntry> &) {
    
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void by_host(std::ostream& out, const std::vector<LogEntry>&) {

}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
int byte_count(const std::vector<LogEntry> &) {
    
    return 0;
}

