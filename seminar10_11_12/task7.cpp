#include <iostream>
#include <string>
#include <vector>

enum class LogLevel {
    DEBUG = 1 << 0, INFO = 1 << 1, WARNING = 1 << 2, ERROR = 1 << 3, CRITICAL = 1 << 4
};

LogLevel operator|(LogLevel _per1, LogLevel _per2) {
    return (LogLevel)(((int)(_per1) | (int)(_per2)));
}

LogLevel operator&(LogLevel _per1, LogLevel _per2) {
    return (LogLevel)(((int)(_per1) & (int)(_per2)));
}

LogLevel operator~(LogLevel _per) {
    return (LogLevel)((int)(_per));
}

enum class LogCategory {
    NETWORK = 1 << 0, DATABASE = 1 << 1, UI = 1 << 2, SECURITY = 1 << 3, PERFORMANCE = 1 << 4
};

LogCategory operator|(LogCategory _per1, LogCategory _per2) {
    return (LogCategory)(((int)(_per1) | (int)(_per2)));
}

LogCategory operator&(LogCategory _per1, LogCategory _per2) {
    return (LogCategory)(((int)(_per1) & (int)(_per2)));
}

LogCategory operator~(LogCategory _per) {
    return (LogCategory)((int)(_per));
}

struct LogEntry {
    LogLevel level;
    LogCategory cat;
    //int timestamp;
    std::string mess;
};

void filterLogs(LogEntry _temp) {
    // if (static_cast<LogLevel>(1 << 0) == _temp.level) std::cout << "[DEBUG] " << _temp.cat 
    // if (static_cast<LogLevel>(1 << 1) == _temp.level) std::cout << "[INFO] " << _temp.cat << "] " << _temp.mess;
    // if (static_cast<LogLevel>(1 << 2) == _temp.level) std::cout << "[WARNING] [" << _temp.cat << "] " << _temp.mess;
    // if (static_cast<LogLevel>(1 << 3) == _temp.level) std::cout << "[ERROR] [" << _temp.cat << "] " << _temp.mess;
    // if (static_cast<LogLevel>(1 << 4) == _temp.level) std::cout << "[CRITICAL] [" << _temp.cat << "] " << _temp.mess;
    std::cout << _temp.mess;
}

void filterLogsHelp(LogCategory cat) {
    
}

int main() {
    LogEntry log1 = {LogLevel::INFO, LogCategory::NETWORK, "Соединение установлено"};
    LogEntry log2 = {LogLevel::ERROR, LogCategory::DATABASE, "Не удалось выполнить запрос"};
    LogEntry log3 = {LogLevel::DEBUG, LogCategory::UI, "Кнопка нажата"};
    LogEntry log4 = {LogLevel::CRITICAL, LogCategory::SECURITY, "Попытка несанкционированного доступа"};
    std::vector<LogEntry> logs = {log1, log2, log3, log4};
    for (auto& lo : logs) {
        filterLogs(lo);
    }
    LogLevel minLevel = LogLevel::WARNING;
    LogCategory activeCategories = LogCategory::DATABASE | LogCategory::SECURITY;
    
    return 0;
}