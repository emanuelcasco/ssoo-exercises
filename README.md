README
# Docker SSOO

Docker implementation for SSOO TP.

Crear imagen:

> docker build . # Dirección del Dockerfile

Crear container:

> docker create --name cenv -it cenv:latest /bin/bash

Copiar mis archivos al container:

> docker cp ./ cenv:/workspace/

Iniciar instancia:

> docker start -i cenv