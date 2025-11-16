#include <iostream>
#include <string>
#include <vector>
//#include <wint.h>

enum class Event {
    LOGIN,
    LOGOUT,
    MESSAGESENT,
    FILEUPLOADED,
    ERROROCCURRED,
    PAYMENTRECEIVED,
    USERREGISTERED
};

//DEFINE_ENUM_FLAG

void handler(Event _event) {
    switch(_event) {
        case Event::LOGIN: 
            std::cout << "You've logged in successfully!!!\n";
            break;
        case 
            Event::LOGOUT: std::cout << "You've logged out successfully!!!\n";
            break;
        case 
            Event::MESSAGESENT: std::cout << "The mesage's been sent successfully!!!\n";
            break;
        case 
            Event::FILEUPLOADED: std::cout << "The file's been uploaded successfully!!!\n";
            break;
        case 
            Event::ERROROCCURRED: std::cout << "The error's been occured successfully!!!!!!! Hooray\n";
            break;
        case 
            Event::PAYMENTRECEIVED: std::cout << "The payment's been received successfully!!!\n";
            break;
        case 
            Event::USERREGISTERED: std::cout << "The user's been registered successfully!!!\n";
            break;
        default:
            std::cout << "Some really bad thing are hapening 0_0\n";
            break;
    };
}

int main() {
    std::vector<Event> events = {
        Event::LOGIN, 
        Event::MESSAGESENT,
        Event::ERROROCCURRED,
        static_cast<Event>(364528674)
    };
    for (auto& it : events) {
        handler(it);
    }
    return 0;
}