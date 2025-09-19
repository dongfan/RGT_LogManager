#pragma once
#include <memory>
#include <fstream>
#include <string>

class LogFile {
public:
    LogFile(const std::string& filename);
    void write(const std::string& msg);
    ~LogFile();

private:
    std::unique_ptr<std::ofstream> file;
};
