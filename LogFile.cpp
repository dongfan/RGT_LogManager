#include "LogFile.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <stdexcept>

LogFile::LogFile(const std::string& filename) {
    file = std::make_unique<std::ofstream>(filename, std::ios::app);
    if (!file || !file->is_open()) {
        throw std::runtime_error("파일을 열 수 없습니다: " + filename);
    }
}

void LogFile::write(const std::string& msg) {
    if (!file || !file->is_open()) {
        throw std::runtime_error("파일이 열려 있지 않아 기록할 수 없습니다.");
    }

    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::tm tm{};
#if defined(_WIN32) || defined(_WIN64)
    localtime_s(&tm, &time);
#else
    localtime_r(&time, &tm);
#endif
    std::ostringstream oss;
    oss << std::put_time(&tm, "[%Y-%m-%d %H:%M:%S] ") << msg;

    (*file) << oss.str() << std::endl;

    if (!(*file)) {
        throw std::runtime_error("로그 쓰기 실패: 스트림 상태 오류");
    }
}

LogFile::~LogFile() {
    if (file && file->is_open()) {
        file->close();
    }
}
