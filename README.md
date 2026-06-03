# makeduinoDCMotor

Llibreria senzilla per controlar dos motors DC amb la placa makeduino basada en Arduino UNO R4 Minima.

## Instal.lacio a Arduino IDE

1. Obre Arduino IDE.
2. Ves a `Sketch > Include Library > Add .ZIP Library...`.
3. Selecciona el fitxer `makeduinoDCMotor-1.2.0.zip`.
4. Tria la placa `Arduino UNO R4 Minima`.

## Motors

- `M1`: motor connectat als pins 10 i 12.
- `M2`: motor connectat als pins 11 i 13.

## Velocitat

La velocitat va de `-100` a `100`.

- `100`: maxima velocitat endavant.
- `50`: mitja velocitat endavant.
- `0`: motor aturat.
- `-50`: mitja velocitat enrere.
- `-100`: maxima velocitat enrere.

Si poses una velocitat fora d'aquest rang, la llibreria la limita automaticament.

## Funcions principals

| Funcio | Que fa |
| --- | --- |
| `motor.motorTurnOn("M1")` | Encen M1 al 100%. |
| `motor.motorTurnOn("M1", 50)` | Encen M1 al 50%. |
| `motor.motorTurnOn("M1", -50)` | Encen M1 al 50% enrere. |
| `motor.motorTurnOn("M1", 50, 2000)` | Encen M1 durant 2 segons i l'atura. |
| `motor.motorTurnOff("M1")` | Atura M1. |
| `motor.motorTurnOffAll()` | Atura tots els motors. |

## Exemples inclosos

- `motorBasic`: encendre, aturar i canviar el sentit d'un motor.
- `twoMotors`: controlar M1 i M2 en una sequencia.
- `speedRamp`: pujar i baixar la velocitat a poc a poc.
- `robotMovements`: moviments basics amb dos motors, com avancar i girar.

## Exemple rapid

```cpp
#include <makeduinoDCMotor.h>

makeduinoDCMotor motor;

void setup() {
  motor.motorTurnOn("M1", 50);
  delay(2000);
  motor.motorTurnOff("M1");
}

void loop() {
}
```

## Notes importants

- Connecta els motors a la placa abans de carregar programes que els activin.
- Comenca provant velocitats baixes, com `30` o `40`.
- La funcio amb temps, per exemple `motorTurnOn("M1", 50, 2000)`, usa `delay()`. Durant aquest temps el programa espera i no fa altres accions.
- Si un motor gira al reves del que esperaves, pots canviar el signe de la velocitat: `50` passa a `-50`.
