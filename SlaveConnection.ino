// LEGENGDA DE OPERADORES:
// |: Binary OR Operator copies a bit if it exists in either operand
// <<: Binary Left Shift Operator. The left operands value is moved left by the number of bits specified by the right operand.

//I2C ESCRAVOS

#define num_bytes 16
#define end_escravo 8

void medusa_loop()
{
  Wire.requestFrom(end_escravo, num_bytes);

  while (Wire.available())
  {

    /////////////////////////////////////////////////// LEITURA RPM ////////////////////////////////////////////////////////////////////////
    byte rpsint0 = Wire.read(); byte rpsint1 = Wire.read(); // 2 Bytes
    rps = rpsint0; rps = (rps << 8) | rpsint1;
    rpm = rps * 60;
    /////////////////////////////////////////////////// LEITURA TEMPO ////////////////////////////////////////////////////////////////////////
    byte tempo0 = Wire.read(); byte tempo1 = Wire.read(); byte tempo2 = Wire.read(); byte tempo3 = Wire.read();
    tempo = tempo0; tempo = (tempo << 8) | tempo1; tempo = (tempo << 8) | tempo2; tempo = (tempo << 8) | tempo3;

    /////////////////////////////////////////////////// LEITURA SONAR ////////////////////////////////////////////////////////////////////////
    wow = Wire.read();  sonarDistance = Wire.read();

    /////////////////////////////////////////////////// LEITURA DEFLEXÃO ////////////////////////////////////////////////////////////////////////
    control_1 = Wire.read();   control_2 = Wire.read();  control_3 = Wire.read(); control_4 = Wire.read();
    
    /////////////////////////////////////////////////// LEITURA GPS ////////////////////////////////////////////////////////////////////////
    byte latuint0 = Wire.read(); byte latuint1 = Wire.read(); byte latuint2 = Wire.read(); byte latuint3 = Wire.read();
    latuint = latuint0; latuint = (latuint << 8) | latuint1; latuint = (latuint << 8) | latuint2; latuint = (latuint << 8) | latuint3;

    int32_t latint = latuint;
    if (latint == -2147483647)
    {
      latint = 0;
    }

    latfloat = latint; latfloat /= 1000000;

    byte longuint0 = Wire.read(); byte longuint1 = Wire.read(); byte longuint2 = Wire.read(); byte longuint3 = Wire.read();
    longuint = longuint0; longuint = (longuint << 8) | longuint1; longuint = (longuint << 8) | longuint2; longuint = (longuint << 8) | longuint3;

    int32_t longint = longuint;
    if (longint == -2147483647)
    {
      longint = 0;
    }

    longfloat = longint; longfloat /= 1000000;

    byte altint0 = Wire.read(); byte altint1 = Wire.read();
    altint = altint0; altint = (altint << 8) | altint1;
    altfloat = altint; altfloat /= 100;
    

    /*
    byte gpsDay0 = Wire.read(); byte gpsDay1 = Wire.read();
    gpsDay = gpsDay0; gpsDay = (gpsDay << 8) | gpsDay1;

    byte gpsMonth0 = Wire.read(); byte gpsMonth1 = Wire.read();
    gpsMonth = gpsMonth0; gpsMonth = (gpsMonth << 8) | gpsMonth1;

    byte gpsYear0 = Wire.read(); byte gpsYear1 = Wire.read();
    gpsYear = gpsYear0; gpsYear = (gpsYear << 8) | gpsYear1;


    byte gpsHour0 = Wire.read(); byte gpsHour1 = Wire.read();
    gpsHour = gpsHour0; gpsHour = (gpsHour << 8) | gpsHour1;

    byte gpsMinute0 = Wire.read(); byte gpsMinute1 = Wire.read();
    gpsMinute = gpsMinute0; gpsMinute = (gpsMinute << 8) | gpsMinute1;

    byte gpsSecond0 = Wire.read(); byte gpsSecond1 = Wire.read();
    gpsSecond = gpsSecond0; gpsSecond = (gpsSecond << 8) | gpsSecond1;
    */
  }
}
