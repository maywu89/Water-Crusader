## Inspiration
Do you ever worry about what is in your water? While some of us live in the luxury of getting clean water for granted, some of us do not. For example, just recently in Flint, MI, another main water pipeline broke again. The whole city was under boil water advisory. So our question was "is there a way we can predict when pipelines break and inform the public in real time"?

## What it does
Water Crusader is an app that utilizes two main components to give citizens an informed assessment of their water quality. First, it takes available historical data of different pipelines and indicate possible pipelines with lead based on the year the pipe was built. Second, users each has a sensor system where they can upload water quality measurements to the app. By fusing critical information from these two components, we our users a risk measurement ranging between low, medium, and high for their water pipelines. From there, our user can use the information to take the next proper step. Over time, Water Crusader will become more accurate as the amount of crowd-sourcing data increases.

Furthermore, Water Crusader is applicable for users returning to rebuild their homes post-disaster. They can use Water Crusader to check their water source.

## How we built it
Hardware: 
To simulate the sensor system with the available hardware materials at HackMIT, we used a ESP32 and DHT11 Temperature and Humidity Sensor. The ESP32 takes temperature and humidity data read from DHT11. Data is received in Nose-RED json by specifying HTTP request and the sending actual post in the Arduino IDE.

Software:

## Challenges we ran into
1. We are limited by the amount of hardware available. We tried our best to create the best simulation of the sensor system as possible.

2. It was hard to find government information on pipelines, especially over weekends!

3. Not all of us are familiar with Node-RED js and there was a lot to learn! 

## Accomplishments that we're proud of
1.Learning new software!
2. Working in a super diverse team!!

## What's next for Water Crusader
We will continue to do research for different water sensors that can be added to our system. From our research, we learned that there is a lead sensor in development.
