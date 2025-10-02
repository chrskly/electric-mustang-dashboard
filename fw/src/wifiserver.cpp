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
#include <string.h>
#include "freertos/FreeRTOS.h"

#include "wifiserver.h"

void handle_file_request(WiFiClient *client, String filePath) {
    client->println("HTTP/1.1 200 OK");
    if ( filePath.endsWith(".html") ) {
        client->println("Content-type:text/html");
    } else if ( filePath.endsWith(".css") ) {
        client->println("Content-type:text/css");
    } else if ( filePath.endsWith(".js") ) {
        client->println("Content-type:text/javascript");
    }
    client->println("Connection: close");
    client->println();
    uint8_t buf[128];
    File file = LittleFS.open(filePath, "r");
    if (file) {
        while (file.available()) {
            size_t len = file.read(buf, sizeof(buf));
            client->write(buf, len);
        }
        file.close();
    } else {
        client->println("HTTP/1.1 404 Not Found");
        client->println("Content-type:text/html");
        client->println();
        client->println("<h1>File Not Found</h1>");
    }
}

void process_wifi_task(void *arg) {

    while (1) {

        WiFiClient client = server.available();
        String header;
        unsigned long currentTime = millis();
        unsigned long previousTime = 0; 
        const long timeoutTime = 2000;

        if (client) {
            currentTime = millis();
            previousTime = currentTime;
            Serial.println("New Client.");
            String currentLine = "";
            while (client.connected() && currentTime - previousTime <= timeoutTime) {
                currentTime = millis();
                if (client.available()) {
                    char c = client.read();
                    Serial.write(c);
                    header += c;
                    if (c == '\n') {
                        if (currentLine.length() == 0) {
                            if (header.indexOf("GET /chart.min.js") >= 0) {
                                Serial.println("Req >>> chart.min.js");
                                handle_file_request(&client, "/chart.min.js");
                            } else if (header.indexOf("GET /chart.min.css") >= 0) {
                                Serial.println("Req >>> chart.min.css");
                                handle_file_request(&client, "/chart.min.css");
                            } else if (header.indexOf("GET /main.js") >= 0) {
                                handle_file_request(&client, "/main.js");
                            } else if (header.indexOf("GET /style.css") >= 0) {
                                handle_file_request(&client, "/style.css");
                            } else if (header.indexOf("GET /") >= 0) {
                                Serial.println("Req >>> index.html");
                                handle_file_request(&client, "/index.html");
                            }
                            // Break out of the while loop
                            break;
                        } else { // if you got a newline, then clear currentLine
                            currentLine = "";
                        }
                    } else if (c != '\r') {  // if you got anything else but a carriage return character,
                        currentLine += c;      // add it to the end of the currentLine
                    }
                }
            }
            // Clear the header variable
            header = "";
            // Close the connection
            client.stop();
            Serial.println("Client disconnected.");
            Serial.println("");
        }
    }
}