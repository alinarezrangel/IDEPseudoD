#####################################
# Instalador de IDE PseudoD         #
# en GNU/Linux y POSIX-Like systems #
#####################################

# Por Alejandro Linarez Rangel.

echo "Bienvenido al instalador de la IDE oficial de      "
echo "PseudoD.                                           "
echo "Es requerido lo siguiente:                         "
echo " * Soporte de QT4 para C/C++                       "
echo " * Make y QMake instalados                         "
echo " * GCC 4.8>, G++ 4.8>                              "
echo " * PseudoD 2.0.0 o superior                        "
echo " * Estar como super-usuario                        "
echo "Como compilar:                                     "
echo "Si lo desea desde este instalador se puede compilar"
echo "la IDE, sin embargo fue diseñada con QTCreator y se"
echo "recomienda que para compilar el proyecto, solo abra"
echo "QTCreator, seleccione este proyecto y contruyalo.  "
echo "Desea continuar?(s/n):                             "
read resp

if [ "$resp" = "n" ]
    then
        echo "Abortado..."
        exit
fi

echo "Nota: si esta actualizando la IDE puede que vea    "
echo "mensajes de error de el comando mkdir, puede       "
echo "ignorarlos de forma segura                         "

echo "Creando las carpetas...                            "

mkdir /usr/share/idepseudod/
mkdir /usr/share/idepseudod/buffer/
mkdir /usr/share/idepseudod/bin/
mkdir /usr/share/idepseudod/tools/
mkdir /usr/share/idepseudod/Iconos/
cp ../Iconos/ /usr/share/idepseudod/Iconos/ -r
cp ./ /usr/share/idepseudod/tools/ -r
touch /usr/share/idepseudod/buffer/Input.txt
touch /usr/share/idepseudod/buffer/Output.txt

echo "Desea construir el proyecto desde aqui?(s/n)       "
read resp

if [ "$resp" = "n" ]
    then
        echo "Nota: la proxima vez que ejecute este      "
        echo "instalador, puede que vea mensajes de error"
        echo "de mkdir, puede ignorarlos.                "
        exit
fi

cd ../IDEPseudoD-build-desktop-Qt_4_8_2_in_PATH__System__Release/
make
cd ../tools/
cp ../IDEPseudoD-build-desktop-Qt_4_8_2_in_PATH__System__Release/IDEPseudoD /usr/share/idepseudod/bin/

echo "La IDE se encuentra en /usr/share/idepseudod/bin/  "

echo "Desea lanzar la IDE?(s/n)                          "
read resp

if [ "$resp" = "s" ]
    then
        /usr/share/idepseudod/bin/IDEPseudoD
fi

