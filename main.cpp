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
        auto logs = manager.readLogs("error.log");
        for (const auto& line : logs) {
            std::cout << line << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "읽기 실패: " << e.what() << std::endl;
    }

    manager.closeLogFile("error.log");

    return 0;
}
