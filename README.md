# Installation de l'environnement CLion et de la toolchain de compilation

## Installer CLion

- Télécharger le logiciel à partir du site de Jetbrains
- Vous pouvez faire activer une license étudiante à partir de votre addresse courriel universitaire
- Configurer les plugins

## Installer la toolchain arm-none-eabi

Pour pouvoir compiler et obtenir les bibliothèques de base, une toolchain de crosscompilation est nécessaire.

- Aller sur le site "https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads"
- Télécharger la version approprié selon votre OS
- Extraire l'archive
- Sous Linux: déplacer et renommer le dossier -> "/opt/arm-none-eabi"
- Sous Windows: déplacer et renommer dans un dossier de votre choix dont vous connaissez le chemin TODO: standardiser

## Installer stlink

Stlink est souvent disponible dans les distributions linux.

- Aller sur le site: "https://github.com/texane/stlink/releases/1.3.0"
- Installer le binaire
- Assurer vous d'ajouter le binaire à votre PATH

## Autres dépendances

Le projet compile à l'aide CMake.
Installer ces deux outils sur votre système.

## Importer le projet

Une configuration dans des paramètres de CLion est nécessaire, le projet est en erreur initialement, ce qui est normal.

- settings -> build -> cmake -> debug
- ajouter la definition suivante: "-DCMAKE_TOOLCHAIN_FILE=toolchain-arm-none-eabi.cmake"
- tools -> cmake -> reset cache
