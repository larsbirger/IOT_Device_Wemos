#include <Wire.h>
#include <BH1750.h>

const int sensor_address	= 0x23; //address

const int FREQ = 74880;


BH1750 lightMeter(sensor_address);

void setup()
{
    Serial.begin(FREQ);
    Wire.begin();
    lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE_2);
}

void loop()
{
    if (lightMeter.measurementReady())
    {
        uint16_t lux = lightMeter.readLightLevel();
        Serial.println(lux);
    }
}