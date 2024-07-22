#include <Arduino.h>
#include <HermesLora.h>
#include <SPI.h>

// Set LoRa pins
#define LORA_IO1 33
#define DEVICE_NAME "Bob"

HermesLora *mnet;
static Message message(DEFAULT_MESSAGE, (uint8_t *)"Hello\0", 6);

void recv_cb(const uint8_t *addr, const uint8_t *payload, int len) {
    Message m(payload, len);

    switch (m.type) {
    case WHOIS_REQUEST_MESSAGE:
        Serial.println("Received a WHOIS_REQUEST_MESSAGE");
        mnet->handle_whois_request(addr, &m);
        break;
    case WHOIS_ANSWER_MESSAGE:
        Serial.println("Received a WHOIS_ANSWER_MESSAGE");
        mnet->handle_whois_answer(addr, &m);
        break;
    case DEFAULT_MESSAGE:
        Serial.println("Received a DEFAULT_MESSAGE");
        break;
    default:
        Serial.println("Received an unknown message type.");
        break;
    }
}

void setup() {
    Serial.begin(9600);
    SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI, SPI_SS);
    HermesLora::init(DEVICE_NAME, LORA_CS, LORA_IRQ, LORA_RST, LORA_IO1);
    mnet = HermesLora::get_instance();

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
