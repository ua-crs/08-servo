/*
 *     Project 08-servo - main.cpp
 *
 *         Muestra el funcionamiento de un servo
 *         Para ello, demuestra el posicionamiento continuo en pasos
 *         de 45 grados
 *
 *         Usar con shield IAE
 *         Nota importante: verificar antes de conectar el servo
 */

#include <Arduino.h>

#include <Servo.h>

/*
 *  Constantes definidas en platformio.ini
 *      MY_SERVO    IOPort donde data esta conectado
 *      SERIAL_BAUD Baud rate del port serie
 */

Servo servo; //    Construccion de un nuevo objeto tipo Servo

void
setup(void)
{
    Serial.begin(SERIAL_BAUD);
    servo.attach(MY_SERVO); //    Inicializacion declarando pin donde esta conectado
    Serial.printf("\n\r\n08-servo\n\r");
    delay(2000);
}

//    Tabla de posicionamiento

static const int grads[] = {0, 45, 90, 135, 180, 135, 90, 45, -1};

#if 1

void
loop(void)
{
    int i;

    for (i = 0; grads[i] >= 0; ++i)
    {
        Serial.printf("grads = %d\n\r", grads[i]);
        servo.write(grads[i]);
        delay(1000);
    }
}

#else

void
loop(void)
{
    const int *p;

    for (p = grads; *p >= 0; ++p)
    {
        Serial.printf("grads = %d\n\r", *p);
        servo.write(*p);
        delay(1000);
    }
}

#endif
