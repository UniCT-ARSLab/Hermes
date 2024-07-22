#include <Arduino.h>
#include <HermesEspNow.h>
#define DEVICE_NAME "Bob"
#define CHANNEL 1

HermesEspNow *mnet;
static Message message(DEFAULT_MESSAGE, (uint8_t *)"Hello\0", 6);

void recv_cb(const uint8_t *addr, const uint8_t *payload, int len) {
    Message m(payload, len);

    switch (m.type) {
    case WHOIS_REQUEST_MESSAGE:
        mnet->handle_whois_request(addr, &m);
        break;
    case WHOIS_ANSWER_MESSAGE:
        Serial.println("Received a WHOSIS_ANSWER_MESSAGE");
        mnet->handle_whois_answer(addr, &m);
        break;
    case DEFAULT_MESSAGE:
        break;
    }
}

void setup() {
    Serial.begin(9600);
    HermesEspNow::init(DEVICE_NAME, CHANNEL);
    mnet = = HermesEspNow::get_instance();

    if (!mnet->start()) {
        while (1) {
            Serial.println("Error while starting Hermes");
        }
    }

    if (!mnet->register_recv_cb(recv_cb)) {
        while (1) {
            Serial.println("Error while registering recv callback function.");
        }
    }
}

void loop() {
    Serial.print("Sending a message...");

    if (!mnet->send("Alice", &message)) {
        Serial.println("FAILED");
    } else {
        Serial.println("OK");
    }

    delay(1000);
}
