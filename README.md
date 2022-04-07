## Description
---

        В образе используется модифицированный bash скрипт "extract-qt-installer" <https://github.com/benlau/qtci> для установки QT и его компонентов без использования дисплейного сервера
        Перед 'docker build' убедитесь, что с вашего IP адреса имеется доступ к серверам QT. 

## Usage
---
>$ `git clone --branch docker https://github.com/Mognoli/Proekt_mospolitech`

>$ `cd Proekt_mospolitech`

Введите логин и пароль вашего аккаунта QT в `/resources/auth`

>$ `docker build -t mosp-proj-app .`

>$ `docker run mosp-proj-app`

---
### Use image from DockerHub:

>$ `docker pull lixxteq/mosp-proj-app`

>$ `docker run mosp-proj-app`