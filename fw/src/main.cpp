/*
 * This file is part of the ev mustang dashboard project.
 *
 * Copyright (C) 2025 Christian Kelly <chrskly@chrskly.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <WiFi.h>
#include <LittleFS.h>
#include "freertos/FreeRTOS.h"

#include "wifiserver.h"


WiFiServer server(80);

TaskHandle_t Hello = NULL; // Task handle
TaskHandle_t wifiHandle = NULL;

// Task function Hello_Task
void Hello_Task(void *arg){
    while(1){
        printf("Task started!\n");
        printf("Hello, World!\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void setup() {
    Serial.begin(115200);
    Serial.println("Booting ...");
    const char* ssid = "mustang";
    const char* password = "password123";

    Serial.println("Starting LittleFS ...");
    if (!LittleFS.begin()) {
        Serial.println("LittleFS Mount Failed");
        return;
    }

    Serial.println("Starting WiFi ...");
    if (!WiFi.softAP(ssid, password)) {
        log_e("Soft AP creation failed.");
        while (1);
    }
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);
    server.begin();

    Serial.println("Starting server...");
    server.begin();

    //xTaskCreate(Hello_Task, "Hello, World!", 4096, NULL, 10, &Hello);
    xTaskCreate(process_wifi_task, "WiFi", 4096, NULL, 10, &wifiHandle);
    
}

void loop() {
    // nothing here
}