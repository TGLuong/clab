#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <mosquitto.h>
#include <signal.h>
#include "mqtt.h"

using namespace std;

int main() {
    mosquitto_lib_init();

    Mqtt prod; 
    prod.create_new();
    prod.connect("localhost", 1883);

    while (true) {
        int temp = rand() % 100;
        cout << "temp: " << temp << endl;
        prod.publish("temp/kitchen/sensor1", temp);
        usleep(200000);
    }

    prod.disconnect();
    prod.destroy();
    mosquitto_lib_cleanup();
    return 0;
}
