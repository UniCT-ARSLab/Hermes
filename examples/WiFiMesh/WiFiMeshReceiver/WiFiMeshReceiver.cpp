#include <Arduino.h>
#include <HermesWiFiMesh.h>
#define DEVICE_NAME "Alice"
#define NET_ID "TESTNET"
#define CHANNEL 1
#define IS_ROOT false
#define MAX_CONNECTIONS 10

HermesWiFiMesh *mnet;
static uint8_t counter = 0;

void recv_cb(const uint8_t *addr, const uint8_t *payload, int len) {
    Message m(payload, len);

    switch (m.type) {
    case WHOIS_REQUEST_MESSAGE:
        Serial.println("Received: WHOIS REQUEST");
        mnet->handle_whois_request(addr, &m);
        break;
    case WHOIS_ANSWER_MESSAGE:
        Serial.println("Received: WHOIS ANSWER");
        mnet->handle_whois_answer(addr, &m);
        break;
    case DEFAULT_MESSAGE:
        counter++;
        Serial.printf("Packet received: %s\n", (char *)m.buffer);
        break;
    }
}

void setup() {
    Serial.begin(9600);
    HermesWiFiMesh::init(DEVICE_NAME, NET_ID, CHANNEL, IS_ROOT,
                         MAX_CONNECTIONS);
    mnet = HermesWiFiMesh::get_instance();

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
    Serial.println("Waiting for a message...");
    delay(5000);
}