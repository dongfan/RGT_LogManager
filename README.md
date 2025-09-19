# RGT_LogManager
스파트 포인터를 활용한 리소스 관리

/project
│
├─ README.md            # 과제 설명, 빌드/실행 방법, 구현 특징
├─ main.cpp             # 테스트용 실행 파일
├─ LogFile.h            # LogFile 클래스 헤더
├─ LogFile.cpp          # LogFile 클래스 구현
├─ LogFileManager.h     # LogFileManager 클래스 헤더
├─ LogFileManager.cpp   # LogFileManager 클래스 구현

## 프로젝트 개요
스마트 포인터를 활용하여 여러 로그 파일을 안전하게 관리하는 C++ 프로그램입니다.
- RAII 기반 파일 핸들 관리
- 타임스탬프 포함 로그 기록
- 예외 안전성 보장
- 로그 파일 내용 읽기 기능 포함

주요 기능
- openLogFile(filename) : 새 파일 생성 또는 기존 파일 열기
- writeLog(filename, msg) : 로그 기록 (타임스탬프 포함)
- closeLogFile(filename) : 파일 닫기
- readLogs(filename) : 파일 내용을 std::vector<std::string>으로 읽기

## 빌드 및 실행
```bash
g++ -std=c++17 main.cpp LogFile.cpp LogFileManager.cpp -o LogTest
./LogTest
