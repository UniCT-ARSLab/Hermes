#ifndef MULTI_ESP_NET_NAME_SERVICE_H
#define MULTI_ESP_NET_NAME_SERVICE_H
#include <Arduino.h>
#include <Message.h>
#include <map>
#include <array>

#if defined(PROTOCOLTYPE_LORA)
  #define ADDRESS_SIZE 2
#elif defined(PROTOCOLTYPE_WIFI)
  #define ADDRESS_SIZE 6
#elif defined(PROTOCOLTYPE_ESPNOW)
  #define ADDRESS_SIZE 6
#else
  #define ADDRESS_SIZE 0
  #warning "PROTOCOLTYPE not defined (usage -DPROTOCOLTYPE_LORA, _WIFI, or _ESPNOW)"
#endif

class NameService {
public:
    ~NameService() = default;

    void add(const String& name, const uint8_t* addr);
    bool exists(const String& name) const;
    const uint8_t* get(const String& name) const;
    void remove(const String& name);

    // TODO : make private and add setter
    std::map<String, std::array<uint8_t, ADDRESS_SIZE>> address_table;
};

#endif