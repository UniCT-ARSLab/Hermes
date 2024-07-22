#include <NameService.h>

NameService::~NameService() { this->address_table.clear(); }

void NameService::add(const String name, const uint8_t *addr) {
    this->address_table[name] = addr;
}

bool NameService::exists(const String name) {
    return this->address_table.count(name) > 0;
}

const uint8_t *NameService::get(const String name) {
    return this->address_table[name];
}

void NameService::remove(const String name) { this->address_table.erase(name); }
