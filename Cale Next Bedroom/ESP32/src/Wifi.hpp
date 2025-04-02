#ifndef Wifi_HPP
#define Wifi_HPP

#include <Wifi.h>

class Wifi {
    private:
        const char* ssid;
        const char* password;
    
    public:
        Wifi(const char* ssid, const char* password);
        void connect();
        void getNetworkInfo();
        bool isConnected();
    };
    
    #endif 