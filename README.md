# Pomodoro C 🍅

Pomodoro Timer para terminal, escrito en **C**, con interfaz **TUI usando ncurses**, soporte de colores, estados visuales, configuración persistente y estadísticas.

## Características

- Interfaz TUI con ncurses
- Estados visuales (WORK / BREAK / PAUSED)
- Historial persistente de sesiones
- Configuración guardada entre ejecuciones
- Notificaciones al finalizar cada timer
- Controles de teclado en tiempo real
- Exportación de estadísticas

## Requisitos

- GCC (compilador C)
- Linux / Unix-like system
- ncurses
- Opcional: `sox` para sonido mejorado

### Instalar dependencias

**Debian / Ubuntu**
```bash
sudo apt install gcc make libncurses-dev sox
```

**Arch**
```bash
sudo pacman -S gcc make ncurses sox
```

**macOS**
```bash
brew install ncurses
```

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

## Autor

Hecho con ❤️ en C.
Proyecto educativo de nivel intermedio–avanzado.