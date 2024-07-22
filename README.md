# Hermes
<img src="https://github.com/Herbrant/Hermes/assets/5670917/396558d0-086f-4ed7-b7bc-65ac7347c8d9" width="250">


**Hermes** is a simple ESP32 Arduino library that enables seamless message exchange over WiFi and LoRa. If you prefer to use the ESP-IDF framework library, have a look at [multi_esp_net](https://github.com/Herbrant/multi_esp_net).
## Table of Contents

1. [About the Project](#about-the-project)
1. [Project Status](#project-status)
1. [Getting Started](#getting-started)
	1. [Dependencies](#dependencies)
	1. [Usage](#usage)
1. [Authors](#authors)
1. [Acknowledgements](#acknowledgments)

# About the Project
The primary objective of this library is to offer a user-friendly API for programmers seeking to incorporate WiFi and LoRa networks into their IoT projects. The library facilitates the creation of a mesh network and enables seamless message exchange between nodes.

Currently, the library provides support for the following technologies:
- [ESP Now](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/network/esp_now.html)
- [WiFi Mesh](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/network/esp-wifi-mesh.html)
- [LoRa Mesh](https://jaimi5.github.io/LoRaMesher/)

**[Back to top](#table-of-contents)**

# Getting Started
## Dependencies

The library leverages the industry-standard Espressif IoT Development Framework [ESP-IDF](https://github.com/espressif/esp-idf) and [LoRaMesher](https://github.com/LoRaMesher/LoRaMesher). Refer to `library.json` for a detailed list of dependencies.

If you are using PlatformIO, simply add this library as a dependency in your platformio.ini file. PlatformIO will automatically resolve and install all necessary dependencies during compilation.

## Usage
To facilitate understanding of the library, it may be helpful to refer to the provided examples:
- [ESP NOW Examples](./examples/EspNow/)
- [WiFi Mesh Examples](./examples/WiFiMesh/)
- [LoRa Mesh Examples](./examples/LoRa/)

**[Back to top](#table-of-contents)**

# Authors

* **[Davide Carnemolla](https://github.com/Herbrant)** - [University of Catania](https://unict.it)
* **[Fabrizio Messina](https://github.com/fmes)** - [University of Catania](https://unict.it)
* **[Corrado Santoro](https://github.com/corradosantoro)** - [University of Catania](https://unict.it)
* **[Federico Fausto Santoro](https://github.com/fedyfausto)** - [University of Catania](https://unict.it)

**[Back to top](#table-of-contents)**

# Acknowledgments
This work is supported by the MIUR project "T-LADIES" under grant PRIN 2020TL3X8X.

**[Back to top](#table-of-contents)**
