#include <stdio.h>
#include <mosquitto.h>


int main() {
    int rc;
    struct mosquitto * mosq;

    mosquitto_lib_init();

    mosq = mosquitto_new("publisher-new", true, NULL);

    rc = mosquitto_connect(mosq, "localhost", 1883, 60);

    if (rc != 0) {
        printf("Client could not connect to broker! Error code: %d\n", rc);
        mosquitto_destroy(mosq);
        return -1;
    }
    printf("Connect to to broker!\n");

    mosquitto_publish(mosq, NULL, "test/t1", 6, "Hello", 0, false);

    mosquitto_disconnect(mosq);
    mosquitto_destroy(mosq);

    mosquitto_lib_cleanup();
    return 0;
}
