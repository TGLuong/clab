#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <mosquitto.h>
#include "inc/mqtt.h"

using namespace std;

void *thread_handler(void *param) {
    Mqtt *cons = (Mqtt*)param;
    int temp;
    while (1) {
        if (message_queue.size() > 0) {
            temp = cons->getMessage();
            cout << "temp: " << temp << endl;
            usleep(1000000);
        } 
    }
    return NULL;
}


int main() {
    mosquitto_lib_init();
    Mqtt cons;
    cons.create_new();
 
    for (int i = 1; i <= 5; i++) {
        pthread_t thread;
        pthread_create(&thread, NULL, thread_handler, &cons);
    }


    cons.connect("localhost", 1883);
    cons.subscribe("temp/kitchen/sensor1");
    cons.listen();

    cons.disconnect();
    cons.destroy();
    mosquitto_lib_cleanup();
    return 0;
}
