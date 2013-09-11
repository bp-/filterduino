#include <Filter.h>

unsigned long tic, toc;
float data;

#define SAMPLING_FREQ 200 // Hertz

// IIR filter implemented in 3 cascaded sections
Filter S1;
Filter S2;
Filter S3;

void setup() {
  Serial.begin(115200);
  
  S1.a1 = -1.647038809863248909337585246248636394739;
  S1.a2 =  0.807378665954402663373912218958139419556;
  S1.G = 0.040084964022788403814612223641233867966;

  S2.a1 = -1.411568118505918345562122340197674930096;
  S2.a2 =   0.548984813017744488483629083930281922221;
  S2.G = 0.034354173627956487158119358582553104497;
  
   S3.a1 = -1.303939025082444080894106264167930930853;
  S3.a2 =   0.430877986314764704900426295353099703789;
  S3.G = 0.031734740308080121307110488260150304995 ;
  
  delay(1000);
}

void loop() {
  tic = micros();
  
  data = analogRead(A0);
  
  Serial.print(data); // raw dara
  Serial.print("\t");
  
  data = S3.update(S2.update(S1.update(data)));
  Serial.println(data); // filtered data
  
  toc = micros();
  
  delayMicroseconds(1000000/SAMPLING_FREQ - (toc-tic));
}


