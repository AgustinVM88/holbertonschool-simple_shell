# Simple Shell

## Descripción
Este proyecto consiste en la implementación de un shell simple escrito en lenguaje C,
capaz de ejecutarse en modo interactivo y no interactivo, similar a `sh` o `bash`.  

El objetivo es entender el funcionamiento interno de un shell de Unix,
así como reforzar conceptos de procesos, llamadas al sistema y manejo de memoria.

---

## Características
- Ejecución en modo interactivo (esperando comandos del usuario).
- Ejecución en modo no interactivo (recibiendo comandos desde un archivo o pipe).
- Manejo de rutas usando la variable de entorno `PATH`.
- Ejecución de comandos con argumentos.
- Manejo de errores básico.
- Soporte para señales como `Ctrl+C` sin cerrar el shell.
- Cumplimiento de estilo **Betty** y sin fugas de memoria.

---

## Requisitos
- Sistema: Ubuntu 20.04 LTS
- Compilador: `gcc`
- Estilo: Betty

---

## Compilación
```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
