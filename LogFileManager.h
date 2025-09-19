#pragma once
#include <unordered_map>
#include <memory>
#include <string>
#include <vector>
#include "LogFile.h"

class LogFileManager {
public:
    LogFileManager() = default;
    ~LogFileManager() = default;

    void openLogFile(const std::string& filename);
    void writeLog(const std::string& filename, const std::string& msg);
    void closeLogFile(const std::string& filename);

    // 로그 파일 내용 읽기
    std::vector<std::string> readLogs(const std::string& filename);

private:
    std::unordered_map<std::string, std::unique_ptr<LogFile>> logs;
};
