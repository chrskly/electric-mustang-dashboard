#pragma once
#include <WiFi.h>
extern WiFiServer server;

void handle_file_request(WiFiClient *client, String filePath);
void process_wifi_task(void *arg);
