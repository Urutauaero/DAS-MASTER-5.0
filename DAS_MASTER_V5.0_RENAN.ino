// Edição feita do DAS pelo Renan
/*
    SISTEMA DE AQUISIÇÃO DE DADOS - DAS 2019 - MASTER - ORIGINAL 2019
    URUTAU AERODESIGN - MANAUS, 02/06/2019

    WALDISMAR DE OLIVEIRA SAMPAIO FILHO
    JACOBUS LAURENS DE JAGER
*/

#define dasVersion "v3.0.0"
#define versionName "Versão alpha"

#define DEBUG

#pragma GCC optimize ("-Ofast")
#include <Wire.h>

#define baudrate 115200

// Declaração funções setup sensores
void MotionSystem_setup();
void heading_setup     ();
void hp_setup          ();
void telemetria_setup  ();
void vcas_setup        ();


float xv, yv, zv;
float heading;
float headingDegrees;

// Funções Globais
void get_data          ();
void serial_write      ();
void SD_write          ();

// ###########################################################################
// VARIÁVEIS GLOBAIS #########################################################
// ###########################################################################

String GyroX, GyroY, GyroZ;
String AccelX, AccelY, AccelZ;

String data_string, IDV_string;

int16_t gpsDay = 0, gpsMonth = 0, gpsYear = 0;
int16_t gpsHour = 0, gpsMinute = 0, gpsSecond = 0;

byte data_string_serial[45];

int rps;
int altint;
int wow, rpm;
int8_t control_1, control_2, control_3, control_4;
int sonarDistance;
int teste1, teste2;

float hp, pbmp, vcas, PVcas;
float longfloat, latfloat, altfloat;
float maghead;
float gForceX, gForceY, gForceZ;
float gyroXrate, gyroYrate, gyroZrate;

long   magheadint;
long   gyroXrateint;
long   gyroYrateint;
double gForceXint;
double gForceYint;
double gForceZint;

uint32_t latuint, longuint;

uint16_t servo1uint, servo2uint, servo3uint, servo4uint;

uint32_t tempo;
double temp;

int i = 0, j = 0;

//RTC ###################################################################################
#include <DS3231.h>            // Inicializando a bilbioteca do módulo RTC DS3231
DS3231 rtc(SDA, SCL);          // Comunição através da biblioteca wire.h e definir um 'nome' a esta biblioteca
Time t;

unsigned long h, m, s;         // Variáveis declaradas para o tempo horas, minutos e segundos
bool primeiro_ciclo = true;    // Pré-definição de uma repetição para o tempo

//Setup Sensores
void setup() {
  Serial.begin(baudrate);
  Wire.begin();

  Serial.println("\n\nBEGIN: rtc.begin --------------\n");
  rtc.begin();
  // Setagem dos parâmetros de dia,hora e data
//    rtc.setDOW(SUNDAY);     // Set Day-of-Week to SUNDAY
//    rtc.setTime(12, 6, 0);     // Set the time to 12:00:00 (24hr format)
//    rtc.setDate(18, 9, 2022);   // Set the date to January 1st, 2014

  Serial.println("\n\nCALLING: MotionSystem_setup --------------\n");
  MotionSystem_setup();

  Serial.println("\n\nCALLING: heading_setup --------------\n");
  heading_setup();

  Serial.println("\n\nCALLING: hp_setup --------------\n");
  hp_setup();

  Serial.println("\n\nCALLING: vcas_setup --------------\n");
  vcas_setup();


  Serial.println("\n\nSTATUS COMUNICAÇÃO I2C-------\n");
  status_check();

  Serial.println("\n\nCALLING: telemetria_setup --------------\n");
  telemetria_setup();

  temporizador_rtc ();
}

// Temporizador após Setup
void loop() {
  temporizador_apos_setup ();
}
