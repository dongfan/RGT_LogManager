#include "LogFileManager.h"
#include <iostream>

int main() {
    LogFileManager manager;

    manager.openLogFile("error.log");
    manager.openLogFile("debug.log");
    manager.openLogFile("info.log");
    
    manager.writeLog("error.log", "Database connection failed");
    manager.writeLog("debug.log", "User login attempt");
    manager.writeLog("info.log", "Server started successfully");

    std::vector<std::string> errorLogs = manager.readLogs("error.log");

    try {
         for (const auto& log : errorLogs) {
        std::cout << log << std::endl; // "[2025-09-19 23:12:41] Database connection failed"
    }
    } catch (const std::exception& e) {
        std::cerr << "읽기 실패: " << e.what() << std::endl;
    }

    manager.closeLogFile("error.log");

    return 0;
}
