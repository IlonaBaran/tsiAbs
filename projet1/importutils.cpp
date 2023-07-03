#include "importutils.h"
#include <intrin.h>
#include <iostream>

// Include GLEW
#include <GL/glew.h>

#include <GLFW/glfw3.h>


void ImportOBJButtonCallback()
{
    std::cout << "Option sélectionnée : Importer un fichier OBJ" << std::endl;
    // Code pour gérer l'action "Importer un fichier OBJ"

    // Code pour gérer l'importation de couches OBJ ici
}

void menuCallback(int option)
{
    switch (option)
    {
        case 1:
            std::cout << "Option sélectionnée : Nouveau fichier" << std::endl;
            // Code pour gérer l'action "Nouveau fichier"
            break;
        case 2:
            std::cout << "Option sélectionnée : Enregistrer" << std::endl;
            // Code pour gérer l'action "Enregistrer"
            break;
        case 3:
            std::cout << "Option sélectionnée : Fermer" << std::endl;
            // Code pour gérer l'action "Fermer"
            break;
        case 4:
            ImportOBJButtonCallback();
            break;
        default:
            break;
    }
}

