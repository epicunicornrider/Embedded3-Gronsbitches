#include "Client.h"

Thread Thread1; //thread

AnalogIn Sound(A0); //sound input

int32_t SoundA = 0; //store the sound

int Count = 0; //counts the loud noices

//sound thread
void Sound_thread()
{

    while (true) {

        float f = Sound.read(); //reads the sound
        for(int i=0; i<32; i++) {
            SoundA += Sound.read_u16();
        }

        SoundA >>= 5;

        if(SoundA > 50000) { //if the sound and light is above and below certain criteria then the alrm starts

            Count++; //counts 1 loud

            printf("*** ALARM ***"); //print alarm start to putty
        }
        wait_us(100000);
    }
}