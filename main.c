#include <stdio.h>

void mostrarInventario(float cantidad1, float cantidad2, float cantidad3, float cantidad4, float cantidad5, float cantidad6, float cantidad7, float cantidad8, int productoPersonalizado, float cantidadPersonalizado, float precioPersonalizado);
void ingresarProducto(char producto, float *cantidades1, float *cantidades2, float *cantidades3, float *cantidades4, float *cantidades5, float *cantidades6, float *cantidades7, float *cantidades8);
void eliminarProducto(char nombreProducto, float *cantidades1, float *cantidades2, float *cantidades3, float *cantidades4, float *cantidades5, float *cantidades6, float *cantidades7, float *cantidades8);

int main(int argc, char *argv[]) {
    char opcion;

    float cantidad1 = 0, cantidad2 = 0, cantidad3 = 0, cantidad4 = 0, cantidad5 = 0, cantidad6 = 0, cantidad7 = 0, cantidad8 = 0;
    float precio1 = 150, precio2 = 55, precio3 = 180, precio4 = 70, precio5 = 120, precio6 = 150, precio7 = 55, precio8 = 180;

    do {
        printf("--------------MENU-------------\n");
        printf("a. Ver Inventario\n");
        printf("b. Ingreso de Producto\n");
        printf("c. Modificar Producto\n");
        printf("d. Eliminar Producto\n");
        printf("e. Salir\n");
        printf("--------------------------------\n");

        printf("Por favor seleccione una opcion:\n");
        scanf(" %c", &opcion);

        switch (opcion) {
            case 'a':
                mostrarInventario(cantidad1, cantidad2, cantidad3, cantidad4, cantidad5, cantidad6, cantidad7, cantidad8, 0, 0, 0);
                break;
            case 'b':
                printf("Opcion 'Ingreso de Producto' seleccionada.\n");
                char producto;
                printf("Ingrese el codigo del producto: ");
                scanf(" %c", &producto);
                ingresarProducto(producto, &cantidad1, &cantidad2, &cantidad3, &cantidad4, &cantidad5, &cantidad6, &cantidad7, &cantidad8);
                break;

            case 'c':
                printf("Opcion 'Modificar Producto' seleccionada.\n");
                printf("Ingrese el codigo del producto que desea modificar: ");
                scanf(" %c", &producto);
                ingresarProducto(producto, &cantidad1, &cantidad2, &cantidad3, &cantidad4, &cantidad5, &cantidad6, &cantidad7, &cantidad8);
                
                break;
            case 'd':
                printf("Opcion 'Eliminar Producto' seleccionada.\n");
                scanf(" %c", &producto);
                eliminarProducto(producto, &cantidad1, &cantidad2, &cantidad3, &cantidad4, &cantidad5, &cantidad6, &cantidad7, &cantidad8);
                break;
            case 'e':
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no válida. Intenta de nuevo.\n\n");
                break;
        }
    } while (opcion != 'e');

    return 0;
}


void mostrarInventario(float cantidad1, float cantidad2, float cantidad3, float cantidad4, float cantidad5, float cantidad6, float cantidad7, float cantidad8, int productoPersonalizado, float cantidadPersonalizado, float precioPersonalizado) {
    float precio1 = 0.50, precio2 = 0.55, precio3 = 0.60, precio4 = 0.20, precio5 = 1.20, precio6 = 0.40, precio7 = 55, precio8 = 0.65;

    printf("----------------INVENTARIO DE PRODUCTOS TALLER----------------------------------------\n");
    printf(" ID          NOMBRE               DESCRIPCION                 CANTIDAD          PRECIO   \n");
    printf("--------------------------------------------------------------------------------------\n");

    printf("1          papas                papas saborizadas a cebolla  (%.0f)          %.2f\n", cantidad1, precio1);
    printf("2          chicles gogo         chicles sabor a menta        (%.0f)          %.2f\n", cantidad2, precio2);
    printf("3          doritos              dortos saborizados a queso   (%.0f)          %.2f\n", cantidad3, precio3);
    printf("4          gomitas              gomitas sabor a frutas       (%.0f)          %.2f\n", cantidad4, precio4);
    printf("5          tampico              jugo sabor a naranja         (%.0f)          %.2f\n", cantidad5, precio5);
    printf("6          leche toni           leche saborizado a chocolate (%.0f)          %.2f\n", cantidad6, precio6);
    printf("7          pan                  a elecion del cliente        (%.0f)          %.2f\n", cantidad7, precio7);
    printf("8          agua tesalia         jugo para hidratacion        (%.0f)          %.2f\n", cantidad8, precio8);

    if (productoPersonalizado) {
        printf("9       Producto personalizado   Descripción del producto    (%.0f)          %.2f\n", cantidadPersonalizado, precioPersonalizado);
    }

    printf("--------------------------------------------------------------\n");
}

void ingresarProducto(char nombreProducto, float *cantidades1, float *cantidades2, float *cantidades3, float *cantidades4, float *cantidades5, float *cantidades6, float *cantidades7, float *cantidades8) {
    printf("Ingrese el ID del producto: ");
    char producto;
    scanf(" %c", &producto);
    
    char productos[8] = {'1', '2', '3', '4', '5', '6', '7', '8' };
    char nombres[8][20] = {"papas", "chicles gogo", "doritos", "gomitas", "tampico", "leche toni", "pan", "agua"};
    
    int productoEncontrado = 0;
    
    for (int i = 0; i < 8; i++) {
        if (producto == productos[i]) {
            productoEncontrado = i;
            
            printf("Producto encontrado: %s\n", nombres[i]);
            
            
            float cantidad;
            printf("Ingrese la cantidad que desea ingresar: ");
            scanf("%f", &cantidad);
            
           
            switch (producto) {
                case '1':
                    *cantidades1 += cantidad;
                    break;
                case '2':
                    *cantidades2 += cantidad;
                    break;
                case '3':
                    *cantidades3 += cantidad;
                    break;
                case '4':
                    *cantidades4 += cantidad;
                    break;
                case '5':
                    *cantidades5 += cantidad;
                    break;
                case '6':
                    *cantidades6 += cantidad;
                    break;
                case '7':
                    *cantidades7 += cantidad;
                    break;
                case '8':
                    *cantidades8 += cantidad;
                    break;
            }
            
           
            printf("Producto '%s' ingresado correctamente.\n", nombres[i]);
            
            return;  
        }
    }
    
    if (!productoEncontrado) {
        printf("Producto no encontrado. Ingresando producto personalizado: %c\n", producto);

        char nombrePersonalizado[20];
        printf("Ingrese el nombre del producto personalizado: ");
        scanf("%s", nombrePersonalizado);
        
        float cantidadPersonalizada;
        printf("Ingrese la cantidad del producto personalizado '%s': ", nombrePersonalizado);
        scanf("%f", &cantidadPersonalizada);

        float precioPersonalizado;
        printf("Ingrese el precio del producto personalizado '%s': ", nombrePersonalizado);
        scanf("%f", &precioPersonalizado);
        
        // Código para mostrar el inventario actualizado
        
        printf("Producto personalizado '%s' ingresado correctamente.\n", nombrePersonalizado);
    }
}
void eliminarProducto(char nombreProducto, float *cantidades1, float *cantidades2, float *cantidades3, float *cantidades4, float *cantidades5, float *cantidades6, float *cantidades7, float *cantidades8) {
    printf("Ingrese el ID del producto a eliminar: ");
    char producto;
    scanf(" %c", &producto);

    char productos[8] = {'1', '2', '3', '4', '5', '6', '7', '8' };
    char nombres[8][20] = {"papas", "chicles gogo", "doritos", "gomitas", "tampico", "leche toni", "pan", "agua"};

    int productoEncontrado = 0;

    for (int i = 0; i < 8; i++) {
        if (producto == productos[i]) {
            productoEncontrado = i;

            printf("Producto encontrado: %s\n", nombres[i]);

            
            float cantidad;
            printf("Ingrese la cantidad que desea eliminar: ");
            scanf("%f", &cantidad);

        
            switch (producto) {
                case '1':
                    if (*cantidades1 >= cantidad) {
                        *cantidades1 -= cantidad;
                        printf("Eliminación de producto exitosa.\n");
                    } else {
                        printf("No hay suficiente cantidad de producto en el inventario para eliminar.\n");
                    }
                    break;
                case '2':
                    if (*cantidades2 >= cantidad) {
                        *cantidades2 -= cantidad;
                        printf("Eliminación de producto exitosa.\n");
                    } else {
                        printf("No hay suficiente cantidad de producto en el inventario para eliminar.\n");
                    }
                    break;
                case '3':
                    if (*cantidades3 >= cantidad) {
                        *cantidades3 -= cantidad;
                        printf("Eliminación de producto exitosa.\n");
                    } else {
                        printf("No hay suficiente cantidad de producto en el inventario para eliminar.\n");
                    }
                    break;
                case '4':
                    if (*cantidades4 >= cantidad) {
                        *cantidades4 -= cantidad;
                        printf("Eliminación de producto exitosa.\n");
                    } else {
                        printf("No hay suficiente cantidad de producto en el inventario para eliminar.\n");
                    }
                    break;
                case '5':
                    if (*cantidades5 >= cantidad) {
                        *cantidades5 -= cantidad;
                        printf("Eliminación de producto exitosa.\n");
                    } else {
                        printf("No hay suficiente cantidad de producto en el inventario para eliminar.\n");
                    }
                    break;
                case '6':
                    if (*cantidades6 >= cantidad) {
                        *cantidades6 -= cantidad;
                        printf("Eliminación de producto exitosa.\n");
                    } else {
                        printf("No hay suficiente cantidad de producto en el inventario para eliminar.\n");
                    }
                    break;
                case '7':
                    if (*cantidades7 >= cantidad) {
                        *cantidades7 -= cantidad;
                        printf("Eliminación de producto exitosa.\n");
                    } else {
                        printf("No hay suficiente cantidad de producto en el inventario para eliminar.\n");
                    }
                    break;
                case '8':
                    if (*cantidades8 >= cantidad) {
                        *cantidades8 -= cantidad;
                        printf("Eliminación de producto exitosa.\n");
                    } else {
                        printf("No hay suficiente cantidad de producto en el inventario para eliminar.\n");
                    }
                    break;
            }

            break;
        }
    }

    if (!productoEncontrado) {
        printf("Producto no encontrado. Eliminación de producto fallida.\n");
    }
}