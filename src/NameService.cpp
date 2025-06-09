#include <NameService.h>

void NameService::add(const String& name, const uint8_t* addr) {
    std::array<uint8_t, ADDRESS_SIZE> copy;
    for (size_t i = 0; i < ADDRESS_SIZE; ++i) {
        copy[i] = addr[i];
    }
    address_table[name] = copy;
}

bool NameService::exists(const String& name) const {
    return address_table.count(name) > 0;
}

const uint8_t* NameService::get(const String& name) const {
    auto it = address_table.find(name);
    if (it != address_table.end()) {
        return it->second.data();
    }
    return nullptr;
}

void NameService::remove(const String& name) {
    address_table.erase(name);
}
