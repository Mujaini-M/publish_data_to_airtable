/*
 * Project publish_data_to_airtable
 * Description: Publish data to airtable by triggering the wbhook by the event name air_table
 * Author: Majid Al Mujaini
 * Date: 1/13/2022
 */

#include "JsonParserGeneratorRK.h"
void publish_to_airtabl(float temp, float ec);

void setup() {
 
}

void loop() {
  delay(5000);
  publish_to_airtabl(25.6, 1.488);
  delay(10000);

}

void publish_to_airtabl(float temp, float ec)
{
  JsonWriterStatic<256> jw;
  
  {
   //insert key-value pairs for each reading
   JsonWriterAutoObject obj(&jw);
   jw.insertKeyValue("Temperature C", temp);
   jw.insertKeyValue("EC ms/cm", ec);
   
  }
  String json_form = jw.getBuffer();

  Particle.publish("air_table", "{\"records\": [{\"fields\":"+json_form+"}]}",PRIVATE); //trigger webhook
  
}