# Pomodoro C 🍅

Pomodoro timer en C ejecutado desde la terminal.
Permite configurar duración de trabajo, descansos y ciclos, y avisa con un **beep** al finalizar cada timer.

## Características

- Ciclos de trabajo y descanso (work / short break / long break)
- Configurable vía argumentos de línea de comandos
- Beep confiable usando `sox` con fallback ASCII bell

## Requisitos

- GCC (compilador C)
- Linux / Unix-like system
- Opcional: `sox` para sonido mejorado (`sudo apt install sox`)

## Compilación
```bash
make
```

## Ejecución
Todos los valores en segundos

```bash
./pomodoro [WORK] [SHORT_BREAK] [LONG_BREAK] [CYCLES_BEFORE_LONG_BREAK]
```
Valores por defecto:
-   Work: 1500 (25 min)
-   Short break: 300 (5 min)
-   Long break: 900 (15 min)
-   Ciclos antes de descanso largo: 4

Ejemplo de prueba en corto tiempo entre ciclos:

```bash
./pomodoro 10 5 15 2
```