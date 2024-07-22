#ifndef MULTI_ESP_NET_NAME_SERVICE_H
#define MULTI_ESP_NET_NAME_SERVICE_H
#include <Arduino.h>
#include <Message.h>
#include <map>

class NameService {
  public:
    std::map<String, const uint8_t *> address_table;
    ~NameService();

    void add(const String name, const uint8_t *addr);
    bool exists(const String name);
    const uint8_t *get(const String name);
    void remove(const String name);
};

#endif