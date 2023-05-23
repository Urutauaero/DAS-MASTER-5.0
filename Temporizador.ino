// Inicio Temporizador
void temporizador_rtc() {
  if (primeiro_ciclo == true)
  {
    primeiro_ciclo = false;
    tempaux = millis() + 1000;

    while (aux < tempaux)
    {
      t = rtc.getTime();
      s = t.sec;

      if(s == saux)
      {
        if (millis() - aux >= 100 && cs < 9)
        {
          cs = cs + 1;
          aux = millis();
        }
      }
      else
      {
        cs = 0;
        aux = millis();
      }
      saux = t.sec;
    }
  }
}

// Temporizador após Setup
void temporizador_apos_setup () {

  t = rtc.getTime();
  s = t.sec;

  if (s == saux)
  {
    if(millis() - aux >= 100 && cs < 9)
    {
      cs++;
      aux = millis();

      get_data();
      serial_write();
      SD_write();
    }
  }
  else
  {
    cs = 0;
    aux = millis();
    get_data();
    serial_write();
    SD_write();
  }

  saux = t.sec;
}
