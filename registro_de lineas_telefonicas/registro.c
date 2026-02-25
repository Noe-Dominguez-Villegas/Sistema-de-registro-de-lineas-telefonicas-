#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estructura de datos 
struct LineaTelefonica {
    int id;
    char curp[19];
    char nombre[100];
    char telefono[11]; 
    char operadora[20];
};

// Prototipos de Submódulos
void mostrarDatosEstudiante();
void registrarLinea(struct LineaTelefonica lista[], int *contador, int *sigID);
void buscarLinea(struct LineaTelefonica lista[], int contador);
void eliminarLinea(struct LineaTelefonica lista[], int *contador);

int main() {
    struct LineaTelefonica registros[100];
    int totalRegistros = 0;
    int siguienteID = 1;
    int opcion;

    
    mostrarDatosEstudiante();

 
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Lineas registradas (Nueva)\n");
        printf("2. Buscar linea\n");
        printf("3. Eliminar una linea\n");
        printf("4. Salir del sistema\n");
        printf("Seleccione una opcion (1-4): ");
        scanf("%d", &opcion);
        getchar(); 

        switch (opcion) {
            case 1: registrarLinea(registros, &totalRegistros, &siguienteID); break;
            case 2: buscarLinea(registros, totalRegistros); break;
            case 3: eliminarLinea(registros, &totalRegistros); break;
            case 4: printf("Saliendo del sistema...\n"); break;
            default: printf("Opcion no valida.\n");
        }
    } while (opcion != 4);

    return 0;
}

// Módulo Principal: 
void mostrarDatosEstudiante() {
    printf("===================================================\n");
    printf("SISTEMA DE REGISTRO DE LINEAS TELEFONICAS\n");
    printf("Nombre: Noe Dominguez Villegas\n");
    printf("Matricula: ES261112078\n");
    printf("Grupo: DS-DFPR-2601-B1-007\n");
    printf("===================================================\n");
}


void registrarLinea(struct LineaTelefonica lista[], int *contador, int *sigID) {
    if (*contador >= 100) {
        printf("Error: Memoria llena.\n");
        return;
    }
    struct LineaTelefonica nueva;
    nueva.id = *sigID;
    
    printf("\nID asignado: %d\n", nueva.id);
    printf("CURP (18 caracteres): ");
    scanf("%18s", nueva.curp);
    
    printf("Nombre completo: ");
    getchar(); 
    fgets(nueva.nombre, 100, stdin);
    nueva.nombre[strcspn(nueva.nombre, "\n")] = 0;

    // Validación de números para el teléfono
    do {
        printf("Numero de telefono (10 digitos): ");
        scanf("%10s", nueva.telefono);
        if(strlen(nueva.telefono) != 10) printf("Error: Debe ser de 10 digitos.\n");
    } while(strlen(nueva.telefono) != 10);

    printf("Seleccione operadora (1. Telcel, 2. AT&T, 3. Movistar): ");
    int op; scanf("%d", &op);
    strcpy(nueva.operadora, (op==1)?"Telcel":(op==2)?"AT&T":"Movistar");

    lista[*contador] = nueva;
    (*contador)++;
    (*sigID)++;
    printf("REGISTRO EXITOSO.\n");
}

// Submódulo: Búsqueda 
void buscarLinea(struct LineaTelefonica lista[], int contador) {
    char criterio[20];
    printf("Ingrese CURP a buscar: ");
    scanf("%s", criterio);
    for(int i=0; i<contador; i++) {
        if(strcmp(lista[i].curp, criterio) == 0) {
            printf("Linea encontrada: ID %d, Nombre: %s\n", lista[i].id, lista[i].nombre);
            return;
        }
    }
    printf("No se encontro el registro.\n");
}

// Submódulo: Eliminar 
void eliminarLinea(struct LineaTelefonica lista[], int *contador) {
    int idEliminar, encontrado = -1;
    printf("Ingrese ID a eliminar: ");
    scanf("%d", &idEliminar);
    for(int i=0; i < *contador; i++) {
        if(lista[i].id == idEliminar) { encontrado = i; break; }
    }
    if(encontrado != -1) {
        for(int i=encontrado; i < *contador - 1; i++) lista[i] = lista[i+1];
        (*contador)--;
        printf("ELIMINACION EXITOSA.\n");
    } else printf("ID no encontrado.\n");
}



