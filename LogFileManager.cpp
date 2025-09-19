#include "LogFileManager.h"
#include "LogFile.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

void LogFileManager::openLogFile(const std::string& filename) {
    auto it = logs.find(filename);
    if (it == logs.end()) {
        try {
            logs[filename] = std::make_unique<LogFile>(filename);
            std::cout << "로그 파일 열림: " << filename << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "로그 파일 열기 실패: " << e.what() << std::endl;
            throw;
        }
    } else {
        std::cout << "로그 파일 이미 열려 있음: " << filename << std::endl;
    }
}

void LogFileManager::writeLog(const std::string& filename, const std::string& msg) {
    auto it = logs.find(filename);
    if (it != logs.end()) {
        try {
            it->second->write(msg);
        } catch (const std::exception& e) {
            std::cerr << "로그 쓰기 실패: " << e.what() << std::endl;
        }
    } else {
        std::cerr << "로그 파일 없음: " << filename << std::endl;
    }
}

void LogFileManager::closeLogFile(const std::string& filename) {
    auto it = logs.find(filename);
    if (it != logs.end()) {
        logs.erase(it); // unique_ptr 자동 소멸 → 파일 닫힘
        std::cout << "로그 파일 닫힘: " << filename << std::endl;
    } else {
        std::cerr << "닫을 로그 파일 없음: " << filename << std::endl;
    }
}

std::vector<std::string> LogFileManager::readLogs(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream infile(filename);

    if (!infile.is_open()) {
        throw std::runtime_error("파일을 열 수 없습니다: " + filename);
    }

    std::string line;
    while (std::getline(infile, line)) {
        lines.push_back(line);
    }

    return lines;
}
