#ifndef MULTI_ESP_NET_NAME_SERVICE_H
#define MULTI_ESP_NET_NAME_SERVICE_H
#include <Arduino.h>
#include <Message.h>
#include <map>
#include <array>

class NameService {
public:
    static constexpr size_t ADDRESS_SIZE = 2; // As for LoraMesher address specs

    ~NameService() = default;

    void add(const String& name, const uint8_t* addr);
    bool exists(const String& name) const;
    const uint8_t* get(const String& name) const;
    void remove(const String& name);

    std::map<String, std::array<uint8_t, ADDRESS_SIZE>> address_table;
};

#endif