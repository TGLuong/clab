#include <queue>
#include <mosquitto.h>
#include <unistd.h>
#include <string>
#include <iostream>

#ifndef MQTT_H
#define MQTT_H

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
static std::queue<int> message_queue;

class Mqtt {
    private:
        struct mosquitto *mosq;
        
        static void message_callback(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message) {
            if (message != NULL && message->topic != NULL) {
                pthread_mutex_lock(&mutex);
                message_queue.push(*((int *)(message->payload)));
                pthread_cond_signal(&cond);
                pthread_mutex_unlock(&mutex);
            }
        }
    
    public:
        Mqtt() {
        }
        int create_new() {
            mosq = mosquitto_new(NULL, true, NULL);
            mosquitto_message_callback_set(mosq, message_callback);
            if (mosq == NULL) {
                return -1;
            }
            return 0;
        }

        int connect(std::string host, int port) {
            if (mosq == NULL) return -1;
            return mosquitto_connect(mosq, host.data(), port, 60);
        }

        int disconnect() {
            if (mosq == NULL) return -1;
            return mosquitto_disconnect(mosq); 
        }

        int destroy() {
            if (mosq == NULL) return -1;
            mosquitto_destroy(mosq); 
            return 0;
        }
        
        int subscribe(std::string topic_filter) {
            if (mosq == NULL) return -1;
            return mosquitto_subscribe(mosq, NULL, topic_filter.data(), 0);
        }

        int publish(std::string topic, int temp) {
            if (mosq == NULL) return -1;
            return mosquitto_publish(mosq, NULL, topic.data(), sizeof(int), &temp, 0, false);
        }

        int listen() {
            if (mosq == NULL) return -1;
            mosquitto_loop_start(mosq);
            std::cout << "Press any key to quit" << std::endl;
            getchar();
            mosquitto_loop_stop(mosq, true);
            return 0;
        }

        int getMessage() {
            pthread_mutex_lock(&mutex);
            while (message_queue.size() == 0) {
                pthread_cond_wait(&cond, &mutex);
            }
            int temp = message_queue.front();
            message_queue.pop();
            pthread_mutex_unlock(&mutex);
            return temp;
        }
};
#endif
