#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <ctime>
#include <iomanip>


class Logger {
public:
    enum class Level { ERROR, WARNING, INFO, DEBUG };

    static Logger& getInstance(const std::string& filename = "logfile.txt") {
        static Logger instance(filename);
        return instance;
    }


    static void LOG(const std::string& message, Level level) {
        getInstance().log(message, level);
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;

    void log(const std::string& message, Level level) {
        if (level > currentLevel) return;

        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&now_c), "[%Y-%m-%d %H:%M:%S]");

        std::string levelStr = levelToString(level);

        if (logFile.is_open()) {
            logFile << ss.str() << ' ' << levelStr << ": " << message << '\n';
            logFile.flush();
        } else {
            std::cerr << "Error: could not open logger file :(" << std::endl;
        }
    }

    void setLevel(Level level) {
        currentLevel = level;
        log("Logger level has been successfully set to " + levelToString(level), Level::INFO);
    }

private:
    std::ofstream logFile;
    Level currentLevel = Level::INFO;


    Logger(const std::string& filename) {
        logFile.open(filename, std::ios::out | std::ios::trunc);
        if (logFile.is_open()) {
            std::cout << "Logger has been successfully initialized! The data is being written to file --" << filename << "--" << std::endl;
        } else {
            std::cerr << "Error: could not open logger file :( --" << filename << "--" << std::endl;
        }
    }


    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
            std::cout << "Logger file has been successfully closed!" << std::endl;
        }
    }

    std::string levelToString(Level level) const {
        switch (level) {
            case Level::ERROR: return "[ERROR]";
            case Level::WARNING: return "[WARN]";
            case Level::INFO: return "[INFO]";
            case Level::DEBUG: return "[DEBUG]";
        }
        return "[UNKNOWN]";
    }
};


class TrackedString {
private:
    std::string value;
    size_t id;
    static size_t objectCount;

    void logCtor(const std::string& type, const TrackedString* other = nullptr) {
        std::stringstream ss;
        ss << "[" << type << "] $id=" << id << "$ this=" << this;
        if (other) {
            ss << " from $id=" << other->id << "$";
        }
        ss << " value=\"" << value << "\"";
        Logger::LOG(ss.str(), Logger::Level::DEBUG);
    }

public:
    static size_t createdObjectCount() { return objectCount; }

    TrackedString() : TrackedString(std::string("")) {
        id = ++objectCount;
        logCtor("default ctor");

    }

    TrackedString(const char* s) : TrackedString(std::string(s)) {
        id = ++objectCount;
        logCtor("const char* ctor");
    }

    TrackedString(const std::string& s) : value(s) {
        id = ++objectCount;
        logCtor("std::string ctor");
    }

    TrackedString(const TrackedString& other) : value(other.value) {
        id = ++objectCount;
        logCtor("copy ctor", &other);
    }

    TrackedString(TrackedString&& other) noexcept : value(other.value), id(other.id) {
        other.id = 0; 
        logCtor("move ctor", &other);
    }
    
    TrackedString& operator=(const TrackedString& other) {
        if (this != &other) {
            value = other.value;
            std::stringstream ss;
            ss << "[copy assign] $id=" << id << "$ this=" << this 
               << " from $id=" << other.id << "$ value=\"" << value << "\"";
            Logger::LOG(ss.str(), Logger::Level::DEBUG);
        }
        return *this;
    }

    TrackedString& operator=(TrackedString&& other) noexcept {
        if (this != &other) {
            value = other.value;
            other.id = 0;
            std::stringstream ss;
            ss << "[move assign] $id=" << id << "$ this=" << this 
               << " (moved-from object ID reset)";
            Logger::LOG(ss.str(), Logger::Level::DEBUG);
        }
        return *this;
    }

    ~TrackedString() {
        std::stringstream ss;
        ss << "[dtor] $id=" << id << "$ this=" << this << " value=\"" << value << "\"";
        Logger::LOG(ss.str(), Logger::Level::DEBUG);
    }

    const std::string& getValue() const { return value; }
    size_t getId() const { return id; }

    friend std::ostream& operator<<(std::ostream& os, const TrackedString& ts) {
        std::stringstream ss;
        ss << "[op<<] $id=" << ts.id << "$ value=\"" << ts.value << "\"";
        Logger::LOG(ss.str(), Logger::Level::DEBUG);
        os << ts.value;
        return os;
    }

    friend bool operator==(const TrackedString& lhs, const TrackedString& rhs) {
        std::stringstream ss;
        ss << "[op==] Compare $id=" << lhs.id << "$ and $id=" << rhs.id << "$";
        Logger::LOG(ss.str(), Logger::Level::DEBUG);
        return lhs.value == rhs.value;
    }
    
    friend bool operator!=(const TrackedString& lhs, const TrackedString& rhs) {
        std::stringstream ss;
        ss << "[op!=] Compare $id=" << lhs.id << "$ and $id=" << rhs.id << "$";
        Logger::LOG(ss.str(), Logger::Level::DEBUG);
        return !(lhs == rhs);
    }
    
    friend bool operator<(const TrackedString& lhs, const TrackedString& rhs) {
        std::stringstream ss;
        ss << "[op<] Compare $id=" << lhs.id << "$ and $id=" << rhs.id << "$";
        Logger::LOG(ss.str(), Logger::Level::DEBUG);
        return lhs.value < rhs.value;
    }

    friend TrackedString operator+(const TrackedString& lhs, const TrackedString& rhs) {
        std::stringstream ss;
        ss << "[op+] Add $id=" << lhs.id << "$ and $id=" << rhs.id << "$";
        Logger::LOG(ss.str(), Logger::Level::DEBUG);
        return TrackedString(lhs.value + rhs.value);
    }
};

size_t TrackedString::objectCount = 0;


class Wrapper {
private:
    TrackedString str;

public:
    static Wrapper create_variant_A(const std::string& s) {
        Logger::LOG("[Wrapper::ctor] Start of the variant A", Logger::Level::INFO);
        Wrapper w; 
        w.str = TrackedString(s);
        Logger::LOG("[Wrapper::ctor] End of the variant A", Logger::Level::INFO);
        return w;
    }

    Wrapper(const std::string& s)
    : str(s)
    {
        Logger::LOG("[Wrapper::ctor] End of the variant B", Logger::Level::INFO);
    }

    Wrapper() {
        Logger::LOG("[Wrapper::internal_default_ctor]", Logger::Level::DEBUG);
    }
    
    ~Wrapper() {
        Logger::LOG("[Wrapper::dtor]", Logger::Level::DEBUG);
    }
};

void task_2() {
    Logger::LOG("--// The compliance of the task 2 has started //--", Logger::Level::INFO);
    
    TrackedString a; 
    TrackedString b("hello");
    std::string s = "world";
    TrackedString c(s);
    TrackedString d = c; 
    

    Logger::LOG("--// The compliance of the task 2 has ended //--", Logger::Level::INFO);
}

void task_3() {
    Logger::LOG("--// The compliance of the task 3 has started //--", Logger::Level::INFO);

    Logger::LOG(">> start variant A - without init list", Logger::Level::INFO);
    Wrapper w1 = Wrapper::create_variant_A("variant A value"); 
    Logger::LOG("<< end variant A - without init list", Logger::Level::INFO);

    Logger::LOG(">> start variant B - with init list", Logger::Level::INFO);
    Wrapper w2("variant B value"); 
    Logger::LOG("<< end variant B - with init list", Logger::Level::INFO);

    Logger::LOG("--// The compliance of the task 3 has ended //--", Logger::Level::INFO);
}

void task4() {
    Logger::LOG("--// The compliance of the task 4 has started //--", Logger::Level::INFO);
    
    Logger::LOG(">> default delegating constructor", Logger::Level::INFO);
    TrackedString x;  
    
    Logger::LOG(">> const char* delegating constructor", Logger::Level::INFO);
    TrackedString y("test");
    
    Logger::LOG("--// The compliance of the task 4 has ended //--", Logger::Level::INFO);
}


void task_5() {
    Logger::LOG("--// The compliance of the task 5 has started //--", Logger::Level::INFO);

    std::vector<TrackedString> vec;

    Logger::LOG(">> push_back(temp)", Logger::Level::INFO);
    vec.push_back(TrackedString("temp"));

    Logger::LOG(">> push_back(not temp)", Logger::Level::INFO);
    TrackedString ts("str");
    vec.push_back(ts);
    
    Logger::LOG(">> emplace_back(...)", Logger::Level::INFO);
    vec.emplace_back("emplaced"); 

    Logger::LOG("--// The compliance of the task 5 has ended //--", Logger::Level::INFO);
}

void task_6() {
    Logger::LOG("--// The compliance of the task 6 has started //--", Logger::Level::INFO);

    TrackedString a("hello");
    TrackedString b("world");

    std::cout << a << " " << b << std::endl; 

    std::cout << ">> Comparisons" << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a < b: " << (a < b) << "<<" << std::endl;

    std::cout << "Addition" << std::endl;
    auto c = a + b; 
    
    std::cout << c << std::endl;

    Logger::LOG("--// The compliance of the task 6 has ended //--", Logger::Level::INFO);
}

int main() {
    auto& logger = Logger::getInstance("logfile.txt");
    logger.setLevel(Logger::Level::DEBUG);

    std::cout << "State before compliances of tests = " << TrackedString::createdObjectCount() << std::endl;
    
    task_2();

    task_3();

    task4();

    task_5();

    task_6();

    std::cout << "State after test = " << TrackedString::createdObjectCount() << std::endl;
    std::cout << "All operations have been successfully completed (results find here logfile.txt)! hooray" << std::endl;
    
    return 0;
}
