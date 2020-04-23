#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#define CV_ADC_MIDPOINT 511


// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=652.75,502.75
AudioSynthWaveform       waveform2;      //xy=654.75,583.75
AudioSynthWaveform       waveform4;      //xy=659.75,777.75
AudioSynthWaveform       waveform3;      //xy=667.75,668.75
AudioSynthWaveform       waveform5;      //xy=677.75,872.75
AudioSynthWaveform       waveform6;      //xy=684.75,969.75
AudioMixer4              mixer2;         //xy=946.75,799.75
AudioMixer4              mixer1;         //xy=1111.75,622.75
AudioOutputI2S           i2s3;           //xy=1379.083251953125,671.0833129882812
AudioConnection          patchCord1(waveform1, 0, mixer1, 0);
AudioConnection          patchCord2(waveform2, 0, mixer1, 1);
AudioConnection          patchCord3(waveform4, 0, mixer2, 0);
AudioConnection          patchCord4(waveform3, 0, mixer1, 2);
AudioConnection          patchCord5(waveform5, 0, mixer2, 1);
AudioConnection          patchCord6(waveform6, 0, mixer2, 2);
AudioConnection          patchCord7(mixer2, 0, mixer1, 3);
AudioConnection          patchCord8(mixer1, 0, i2s3, 0);
AudioControlSGTL5000     audioOut;
// GUItool: end automatically generated code

void setup()
{
   AudioMemory(10);
  audioOut.enable();
  audioOut.volume(1);
  audioOut.lineOutLevel(13);

  mixer1.gain(0,1);
  mixer1.gain(1,1);
  mixer1.gain(2,1);
  mixer1.gain(3,1);

  
  mixer2.gain(0,1);
  mixer2.gain(1,1);
  mixer2.gain(2,1);
  
  



  waveform1.pulseWidth(0.5);
  waveform1.begin(0.4, 794, WAVEFORM_PULSE);

  waveform2.pulseWidth(0.5);
  waveform2.begin(0.4, 647, WAVEFORM_PULSE);

  waveform3.pulseWidth(0.5);
  waveform3.begin(0.4, 524, WAVEFORM_PULSE);
  
  waveform4.pulseWidth(0.5);
  waveform4.begin(0.4, 444, WAVEFORM_PULSE);

  waveform5.pulseWidth(0.5);
  waveform5.begin(0.4, 368, WAVEFORM_PULSE);

  waveform6.pulseWidth(0.5);
  waveform6.begin(0.4, 283, WAVEFORM_PULSE);

  /* waveform1.phase(33); //Phase test no hace efecto interesante
  waveform2.phase(333);
  waveform3.phase(0);
  waveform4.phase(200);
  waveform5.phase(198);
  waveform6.phase(50); */


 
}

void loop(){

  // Read CV and knobs,sum them and scale to 0-1.0
  float knob_1 = min(1023, analogRead(A8) + (CV_ADC_MIDPOINT - analogRead(A10))) /1023.0;
  float knob_2 = min(1023, analogRead(A2) + (CV_ADC_MIDPOINT - analogRead(A11))) /1023.0;
  float knob_3 = min(1023, analogRead(A1) + (CV_ADC_MIDPOINT - analogRead(A12))) /1023.0;
  float knob_4 = min(1023, analogRead(A0) + (CV_ADC_MIDPOINT - analogRead(A13))) /1023.0;
  
  float multFactor=1180;
  
    waveform1.frequency(794+knob_1*multFactor);
    waveform2.frequency(647+knob_1*multFactor);
    waveform3.frequency(524+knob_1*multFactor);
    waveform4.frequency(444+knob_1*multFactor);
    waveform5.frequency(368+knob_1*multFactor);
    waveform6.frequency(283+knob_1*multFactor);

    waveform1.pulseWidth(knob_2);
    waveform2.pulseWidth(knob_2);
    waveform3.pulseWidth(knob_2);
    waveform4.pulseWidth(knob_2);
    waveform5.pulseWidth(knob_2);
    waveform6.pulseWidth(knob_2);




  
}
