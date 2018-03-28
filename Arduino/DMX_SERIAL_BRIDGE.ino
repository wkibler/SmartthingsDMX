#include <Conceptinetics.h>
#include <Rdm_Defines.h> // Can Probably remove this
#include <Rdm_Uid.h>     // Can Probably remove this
#include <SPI.h>   

#define DMX_SLAVE_CHANNELS      9 
#define RXEN_PIN                2

// Create DMX slave controller instance
DMX_Slave dmx_slave ( DMX_SLAVE_CHANNELS, RXEN_PIN );


// Variables 
int channelDMX;
int channelDMX1;
int channelDMX2;
int channelDMX3;
int channelDMX4;
int channelDMX5;
int channelDMX6;
int channelDMX7;
int channelDMX8;
int channelDMX9;
int i;

void setup() {
    Serial.begin(9600);
    dmx_slave.enable ();
    dmx_slave.setStartAddress (1);
    delay(100);
    dmx_slave.onReceiveComplete ( OnFrameReceiveComplete );
}

void loop() {
  Serial.print(channelDMX1);
  Serial.print(",");
  Serial.print(channelDMX2);
  Serial.print(",");
  Serial.print(channelDMX3);
  Serial.print(",");
  Serial.print(channelDMX4);
  Serial.print(",");
  Serial.print(channelDMX5);
  Serial.print(",");
  Serial.print(channelDMX6);
  Serial.print(",");
  Serial.print(channelDMX7);
  Serial.print(",");
  Serial.print(channelDMX8);
  Serial.print(",");
  Serial.println(channelDMX9);
}

void OnFrameReceiveComplete (unsigned short nrChannels) //When a complete DMX frame is received read one channel status at a time. 
{
    if (channelDMX=10){
      channelDMX=1;
      }
      
    if(channelDMX=1){
      channelDMX1=dmx_slave.getChannelValue(1);
      }
    if(channelDMX=2){
      channelDMX2=dmx_slave.getChannelValue(2);
      }
    if(channelDMX=3){
      channelDMX3=dmx_slave.getChannelValue(3);
      }
    if(channelDMX=4){
      channelDMX4=dmx_slave.getChannelValue(4);
      }
    if(channelDMX=5){
      channelDMX5=dmx_slave.getChannelValue(5);
      }
    if(channelDMX=6){
      channelDMX6=dmx_slave.getChannelValue(6);
      }
    if(channelDMX=7){
      channelDMX7=dmx_slave.getChannelValue(7);
      }
    if(channelDMX=8){
      channelDMX8=dmx_slave.getChannelValue(8);
      }
    if(channelDMX=9){
      channelDMX9=dmx_slave.getChannelValue(9);
      }
    channelDMX=(channelDMX+1);
    dmx_slave.getBuffer().clear();     
}


